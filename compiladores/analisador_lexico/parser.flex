%{
    #include <stdio.h>
%}

/* Keywords */
ELSE "else"
IF "if"
RETURN "return"
WHILE "while"

/* Builtin types */
INT "int"
VOID "void"

/* Operators */
PLUS "+"
MINUS "-"
TIMES "*"
DIVIDE "/"
OPERATOR ({PLUS}|{MINUS}|{TIMES}|{DIVIDE})

/* Special symbols */
ASSIGN "="
EQ "=="
NOT_EQ "!="
LT "<"
LT_EQ "<="
GT ">"
GT_EQ ">="
LINE_TERMINATOR ";"
COMMA ","
OPEN_PARENTHESES "("
CLOSE_PARENTHESES ")"
OPEN_BRACKET "["
CLOSE_BRACKET "]"
OPEN_CURLY_BRACKET "{"
CLOSE_CURLY_BRACKET "}"

DIGIT [0-9]
NUMBER {DIGIT}+

LETTER [a-zA-Z]
IDENTIFIER {LETTER}+

WHITESPACE [ ]
TAB \t
NEWLINE \n
SPACE ({WHITESPACE}|{TAB}|{NEWLINE})+

/* This crap should fucking work */
/* COMMENT \/\*(.|{SPACE})+?\*\/ */
COMMENT "/*"([^*]|(\*+[^*\/]))*\*+\/

%%
{ELSE} { printf("KEYWORD<\"ELSE\">", yytext); }
{IF} { printf("KEYWORD<\"IF\">", yytext); }
{RETURN} { printf("KEYWORD<\"RETURN\">", yytext); }
{WHILE} { printf("KEYWORD<\"WHILE\">", yytext); }

{INT} { printf("TYPE<\"INT\">"); }
{VOID} { printf("TYPE<\"VOID\">"); }

{PLUS} { printf("OPERATOR<\"+\">"); }
{MINUS} { printf("OPERATOR<\"-\">"); }
{TIMES} { printf("OPERATOR<\"*\">"); }
{DIVIDE} { printf("OPERATOR<\"/\">"); }
{ASSIGN} { printf("OPERATOR<\"=\">"); }
{EQ} { printf("OPERATOR<\"==\">"); }
{NOT_EQ} { printf("OPERATOR<\"!=\">"); }
{LT} { printf("OPERATOR<\"<\">"); }
{LT_EQ} { printf("OPERATOR<\"<=\">"); }
{GT} { printf("OPERATOR<\">\">"); }
{GT_EQ} { printf("OPERATOR<\">=\">"); }
{LINE_TERMINATOR} { printf(";"); }
{COMMA} { printf(","); }
{OPEN_PARENTHESES} { printf("("); }
{CLOSE_PARENTHESES} { printf(")"); }
{OPEN_BRACKET} { printf("["); }
{CLOSE_BRACKET} { printf("]"); }
{OPEN_CURLY_BRACKET} { printf("{"); }
{CLOSE_CURLY_BRACKET} { printf("}"); }

{IDENTIFIER} { printf("IDENTIFIER<\"%s\">", yytext); }
{NUMBER} { printf("NUMBER<\"%s\">", yytext); }
{SPACE} { printf("%s", yytext); }
{COMMENT} { printf("COMMENT"); }

%%
int main(int argc, char *argv[]){
    FILE *f_in;

    if (argc == 2){
        if(f_in = fopen(argv[1], "r"))
            yyin = f_in;
        else
            perror(argv[0]);
    }
    else{
        yyin = stdin;
    }

    yylex();

    return 0;
}
