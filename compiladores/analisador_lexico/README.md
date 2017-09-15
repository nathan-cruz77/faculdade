Analisador Léxico - `C-`
=================

### Uso
```
$ make
$ ./parser arquivo.c
```

O resultado da análise léxica será exibido na saída padrão.

### Símbolos suportados

#### Palavras Reservadas
| Termo  |  Representação    |
|:------ |:------------------|
|  `if`  |`KEYWORD<"IF">`    |
|`else`  |`KEYWORD<"ELSE">`  |
|`return`|`KEYWORD<"RETURN">`|
|`while` |`KEYWORD<"WHILE">` |

#### Operadores
| Termo  |  Representação  |
|:------ |:----------------|
|   `+`  |`OPERATOR<"+">`  |
|   `-`  |`OPERATOR<"-">`  |
|`*`     |`OPERATOR<"*">`  |
|`/`     |`OPERATOR<"/">`  |
|  `<`   |`OPERATOR<"<">`  |
|`<=`    |`OPERATOR<"<=">` |
|`>`     |`OPERATOR<">">`  |
|`>=`    |`OPERATOR<">=">` |
|  `==`  |`OPERATOR<"==">` |
|`!=`    |`OPERATOR<"!=">` |
|`=`     |`OPERATOR<"=">`  |

#### Tipos embutidos
| Termo  |  Representação  |
|:------ |:----------------|
|`int`   |`TYPE<"INT">`    |
|`void`  |`TYPE<"VOID">`   |

#### Comentários
São suportados comentários iniciados em `/*` e terminados em `*/`.
São representados por `COMMENT`.

#### Identificadores
São suportados identificadores representados uma ou mais letras
`a` a `z`, tanto maiúsculas quando minúsculas. São identificados por:
`IDENTIFIER<name>`, onde `name` é o nome do identificador.

#### Números
São suportados números inteiros representados por um ou mais dígito
entre `0` e `9`. São representados da forma: `NUMBER<value>`, onde
`value` é o valor do número.

#### Espaços em branco
São consierados espaços em branco os caracteres `\t`(tabulação),
 `\n`(quebra de linha) e `\s`(espaço em branco).

#### Caracteres especiais
| Termo  |  Representação  |
|:------ |:----------------|
| `;`    |`;`              |
| `,`    |`,`              |
| `(`    |`(`              |
| `)`    |`)`              |
| `[`    |`[`              |
| `]`    |`]`              |
| `{`    |`{`              |
| `}`    |`}`              |

### Exemplo de uso
Dado o arquivo test.c:
```C
/* Um programa para calcular mdc */
int gdc (int u, int v)
{
   if (v == 0) return u;
   else return gdc(v,u-u/v*v);
   /* u-u / v*v == u mod v */
}

void main(void)
{
   int x;
   int y;
   x = input();
   y = input();
   output(gdc(x,y));
}
```
Temos a saída:
```
COMMENT
TYPE<"INT"> IDENTIFIER<"gdc"> (TYPE<"INT"> IDENTIFIER<"u">, TYPE<"INT"> IDENTIFIER<"v">)
{
   KEYWORD<"IF"> (IDENTIFIER<"v"> OPERATOR<"=="> NUMBER<"0">) KEYWORD<"RETURN"> IDENTIFIER<"u">;
   KEYWORD<"ELSE"> KEYWORD<"RETURN"> IDENTIFIER<"gdc">(IDENTIFIER<"v">,IDENTIFIER<"u">OPERATOR<"-">IDENTIFIER<"u">OPERATOR<"/">IDENTIFIER<"v">OPERATOR<"*">IDENTIFIER<"v">);
   COMMENT
}

TYPE<"VOID"> IDENTIFIER<"main">(TYPE<"VOID">)
{
   TYPE<"INT"> IDENTIFIER<"x">;
   TYPE<"INT"> IDENTIFIER<"y">;
   IDENTIFIER<"x"> OPERATOR<"="> IDENTIFIER<"input">();
   IDENTIFIER<"y"> OPERATOR<"="> IDENTIFIER<"input">();
   IDENTIFIER<"output">(IDENTIFIER<"gdc">(IDENTIFIER<"x">,IDENTIFIER<"y">));
}
```
