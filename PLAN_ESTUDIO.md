# Plan de estudio: examen del compilador C-TDS

Objetivo: (1) hacer a mano las 5 etapas de un programa nuevo y (2) extender el compilador en vivo.
Criterio Pareto: pocas reglas mecánicas explican casi todo lo que se pregunta.

```
.ctds -> analizadorLexico.l -> analizadorSintactico.y -> analizadorSemantico.c -> codigoIntermedio.c -> codigoObjeto.c -> .ass
           (tokens .lex)         (AST .sint, ast.c)        (tablaSimbolos.c)        (cuadruplas .ci)      (x86-64 AT&T)
```

## Cronograma (~8-10 h)

| Sesión | Tiempo | Contenido | Estado |
|---|---|---|---|
| 0. Entorno | 30 min | Instalar flex/bison y recompilar | HECHO |
| 1. Léxico + AST | 1.5 h | Secciones 1 y 2 de este archivo | HECHO |
| 2. Semántico + tabla de símbolos | 1 h | Sección 3 | HECHO (3 ejercicios resueltos y corregidos) |
| 3. Código intermedio | 2 h | Sección 4; 5 programas a mano vs `.ci` (ejercicios de la Sesión 3, al final) | HECHO (ci_01 a ci_04 corregidos; ci_05 salteado a propósito, repite lo anterior) |
| 4. Assembly | 2 h | Sección 5; 3 `.ci` a mano vs `.ass` | |
| 5. Extensiones en vivo | 2 h | Sección 6; cada receta 2 veces con cronómetro | |
| 6. Simulacro | 1 h | Programa nuevo, 5 etapas a mano, corrección | |

Comandos para comparar tu traza con el compilador (todos generan un archivo junto al `.ctds`):

```sh
./c-tds -target scan     prog.ctds   # prog.lex
./c-tds -target parse    prog.ctds   # prog.sint
./c-tds -target codinter prog.ctds   # prog.ci
./c-tds -target assembly prog.ctds   # prog.ass
```

Recompilar tras tocar `.l` o `.y`:

```sh
bison -d -v analizadorSintactico.y && flex analizadorLexico.l
gcc -o c-tds main.c ast.c optimizador.c tablaSimbolos.c analizadorSemantico.c codigoIntermedio.c codigoObjeto.c analizadorSintactico.tab.c lex.yy.c
```

---

## 1. Etapa léxica

**Qué hace:** lee el texto de izquierda a derecha y lo corta en tokens. Siempre toma el lexema **más largo** que coincida con alguna regla; si hay empate, gana la regla que aparece primero en el `.l` (por eso las palabras reservadas están antes que `ID`).

**Formato de salida:** una línea por token, `NOMBRE  texto` (dos espacios en medio). Los espacios y saltos de línea no generan nada.

### Procedimiento

1. Recorré el programa carácter a carácter y cortá en el lexema más largo posible.
2. Para cada lexema buscá su nombre en la tabla.
3. Escribí una línea por token, en el mismo orden del texto.

### Tabla de tokens

| Lexema | Token | | Lexema | Token |
|---|---|---|---|---|
| `int` | `INT` | | `+` | `OP_SUMA` |
| `float` | `FLOAT` | | `-` | `OP_RESTA` |
| `boolean` | `BOOLEAN` | | `*` | `OP_PROD` |
| `void` | `VOID` | | `/` | `OP_DIV` |
| `extern` | `EXTERN` | | `%` | `OP_DIVENT` |
| `if` | `IF` | | `<` | `OP_MENOR` |
| `else` | `ELSE` | | `>` | `OP_MAYOR` |
| `while` | `WHILE` | | `==` | `OP_EQ` |
| `return` | `RETURN` | | `&&` | `OP_AND` |
| `true`, `false` | `CTE_LOGICA` | | `\|\|` | `OP_OR` |
| `12` | `CTE_ENTERA` | | `!` | `OP_NEG` |
| `3.5` | `CTE_FLOAT` | | `=` | `OP_ASIG` |
| nombre | `ID` | | `;` `,` | `PUNTO_COMA` `COMA` |
| `(` `)` | `PAR_IZQ` `PAR_DER` | | `{` `}` | `LLAVE_IZQ` `LLAVE_DER` |

### Trampas (verificadas con el compilador)

- `<=`, `>=`, `!=` **no existen**. `a <= 2` da `OP_MENOR` y después `OP_ASIG`. `b != 1` da `OP_NEG` y después `OP_ASIG`.
- `-5` son **dos** tokens: `OP_RESTA` y `CTE_ENTERA 5`. El signo nunca forma parte del número.
- `3.5` es `CTE_FLOAT`; `3.` o `.5` no son float. Una constante float exige dígitos a ambos lados del punto.
- `true` y `false` son `CTE_LOGICA`, no `ID`.
- Un `ID` es letra seguida de letras, dígitos o `_`. No puede empezar con `_`.
- `// hola` genera **una** línea: `COMENTARIO_LINEA  // hola` (con todo el texto del comentario).
- `/* ... */` genera solo `COMENTARIO_ABRE  /*` y `COMENTARIO_CIERRA  */`. Lo de adentro no se lista.
- Un carácter desconocido (por ejemplo `@`) imprime un error léxico por stderr y no genera token.

### Ejemplo resuelto

Programa:

```c
int g;
extern void printInt(int x);
int suma(int a, int b) {
    int r;
    r = a + b * 2;
    return r;
}
```

Tokens (primeras líneas):

```
INT    int
ID  g
PUNTO_COMA  ;
EXTERN    extern
VOID    void
ID  printInt
PAR_IZQ  (
INT    int
ID  x
PAR_DER  )
PUNTO_COMA  ;
INT    int
ID  suma
PAR_IZQ  (
INT    int
ID  a
COMA  ,
INT    int
ID  b
PAR_DER  )
LLAVE_IZQ  {
...
ID  r
OP_ASIG  =
ID  a
OP_SUMA  +
ID  b
OP_PROD  *
CTE_ENTERA  2
PUNTO_COMA  ;
```

