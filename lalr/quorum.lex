 /*
 reconhecimento de strings retirados de
 http://www.lysator.liu.se/c/ANSI-C-grammar-l.html

 regras para comentários retirados de
 http://stackoverflow.com/a/25396611
 */

%{
#include <stdio.h>
#include "y.tab.h"
%}

%%

"//".*
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]
[/][*]                                  return BAD_COMMENT;

","         return COMMA;
":"         return COLON;
"("         return LPAREN;
")"         return RPAREN;
"="         return EQ;
"not="      return NOTEQ;
"+"         return PLUS_OP;
"-"         return MINUS_OP;
"*"         return TIMES_OP;
"/"         return DIV_OP;
">"         return GR;
"<"         return LE;
">="        return GREQ;
"<="        return LEEQ;
"and"       return AND;
"or"        return OR;
"."         return DOT;

"boolean"   return BOOLEAN_TYPE;
"integer"   return INTEGER_TYPE;
"number"    return NUMBER_TYPE;
"text"      return TEXT_TYPE;

"repeat"    return REPEAT;
"while"     return WHILE;
"until"     return UNTIL;
"times"     return TIMES;
"if"        return IF;
"class"     return CLASS;
"else"      return ELSE;
"action"    return ACTION;
"returns"   return RETURNS;
"use"       return USE;
"check"     return CHECK;
"detect"    return DETECT;
"always"    return ALWAYS;
"cast"      return CAST;
"end"       return END;
"true"      return TRUE;
"false"     return FALSE;
"is"        return IS;

[0-9]+"."[0-9]*                         return NUMBER;
[0-9]+                                  return INTEGER;
([a-zA-Z])([a-zA-Z]|[0-9]|"_")*         return ID;
\"(\\.|[^\\"])*\"                       return TEXT;


(" "|\t)* /* ignora espaços */

.                                       return ERROR;

<<EOF>>                                 return END_OF_FILE;


%%

int main(void) {
    yyparse();
    return 0;
}

int yywrap(void) {
    return 0;
}

int yyerror(char* error) {
    printf("%s\n", error);
    exit(1);
}