---

## 2. Etapa sintáctica (AST)

**Qué hace:** verifica que los tokens respeten la gramática y construye el árbol (`.sint`). La gramática (`analizadorSintactico.y`) tiene una acción por producción que llama a `crearNodo(TIPO, valor, hijo0, hijo1, hijo2, hijo3)`.

**Formato de salida:** un nodo por línea. Cada nivel de profundidad se indenta con **2 espacios**. Si el nodo tiene valor se imprime `NOMBRE : valor`; si no, solo `NOMBRE`. Los hijos se imprimen en orden `hijos[0]`, `hijos[1]`, `hijos[2]`, `hijos[3]`, saltando los que son NULL.

### Procedimiento (de arriba hacia abajo)

1. La raíz siempre es `DECLS` y adentro otro `DECLS` (el parser envuelve la lista una vez más).
2. Cada declaración global cuelga de un `DECLS` cuyo segundo hijo es el `DECLS` del resto de la lista. Es una lista **anidada hacia la derecha**: no hay hermanos, hay anidamiento.
3. Para cada declaración, aplicá la plantilla de la tabla siguiente.
4. Para cada expresión, construí el árbol respetando la precedencia (abajo). Los paréntesis no generan nodo.

### Plantillas de nodos

| Construcción | Árbol (hijos en orden) |
|---|---|
| `int g;` | `VAR` → `TYPE : int`, `IDS : g` |
| `int a, b;` | `VAR` → `TYPE : int`, `IDS : a` → hijo `IDS` (sin valor) → hijo `IDS : b` |
| `extern void f(int x);` | `EXTERN : f` → `PARAMS` → `PARAM : x` → `TYPE : int` (si devuelve tipo, el primer hijo es `TYPE`; si es `void`, no hay) |
| `int f(int a, int b) {...}` | `METHOD : f` → `TYPE : int`, `PARAMS`, `BLOQUE` |
| `void f() {...}` | `METHOD : f` → `BLOQUE` (sin `TYPE`, sin `PARAMS`) |
| parámetros `a, b` | `PARAMS` → `PARAM : a` (→ `TYPE`), `PARAMS` → `PARAMS` → `PARAM : b` (→ `TYPE`). **Hay un `PARAMS` extra** a partir del segundo parámetro |
| `{ vars; sentencias }` | `BLOQUE` → `VAR_DECL` (cadena de `VAR`), `STATEMENT` (cadena de sentencias). Si no hay variables, no aparece `VAR_DECL` |
| lista de variables | `VAR_DECL` → `VAR`, `VAR_DECL` → `VAR`, ... (anidado) |
| lista de sentencias | `STATEMENT` → sentencia, `STATEMENT` → sentencia, ... (anidado) |
| `x = e;` | `OP_ASIG : x` → expresión |
| `f(a, b);` (sentencia) | `METHOD_CALL` → `ARGUMENTS_CALL : f` → `ARG` → `EXPR` → e1, `ARGS` → `ARG` → `EXPR` → e2 |
| `f()` | `METHOD_CALL` → `NO_ARGUMENTS_CALL : f` |
| `if (c) {A}` | `IF` → c, `BLOQUE` |
| `if (c) {A} else {B}` | `IF` → c, `BLOQUE`, `ELSE` → `BLOQUE` |
| `while (c) {A}` | `WHILE` → c, `BLOQUE` |
| `return e;` | `RETURN` → `EXPR` → e |
| `return;` | `RETURN` (sin hijos) |
| `{ ... }` suelto | `BLOQUE` → `BLOQUE` (el de afuera es la sentencia, el de adentro el contenido) |
| `;` solo | no genera nodo |
| constante | `LITERAL : 3` (también `true`, `3.5`) |
| variable | `ID : x` |
| `a + b` | `SUMA` → a, b (igual con `RESTA`, `PROD`, `DIV`, `DIVENT`) |
| `a < b` `a > b` `a == b` | `MENOR` / `MAYOR` / `EQ` → a, b |
| `a && b` `a \|\| b` | `AND` / `OR` → a, b |
| `-a` | `SIGNO_MENOS` → a |
| `!a` | `NEG` → a |
| llamada en expresión | `METHOD_CALL` → `ARGUMENTS_CALL : f` ... |

Atención: una llamada como **sentencia** y una llamada dentro de una **expresión** producen ambas `METHOD_CALL`, pero la de sentencia queda dentro de `STATEMENT`.

### Precedencia (de menor a mayor) y asociatividad

| Nivel | Operadores | Asociatividad |
|---|---|---|
| 1 (más débil) | `\|\|` | izquierda |
| 2 | `&&` | izquierda |
| 3 | `<` `>` `==` | **no asociativos** (`a < b < c` es error sintáctico) |
| 4 | `+` `-` | izquierda |
| 5 | `*` `/` `%` | izquierda |
| 6 (más fuerte) | `!` y `-` unario | derecha |

Cómo armar el árbol de una expresión: el operador de **menor** precedencia queda en la raíz. Con igual precedencia y asociatividad izquierda, el **último** operador queda en la raíz (`a - b - c` es `RESTA(RESTA(a,b), c)`).

### Ejemplo resuelto

Programa:

```c
int g;
extern void printInt(int x);
int suma(int a, int b) {
    int r;
    r = a + b * 2;
    return r;
}
void main() {
    int x;
    x = suma(3, 4);
    if (x > 5 && g == 0) { g = x; }
    printInt(g);
}
```

Árbol (salida real del compilador):

```
DECLS
  DECLS
    VAR
      TYPE : int
      IDS : g
    DECLS
      EXTERN : printInt
        PARAMS
          PARAM : x
            TYPE : int
      DECLS
        METHOD : suma
          TYPE : int
          PARAMS
            PARAM : a
              TYPE : int
            PARAMS
              PARAMS
                PARAM : b
                  TYPE : int
          BLOQUE
            VAR_DECL
              VAR
                TYPE : int
                IDS : r
            STATEMENT
              OP_ASIG : r
                SUMA
                  ID : a
                  PROD
                    ID : b
                    LITERAL : 2
              STATEMENT
                RETURN
                  EXPR
                    ID : r
        DECLS
          METHOD : main
            BLOQUE
              VAR_DECL
                VAR
                  TYPE : int
                  IDS : x
              STATEMENT
                OP_ASIG : x
                  METHOD_CALL
                    ARGUMENTS_CALL : suma
                      ARG
                        EXPR
                          LITERAL : 3
                        ARGS
                          ARG
                            EXPR
                              LITERAL : 4
                STATEMENT
                  IF
                    AND
                      MAYOR
                        ID : x
                        LITERAL : 5
                      EQ
                        ID : g
                        LITERAL : 0
                    BLOQUE
                      STATEMENT
                        OP_ASIG : g
                          ID : x
                  STATEMENT
                    METHOD_CALL
                      ARGUMENTS_CALL : printInt
                        ARG
                          EXPR
                            ID : g
```

Cómo leerlo: cada `STATEMENT` tiene la sentencia como primer hijo y **el resto de las sentencias como segundo hijo**, por eso el segundo `STATEMENT` queda indentado un nivel más que el primero. Lo mismo vale para `DECLS`.

### Errores típicos al hacerlo a mano

- Olvidar el `DECLS` extra de la raíz.
- Poner `PARAMS` hermanos en vez de anidados (y olvidar el `PARAMS` extra).
- Poner las sentencias como hermanas en vez de anidar cada `STATEMENT` dentro del anterior.
- Poner `TYPE` en un método `void`, o `VAR_DECL` en un bloque sin variables.
- Dibujar paréntesis como nodos.
- Olvidar el `EXPR` que envuelve cada argumento y cada `return`.

---

## 3. Etapa semántica

**Qué hace:** recorre el AST y verifica lo que la gramática no puede expresar: que todo nombre esté declarado, que los tipos cierren y que las llamadas sean válidas. De paso **decora el AST**: engancha en cada nodo que declara o usa un nombre el puntero a su símbolo en la tabla. Si encuentra errores, los imprime por `stderr` y **no se genera código intermedio**. Si el parser ya falló, el semántico ni arranca.

### 3.1 La tabla de símbolos

Es una **pila de niveles**. Cada nivel es una lista de símbolos. Se busca siempre de adentro hacia afuera (del nivel más profundo al global).

| Nivel | Qué contiene | Cuándo se abre / cierra |
|---|---|---|
| 0 (global) | variables globales, **todas** las funciones (incluidas `extern` y `main`) | al empezar / al terminar el análisis |
| 1 | los **parámetros** y las variables declaradas al principio del cuerpo de **una** función | al empezar cada función / al terminar |
| 2, 3, ... | variables declaradas en un `{}` interno: cuerpo de `if`, de `else`, de `while`, o bloque suelto | al entrar al `{}` / al salir |

Puntos clave:
- Los parámetros y las variables del primer nivel de la función **comparten el mismo nivel**. Por eso `int f(int a) { int a; }` es un error de redeclaración.
- Un `{}` interno **sí puede** declarar un nombre que ya existe en un nivel de afuera (lo tapa, no es error). Solo es error repetirlo **en el mismo nivel**.
- Al cerrar un nivel, sus símbolos dejan de ser visibles. Por eso una variable de un `while` no existe después del `while`.
- Cada función arranca con su propio nivel 1: los parámetros de una función no se ven en otra.

**Qué guarda cada símbolo** (campos que importan en el examen):

| Campo | Valor |
|---|---|
| nombre | el identificador |
| flag | `VARIABLE`, `PARAMETRO` o `FUNCION` |
| tipo | `int`, `float`, `boolean`, `void`. En una función es el tipo de retorno |
| esGlobal | 1 si se declaró en el nivel 0 |
| numParams y tipos | solo funciones: cantidad y tipo de cada parámetro formal, en orden |
| esExterna | solo funciones: 1 si se declaró con `extern` |
| inicializado | 1 al asignarle (los parámetros nacen con 1). **No se usa para dar errores**: usar una variable sin asignar no es error |
| offset | **todavía 0** en esta etapa (se asigna en assembly) |

### 3.2 Las dos pasadas

**Pasada 1: declaraciones globales**, en el orden del texto, solo del nivel 0:
1. Cada variable global se inserta (`VARIABLE`, tipo, `esGlobal`).
2. Cada método y cada `extern` se inserta como `FUNCION` con su tipo de retorno, su cantidad de parámetros y los tipos de cada uno. **Sus parámetros todavía no se insertan.**
3. Un nombre repetido en el nivel 0 (variable con variable, función con función **o variable con función**) da `Identificador redeclarado!!!`.
4. Al terminar la pasada se comprueba que exista `main`. Solo se exige el nombre: no se mira su tipo ni sus parámetros.

Consecuencia: como todo lo global se registra **antes** de mirar los cuerpos, una función puede llamar a otra o usar una global que aparece **más abajo** en el texto.

**Pasada 2: cuerpos de los métodos**, en el orden del texto. Para cada método con cuerpo (los `extern` no tienen):
1. Abrir nivel 1.
2. Insertar los parámetros (`PARAMETRO`, tipo, `inicializado = 1`), en orden.
3. Insertar las variables declaradas al principio del cuerpo, en orden.
4. Recorrer las sentencias en orden, verificando cada una (ver 3.3). Cada `{}` interno abre un nivel nuevo, procesa sus declaraciones y sentencias, y lo cierra.
5. Cerrar el nivel 1.

### 3.3 Qué se verifica en cada construcción

| Construcción | Regla | Error si falla |
|---|---|---|
| `x = e;` | `x` declarada, no es función, y su tipo es **idéntico** al de `e` | `asignación a 'x', que no está declarado` / `no se puede asignar a la función 'x'` / `asignación de tipos incompatibles` |
| uso de `x` en una expresión | `x` declarada; el tipo de la expresión es el de `x` | `'x' no está declarado` |
| `a + b`, `-`, `*`, `/`, `%` | ambos operandos `int` o `float`. Resultado `float` si alguno lo es, si no `int` | `operandos no numéricos en una operación aritmética` |
| `a < b`, `a > b` | ambos numéricos. Resultado `boolean` | `operandos incompatibles en una comparación` |
| `a == b` | ambos numéricos, **o** ambos del mismo tipo (por ejemplo dos `boolean`). Resultado `boolean` | `operandos incompatibles en una comparación` |
| `a && b`, `a \|\| b` | ambos `boolean`. Resultado `boolean` | `los operandos de && y || deben ser booleanos` |
| `-a` | `a` numérico | `el signo menos exige un operando numérico` |
| `!a` | `a` `boolean` | `la negación exige un operando booleano` |
| `if (c)` / `while (c)` | `c` es `boolean` | `la condición del if debe ser booleana` / `la condición del while debe ser booleana` |
| `return e;` | si la función no es `void`, el tipo de `e` coincide con el de la función | `el tipo retornado no coincide con el del método` |
| `return;` | la función es `void` | `el método debe retornar un valor` |
| `return e;` en `void` | no se permite | `un método void no puede retornar un valor` |
| `f(a1, ..., an)` | `f` declarada y es función; cantidad igual a `numParams`; el tipo de cada argumento **idéntico** al del parámetro | `llamada a 'f', que no está declarada` / `'f' no es una función` / `'f' espera N argumento(s) pero recibió M` / `el argumento K de 'f' tiene un tipo incompatible` |
| llamada usada como valor | el resultado tiene el tipo de retorno de `f` | (una función `void` usada en una expresión produce un error de tipos) |
| literal | `true`/`false` son `boolean`; con `.` es `float`; el resto `int` | |

### 3.4 Reglas de tipos que confunden

- **No hay conversión implícita.** `float f; f = 3;` es error (`int` a `float`). `int` pasado a un parámetro `float` también. `3 + 2.5` sí es válido y da `float`.
- `boolean` **no** es numérico: `p + 1`, `p < q` y `x = p` con `x` entero son errores.
- Las condiciones deben ser `boolean`: `if (x)` con `x` entero es error.
- `==` acepta `boolean == boolean`; `<` y `>` no.
- Una función `void` se puede llamar como sentencia, pero no usarla como valor.

### 3.5 Cómo se informan los errores

- Se imprimen por `stderr`, **uno por línea, sin número de línea**, en el orden en que se detectan: primero los de la pasada 1 (declaraciones globales) y después los de la pasada 2 (cuerpos, en orden de aparición).
- El mensaje de redeclaración es siempre `Identificador redeclarado!!!`, **sin** el nombre.
- Una expresión con error toma tipo "indefinido" y **no genera errores en cascada** por encima de ella. Ejemplo: en `x = h(2);` con `h` sin declarar, solo sale `llamada a 'h', que no está declarada`; no se agrega un error de asignación.
- Se siguen analizando las demás sentencias para informar **todos** los errores, no solo el primero.
- Con errores semánticos, el compilador termina con código 1 y no produce `.ci`.

### 3.6 Lo que NO se verifica (no lo inventes en el examen)

- Que una función no `void` retorne en todos los caminos (`int f() { }` es válido).
- Que se use una variable antes de asignarla.
- Código inalcanzable, o variables sin usar.
- El tipo y los parámetros de `main`.
- Una función `extern` nunca se verifica por dentro: no tiene cuerpo.

### 3.7 Decoración del AST

Se engancha el símbolo en estos nodos: `METHOD` y `EXTERN` (su función), `PARAM`, `IDS` (cada variable declarada), `OP_ASIG` (el destino), `ID` (cada uso) y `ARGUMENTS_CALL` / `NO_ARGUMENTS_CALL` (la función llamada). El árbol impreso **no cambia**: la decoración no se ve en el `.sint`.

### 3.8 Cómo explicarlo en el examen (con palabras)

Se explica en un párrafo, siguiendo siempre el mismo orden: **qué verifica, pasada 1, pasada 2 (cuerpo por cuerpo, sentencia por sentencia), decoración y errores.** Estructura fija de cada sentencia: se busca el nombre (de adentro hacia afuera), se calcula el tipo de abajo hacia arriba y se compara con lo que el contexto exige.

### 3.9 Ejemplo resuelto sin errores

Programa:

```c
int g;
int doble(int v) { return v * 2; }
void main() {
    int i;
    i = 0;
    while (i < 3) { i = i + 1; }
    g = doble(i);
}
```

> El análisis semántico recibe el AST que construyó el parser y verifica lo que la gramática no puede expresar: que todo identificador esté declarado antes de usarse, que los tipos sean compatibles con el contexto y que las llamadas respeten la firma de la función. Usa una **tabla de símbolos organizada como una pila de niveles** y recorre el árbol en **dos pasadas**.
>
> En la **primera pasada** se abre el nivel 0 (global) y se recorre solo la lista de declaraciones de más arriba. Se insertan `g` (variable, `int`), `doble` (función que devuelve `int` y recibe un `int`) y `main` (función `void` sin parámetros), y se comprueba que exista `main`. Los parámetros todavía no se insertan. Como todo lo global queda registrado antes de mirar ningún cuerpo, una función puede usar otra declarada más abajo en el texto.
>
> En la **segunda pasada** se visita el cuerpo de cada método. Para `doble` se abre el nivel 1, se inserta el parámetro `v` (`int`) y se analiza `return v * 2`. `v` se busca desde el nivel más interno hacia afuera y se resuelve en el nivel 1 con tipo `int`. El literal `2` es `int`. El tipo del producto se calcula de abajo hacia arriba: dos operandos `int` dan `int`. Ese tipo se compara con el tipo de retorno de la función, `int`, y coincide. Se cierra el nivel 1 y `v` deja de ser visible.
>
> Para `main` se abre otro nivel 1 y se inserta `i` (`int`). En `i = 0` el destino debe estar declarado y no ser una función, y su tipo debe ser idéntico al de la expresión (`int` con `int`: correcto). En el `while`, la condición `i < 3` se evalúa **antes** de abrir el nivel del cuerpo: ambos operandos son numéricos, el resultado es `boolean`, que es lo que exige un `while`. Luego se abre el nivel 2 para el cuerpo, se verifica `i = i + 1` (`i` se encuentra en el nivel 1, la suma da `int`, la asignación es válida) y se cierra el nivel 2. Por último, en `g = doble(i)` se busca `doble` y se comprueba que sea una función, que reciba un argumento (cantidad correcta) y que el tipo de `i` (`int`) coincida con el del parámetro formal. El tipo de la llamada es el tipo de retorno de la función, `int`, que coincide con el de `g`. Se cierra el nivel 1 y el nivel 0.
>
> Además de verificar, el análisis **decora el AST**: enlaza cada nodo que declara o usa un nombre con su símbolo en la tabla, información que luego usa el generador de código intermedio. Si hay errores, se informan todos por `stderr`, sin número de línea y en el orden en que se detectan; una expresión con error recibe tipo indefinido para no generar errores en cascada, y no se genera código. En este programa no hay errores.

La pila de la tabla en cuatro momentos (el nivel más interno va arriba):

```
(a) fin pasada 1     (b) dentro de doble    (c) dentro del while    (d) al terminar
                                            ┌───────────────┐
                                            │ 2: (vacío)    │
                     ┌─────────────┐        ├───────────────┤
┌───────────────┐    │ 1: v        │        │ 1: i          │       (pila vacía)
│ 0: g, doble,  │    ├─────────────┤        ├───────────────┤
│    main       │    │ 0: g, doble,│        │ 0: g, doble,  │
└───────────────┘    │    main     │        │    main       │
                     └─────────────┘        └───────────────┘
```

### 3.10 Ejemplo resuelto con errores

Programa:

```c
int g;
void main() {
    int x;
    boolean g;
    x = calc(1, 2);
    if (pos(x)) {
        int x;
        x = true;
        g = calc(x);
    }
    while (g) {
        int h;
        h = x + 1.5;
    }
    g = pos(g);
}
int calc(int a, int b) {
    int a;
    int c;
    c = a + b;
    return c;
}
boolean pos(int n) { return n > 0; }
```

> En la pasada 1 se inserta en el nivel 0 `g` (variable `int`), `main` (función `void` sin parámetros), `calc` (función `int` con dos parámetros `int`) y `pos` (función `boolean` con un parámetro `int`), y se comprueba que exista `main`. En la pasada 2, en `main`, se abre el nivel 1 con `x` (`int`) y `g` (`boolean`); este `g` tapa al global. `x = calc(1, 2)` es correcta: `calc` ya estaba registrada aunque se defina más abajo, y la cantidad y los tipos de los argumentos coinciden. La condición del `if` es una llamada que devuelve `boolean`: válida. Se abre el nivel 2 con otra `x` (`int`) que tapa a la anterior: `x = true` falla porque asigna `boolean` a `int`. En `g = calc(x)` falla la cantidad (espera 2, recibe 1), pero el tipo de la llamada sigue siendo `int`, el de retorno; como `g` se resuelve en el nivel 1 como `boolean`, la asignación falla también. Se cierra el nivel 2. La condición del `while` es `g`, `boolean`: correcta, y su cuerpo abre otro nivel 2 con `h`: `x + 1.5` es `float` (`x` se resuelve en el nivel 1) y asignarlo a `h`, `int`, falla porque no hay conversión implícita. En `g = pos(g)` el argumento es `boolean` y se esperaba `int`: falla, pero el tipo de la llamada sigue siendo `boolean`, así que la asignación es correcta. Al cerrar `main` se abre un nivel 1 para `calc` con `a` y `b`; la variable `int a` repite el nombre del parámetro en el mismo nivel y se informa como redeclaración, sin insertarse. Luego `c` y el `return c` están bien. Por último `pos`: `n > 0` es `boolean`, igual al retorno. Como hubo errores, se informan todos y no se genera código intermedio.

Errores, en el orden exacto en que se informan:

```
Error semántico: asignación de tipos incompatibles                    (x = true)
Error semántico: 'calc' espera 2 argumento(s) pero recibió 1          (calc(x))
Error semántico: asignación de tipos incompatibles                    (g = calc(x))
Error semántico: asignación de tipos incompatibles                    (h = x + 1.5)
Error semántico: el argumento 1 de 'pos' tiene un tipo incompatible   (pos(g))
Identificador redeclarado!!!                                          (int a; en calc)
```

La redeclaración sale **última** aunque sea un error de declaración: ocurre en la pasada 2 y el cuerpo de `calc` aparece después del de `main`. Una redeclaración *global* saldría primera, porque es de la pasada 1.

Punto más profundo de `main` (cuerpo del `if`):

```
nivel 2: x (VARIABLE, int)
nivel 1: x (VARIABLE, int), g (VARIABLE, boolean)
nivel 0: g (VARIABLE, int), main (FUNCION, void, []),
         calc (FUNCION, int, [int,int]), pos (FUNCION, boolean, [int])
```

**Regla para recordar:** si el tipo de una expresión es *indefinido* (nombre no declarado, o llamada a algo que no es función), el padre no suma errores. En cualquier otro caso, incluso con error de argumento o de cantidad, el tipo de la llamada es el de retorno y el padre se verifica con normalidad.

### 3.11 Errores típicos al hacerlo a mano

- Insertar los parámetros de una función en el nivel 0 en vez de abrirles un nivel 1.
- Abrir un nivel extra para el cuerpo de la función, separado del de los parámetros.
- Olvidar que `main` y las demás funciones se insertan en la **pasada 1**, antes de visitar ningún cuerpo.
- Aceptar `float f; f = 3;` o `if (x)` con `x` entero: ambos son errores.
- Dar un error por usar una variable sin inicializar (el compilador no lo detecta).
- Poner el nombre en el mensaje de redeclaración.
- Marcar como `PARAMETRO` una variable declarada en el cuerpo (`int i;`). Es `VARIABLE`.
- Decir que `a > b` o `a == b` dan `int`: dan `boolean`.
- Deducir el tipo de una expresión por el contexto en que se usa. Sale de **abajo hacia arriba**: `s / 2` con `s` entero es `int`, aunque se devuelva en una función `float`.
- Dar tipo indefinido a una llamada solo porque un argumento falló. Solo es indefinida si la función no existe o no es función.
- Informar el error de cantidad de argumentos **antes** que los de tipo de cada argumento: en una llamada, primero se verifican los argumentos uno por uno y **después** la cantidad.
- Olvidar que un error **no** siempre arrastra a su padre: un argumento o una cantidad incorrectos no cambian el tipo de la llamada (sigue siendo el de retorno), así que la asignación que la contiene se verifica con normalidad.

---

## 4. Código intermedio

**Qué hace:** recorre el AST decorado y produce una lista de **cuádruplas** (`op, arg1, arg2, res`), que se imprimen como código de tres direcciones. Solo corre si no hubo errores semánticos. Sin `-opt` no hay ninguna optimización: `1 + 2` genera `t = 1 + 2`.

**Formato de salida:** una instrucción por línea, sin sangría. Las etiquetas terminan en `:`.

| Instrucción | Se imprime |
|---|---|
| aritmética (`+ - * / %`) y relacional (`< > ==`) | `t3 = a + t2` |
| signo menos / negación lógica | `t2 = -a` / `t2 = !a` |
| copia | `x = t3` |
| etiqueta | `L1:` |
| salto incondicional / condicional | `goto L2` / `ifFalse t1 goto L2` |
| entrada y salida de función | `enter f` / `leave` |
| argumento y llamada | `param x` / `t4 = call f, 2` (sin `t4 =` si `f` es `void`) |
| retorno | `return t3` / `return` |

### 4.1 El único concepto difícil: **cuándo se pide cada número**

Los contadores de temporales (`t`) y de etiquetas (`L`) arrancan en 1, son **globales al programa** y no se reinician por función. Casi todos los errores a mano son de numeración. La regla es: **el número se pide en el momento en que el generador lo necesita**, y eso cambia según la construcción:

| Construcción | Orden exacto |
|---|---|
| `a op b` | 1) generar `a`, 2) generar `b`, 3) pedir `t` del resultado, 4) emitir `t = a op b` |
| `-a`, `!a` | 1) generar `a`, 2) pedir `t`, 3) emitir |
| `x = e` | 1) generar `e`, 2) emitir `x = <operando de e>` (siempre copia) |
| `a && b` | 1) pedir `t` resultado, 2) pedir etiqueta `fin`, 3) generar `a`, 4) `t = a`, 5) `ifFalse t goto fin`, 6) generar `b`, 7) `t = b`, 8) `fin:` |
| `a \|\| b` | igual que `&&`, pero entre 4) y 5) se pide **otro** `t'` y se emite `t' = !t`; el salto es `ifFalse t' goto fin` |
| `if (c) A` | 1) generar `c`, 2) pedir `fin`, 3) `ifFalse c goto fin`, 4) `A`, 5) `fin:` |
| `if (c) A else B` | 1) generar `c`, 2) pedir `laOtra`, 3) pedir `fin`, 4) `ifFalse c goto laOtra`, 5) `A`, 6) `goto fin`, 7) `laOtra:`, 8) `B`, 9) `fin:` |
| `while (c) A` | 1) pedir `inicio`, 2) pedir `fin`, 3) `inicio:`, 4) generar `c`, 5) `ifFalse c goto fin`, 6) `A`, 7) `goto inicio`, 8) `fin:` |
| `f(a1, ..., an)` | 1) generar **todos** los argumentos en orden, 2) emitir un `param` por cada uno, 3) pedir `t` (salvo que `f` sea `void`), 4) `t = call f, n` |
| `return e` / `return` | generar `e`, luego `return <operando>` / `return` |
| método | `enter f`, el cuerpo, `return` implícito si es `void` y la última instrucción no es un `return`, y siempre `leave` |

Qué consecuencia tiene cada fila:

- En una operación binaria, los temporales de los operandos son **menores** que el del resultado.
- En `&&` y `||`, el temporal del resultado y la etiqueta son **menores** que los de los operandos. Si hay un `&&` dentro de un `||`, el externo pide primero su `t` y su `L`, y recién después el interno pide los suyos.
- En `if` y `while` la condición se genera con los números que ya estén en juego, y **después** se piden las etiquetas del `if` (pero **antes** en el `while`).

### 4.2 Procedimiento a mano

1. Una pasada por las funciones, en el orden del texto. Las variables globales y los `extern` no generan nada.
2. Dentro de cada función: `enter`, las sentencias con las plantillas de arriba, y el cierre (`return` implícito si corresponde y `leave`).
3. Escribí al costado el próximo `t` y el próximo `L` libres. Es lo único que se arrastra entre sentencias y entre funciones.
4. En cada expresión, trabajá **de adentro hacia afuera** y de izquierda a derecha.

### 4.3 Trampas (verificadas con el compilador)

- **Las hojas no generan nada.** Variables y constantes se usan directo como operando. `x = y;` da `x = y`. `true` y `false` se imprimen como `1` y `0`. Una constante float se trunca a entero (limitación del IR).
- **Sin optimizaciones no hay plegado.** `(1 + 2) * x` da `t1 = 1 + 2` y `t2 = t1 * x`.
- **Los paréntesis no existen en el IR**: solo cambian el orden en que se genera.
- **Una llamada como sentencia a una función no `void` igual consume un temporal**: `k(2);` da `t1 = call k, 1`, y ese `t1` nunca se usa.
- **Una variable dentro de `&&` o `||` se copia al temporal**: `p || a == b` empieza con `t4 = p`.
- **La condición de un `if` o `while` que es una variable o constante no usa temporal**: `if (p)` da `ifFalse p goto L1`, y `while (true)` da `ifFalse 1 goto L3`.
- **Llamadas anidadas**: en `suma(suma(1, 2), x)` se emiten primero `param 1`, `param 2` y `t13 = call suma, 2`, y **después** `param t13`, `param x`. Los `param` de la llamada externa nunca se intercalan con los de la interna.
- **`return` implícito solo si falta.** Un `void` que termina en `return;` explícito no lo duplica. Si la última instrucción emitida no es un `return` (por ejemplo, una etiqueta `L1:` después de un `if` con `return` adentro), sí se agrega. Una función **no** `void` sin `return` no recibe ninguno: termina en `leave`.
- **Un bloque suelto `{ ... }` no genera nada propio**: solo sus sentencias.
- **Las declaraciones** de variables locales y los parámetros no generan código.
- **`<=`, `>=`, `!=` no existen** en el IR (ni en el lenguaje). Solo hay `<`, `>`, `==` y la negación `!`.

### 4.4 Ejemplo con `&&` anidado en `||`

Para `p = !(x == 1) && x > 2 || p;` (`||` es el operador de menor precedencia, así que es la raíz). Los números suponen que antes ya se usaron `t1` a `t8` y `L1` a `L3`:

```
t11 = x == 1        ← lo primero que se genera: el operando más interno del &&
t12 = !t11
t10 = t12           ← t10 es el resultado del && (se pidió DESPUÉS que t9 y L4, pero ANTES que t11)
ifFalse t10 goto L5
t13 = x > 2
t10 = t13
L5:
t9 = t10            ← t9 es el resultado del || (se pidió primero)
t14 = !t9           ← el temporal extra del ||, pedido después de generar su primer operando
ifFalse t14 goto L4
t9 = p
L4:
p = t9
```

Los números salen de este orden: `t9` y `L4` (el `||`), `t10` y `L5` (el `&&`), `t11` y `t12` (operandos), `t13`, y recién al final `t14` (el `!` del `||`). Es el caso más difícil de numerar de toda la etapa.

### 4.5 Ejemplo completo (programa de la sección 2)

```
enter suma
t1 = b * 2
t2 = a + t1
r = t2
return r
leave
enter main
param 3
param 4
t3 = call suma, 2
x = t3
t5 = x > 5
t4 = t5
ifFalse t4 goto L1
t6 = g == 0
t4 = t6
L1:
ifFalse t4 goto L2
g = x
L2:
param g
call printInt, 1
return
leave
```

---

## 5. Assembly (se completa en la Sesión 4)

- **Offsets:** se asignan por orden de **primera aparición** en el `.ci`. Primero los parámetros (`-8`, `-16`, ... los 6 primeros llegan en `%rdi %rsi %rdx %rcx %r8 %r9`), después, recorriendo las cuádruplas, `arg1`, `arg2` y `res` de cada una (variables locales y temporales). Una local que nunca aparece no ocupa lugar.
- **Tamaño del frame:** `enter $N, $0` con N = cantidad de slots × 8, redondeado hacia arriba a múltiplo de 16.
- **Plantillas:** cargar operandos en `%r10`/`%r11`, operar, guardar. Comparaciones: `cmp; mov $0,%r11; mov $1,%r10; cmovX %r10,%r11`. División: `cqto; idiv`. `ifFalse`: `cmp $0,%r10; je .Ln`.
- Globales en `.bss`, acceso `nombre(%rip)`. Llamada a `extern`: `mov $0,%rax` antes del `call`.
- `return` genera `leave; ret`, y el `leave; ret` final aparece duplicado. Es normal.

Ejemplo completo en `suma`: ver salida de `./c-tds -target assembly`.

### Tabla de traducción (cada cuádrupla se traduce sola)

Regla de oro: **cargar → operar → guardar**. `mov` no copia memoria a memoria, así que siempre se pasa por `%r10`/`%r11`. AT&T: `mov origen, destino`.

| IR | Assembly |
|---|---|
| `x = y` | `mov y, %r10` / `mov %r10, x` |
| `t = a + b` | `mov a,%r10` / `mov b,%r11` / `add %r11,%r10` / `mov %r10,t` |
| `t = a - b` | igual con `sub %r11,%r10` |
| `t = a * b` | igual con `imul %r11,%r10` |
| `t = a / b` | `mov a,%rax` / `mov b,%r10` / `cqto` / `idiv %r10` / `mov %rax,t` |
| `t = a % b` | igual que `/` pero se guarda `%rdx` |
| `t = a < b` | `mov a,%r10` / `mov b,%r11` / `cmp %r11,%r10` / `mov $0,%r11` / `mov $1,%r10` / `cmovl %r10,%r11` / `mov %r11,t` |
| `t = a > b` / `t = a == b` | igual con `cmovg` / `cmove` |
| `t = -a` | `mov a,%r10` / `neg %r10` / `mov %r10,t` |
| `t = !a` | `mov a,%r10` / `xor $1,%r10` / `mov %r10,t` |
| `L:` | `.L:` |
| `goto L` | `jmp .L` |
| `ifFalse c goto L` | `mov c,%r10` / `cmp $0,%r10` / `je .L` |
| `param x` | no emite nada: se acumula hasta el `call` |
| `call f, n` | carga los args en `%rdi %rsi %rdx %rcx %r8 %r9` / (`mov $0,%rax` si es `extern`) / `call f` |
| `t = call f, n` | lo anterior + `mov %rax, t` (si es `extern`, antes `cltq`) |
| `return x` | `mov x,%rax` / `leave` / `ret` |
| `return` | `mov $0,%rax` / `leave` / `ret` |
| `leave` | `leave` / `ret` (queda duplicado tras un `return`) |

Operandos: constante → `$5`; local o temporal → `-8(%rbp)`; global → `nombre(%rip)` (no ocupa slot).

Esqueleto del archivo: `.bss` con las globales usadas → `.text` → cada función (`.globl main` solo para main; `nombre:`; `enter $N, $0`; copiar params de registros al frame; cuerpo) → `.section .note.GNU-stack,"",@progbits`.

---

## 6. Extensiones en vivo

**Truco principal:** escribir la sintaxis nueva en términos de nodos que ya existen, dentro de la acción del parser. Solo se tocan `.l` y `.y`; semántico, IR y assembly no se enteran.

| Pedido | Resolución en el `.y` |
|---|---|
| `a <= b` | `NEG(MAYOR(a,b))` |
| `a >= b` | `NEG(MENOR(a,b))` |
| `a != b` | `NEG(EQ(a,b))` |
| `a += b` | `OP_ASIG(a, SUMA(ID a, b))` |
| `for`, `do-while`, `until`, `unless` | combinando `WHILE`, `IF`, `NEG` |

Pasos: (1) regla en el `.l` con `return TOKEN`, (2) `%token` y precedencia en el `.y`, (3) producción con `crearNodo`, (4) recompilar (ver comandos arriba).

**Cuando hace falta una instrucción nueva** (por ejemplo `**`, `abs`, `<<`), recorrido completo:

1. `analizadorLexico.l`: regla del token.
2. `analizadorSintactico.y`: `%token`, precedencia, producción.
3. `ast.h`: nuevo valor en `TipoNodo`.
4. `ast.c`: caso en `tipoNodoNombre`.
5. `analizadorSemantico.c`: agregar el caso en `visitarExpresion` (o en la sentencia).
6. `codigoIntermedio.h`: nuevo `IR_*`. `codigoIntermedio.c`: caso en `genExpr` (o `genStmt`) y símbolo en `simboloBinario`.
7. `codigoObjeto.c`: caso en `traducirCuadrupla`.

Hay un precedente en el repo: `NODO_SHL` / `IR_SHL`.

Siempre: después de cada cambio, recompilar y probar con un programa corto usando `-target scan`, `parse`, `codinter` y `assembly` para ver en qué etapa se rompe.

---

## Ejercicio de la Sesión 1 (hacelo después de leer las secciones 1 y 2)

Hacé a mano la **etapa léxica** y el **AST** de este programa y comparalos con `-target scan` y `-target parse`:

```c
int g;
int doble(int v) { return v * 2; }
void main() {
    int i;
    i = 0;
    while (i < 3 && g == 0) { i = i + 1; }
    g = doble(i);
}
```

---

## Ejercicios de la Sesión 3

Cinco programas en `ejercicios/ci_01.ctds` a `ci_05.ctds`, de menor a mayor dificultad. Para cada uno:

1. **Sin mirar el compilador**, escribí el IR completo en una hoja, con los números de `t` y `L`.
2. Generá la salida real y compará línea por línea:

```sh
./c-tds -target codinter ejercicios/ci_01.ctds     # deja ejercicios/ci_01.ci
```

3. Un ejercicio cuenta como **bien** solo si es **idéntico**, incluidos los números. Si no, buscá la primera línea que difiere: casi siempre es el orden en que se pidió un `t` o una `L` (tabla 4.1).

Para no pisar tu respuesta, escribila en otro archivo (por ejemplo `mi_01.ci`) y compará con `diff mi_01.ci ejercicios/ci_01.ci`.

| Ejercicio | Qué practica | Estado |
|---|---|---|
| `ci_01` | Aritmética, precedencia, paréntesis, signo menos, una global (no genera código), asignaciones que copian | HECHO (idéntico al compilador) |
| `ci_02` | `while`, `if` con y sin `else`, condición que es una variable, comparaciones guardadas en un `boolean` | HECHO (corregido: había que numerar las etiquetas del `if`/`else`, no nombrarlas) |
| `ci_03` | Llamadas anidadas como argumento, llamada `void` y no `void` como sentencia, `return;` en el medio, `return` implícito | HECHO (corregido: faltaba el `return` implícito y el `leave` finales de `main`) |
| `ci_04` | `&&` y `||` con cortocircuito, mezclados y anidados, y usados como condición de `if` y `while` | HECHO (corregido: pedir `t`/`L` del `&&`/`||` antes de los operandos; `||` niega, `&&` no; `if` pide etiquetas después de la condición y `while` antes) |
| `ci_05` | Recursión, dos funciones (los contadores **no** se reinician), `||` con una llamada, `if`/`else` dentro de un `while` | PENDIENTE (opcional: casi todo repite lo anterior; sirve como simulacro cronometrado) |

Antes de comparar, anotá en cada uno cuántas etiquetas y cuántos temporales esperás usar en total. Si el conteo no coincide, ya sabés que la numeración falló sin leer línea por línea.

### Cómo compilar en Windows

El `c-tds` que está versionado en el repo es un binario de Linux o Mac y no corre en Windows. Si usás Windows sin WSL, con `gcc` y `flex` alcanza para compilar sin `bison`, porque `analizadorSintactico.tab.c` ya está generado en el repo:

```sh
flex analizadorLexico.l
gcc -o c-tds main.c ast.c optimizador.c tablaSimbolos.c analizadorSemantico.c codigoIntermedio.c codigoObjeto.c analizadorSintactico.tab.c lex.yy.c
```

`bison` solo hace falta si cambiás el `.y`. El `-target assembly` genera el `.ass`, pero armar el ejecutable necesita además un `gcc` y `libtds.c` junto al compilador.

### Criterio para dar por terminada la sesión

- Los cinco ejercicios idénticos al compilador.
- Podés explicar en una frase por qué en `&&` el temporal del resultado es menor que los de los operandos y en una suma es mayor.
- Podés resolver `ci_04` en menos de 15 minutos.
