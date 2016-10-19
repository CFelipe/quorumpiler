 /*
 reconhecimento de strings retirados de
 http://www.lysator.liu.se/c/ANSI-C-grammar-l.html

 regras para comentários retirados de
 http://stackoverflow.com/a/25396611
 */

%{
#include <stdio.h>

#define T_INTEGER_TYPE      1
#define T_NUMBER_TYPE       2
#define T_BOOLEAN_TYPE      3
#define T_TEXT_TYPE         4
#define T_CAST              5
#define T_LPAREN            6
#define T_COMMA             7
#define T_ID                8
#define T_RPAREN            9
#define T_OR                10
#define T_AND               11
#define T_NOTEQ             12
#define T_EQ                13
#define T_GR                14
#define T_LE                15
#define T_GREQ              16
#define T_LEEQ              17
#define T_PLUS              18
#define T_MINUS             19
#define T_TIMES_OP          20
#define T_DIV               21
#define T_FALSE             22
#define T_TRUE              23
#define T_NUMBER            24
#define T_INTEGER           25
#define T_DOT               26
#define T_ACTION            27
#define T_END               28
#define T_RETURNS           29
#define T_COLON             30
#define T_CLASS             31
#define T_IS                32
#define T_REPEAT            33
#define T_WHILE             34
#define T_UNTIL             35
#define T_IF                36
#define T_ELSEIF            37
#define T_ELSE              38
#define T_USE               39
#define T_CHECK             40
#define T_DETECT            41
#define T_ALWAYS            42
#define T_TIMES             43
#define T_TEXT              44
#define T_$                 45

#define END_OF_FILE         46
#define ERROR               47
#define BAD_COMMENT         48

#define NT_STMT             49
#define NT_STMTS            50
#define NT_TYPE             51
#define NT_CAST_EXPR        52
#define NT_EXPR             53
#define NT_E1               54
#define NT_E1P              55
#define NT_E2               56
#define NT_E2P              57
#define NT_E3               58
#define NT_E3P              59
#define NT_E4               60
#define NT_E4P              61
#define NT_E5               62
#define NT_E5P              63
#define NT_E6               64
#define NT_E6P              65
#define NT_E7               66
#define NT_E8               67
#define NT_LIB              68
#define NT_LIBP             69
#define NT_ARGS             70
#define NT_ARGSP            71
#define NT_ARGS_DEF         72
#define NT_ARGS_DEFP        73
#define NT_DECLARATION      74
#define NT_ACTION_DECL      75
#define NT_ACTION_ARGS      76
#define NT_ACTION_RET       77
#define NT_INSTANCE         78
#define NT_ACTION_CALL      79
#define NT_CLASS_DECL       80
#define NT_INHERITANCE      81
#define NT_ASSIGN           82
#define NT_ID_STMT          83
#define NT_ID_STMTP         84
#define NT_REPEAT_STMT      85
#define NT_REPEAT_STMTP     86
#define NT_IF_STMT          87
#define NT_ELSEIF_STMT      88
#define NT_ELSE_STMT        89
#define NT_USE_STMT         90
#define NT_CHECK_STMT       91
#define NT_DETECT_STMT      92
#define NT_ALWAYS_STMT      93

#define END                 '\0'

%}

%%


"//".*
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]
[/][*]                                  return BAD_COMMENT;

","         return T_COMMA;
":"         return T_COLON;
"("         return T_LPAREN;
")"         return T_RPAREN;
"="         return T_EQ;
"not="      return T_NOTEQ;
"+"         return T_PLUS;
"-"         return T_MINUS;
"*"         return T_TIMES_OP;
"/"         return T_DIV;
">"         return T_GR;
"<"         return T_LE;
">="        return T_GREQ;
"<="        return T_LEEQ;
"and"       return T_AND;
"or"        return T_OR;
"."         return T_DOT;

"boolean"   return T_BOOLEAN_TYPE;
"integer"   return T_INTEGER_TYPE;
"number"    return T_NUMBER_TYPE;
"text"      return T_TEXT_TYPE;

"repeat"    return T_REPEAT;
"while"     return T_WHILE;
"until"     return T_UNTIL;
"times"     return T_TIMES;
"if"        return T_IF;
"class"     return T_CLASS;
"else"      return T_ELSE;
"action"    return T_ACTION;
"returns"   return T_RETURNS;
"use"       return T_USE;
"check"     return T_CHECK;
"detect"    return T_DETECT;
"always"    return T_ALWAYS;
"cast"      return T_CAST;
"end"       return T_END;
"true"      return T_TRUE;
"false"     return T_FALSE;
"is"        return T_IS;

[0-9]+"."[0-9]*                         return T_NUMBER;
[0-9]+                                  return T_INTEGER;
([a-zA-Z])([a-zA-Z]|[0-9]|"_")*         return T_ID;
\"(\\.|[^\\"])*\"                       return T_TEXT;


(" "|\t)* /* ignora espaços */

.                                       return ERROR;

<<EOF>>                                 return T_$;



%%

/*
int main() {
    //printf("1 ");
    //"\n"                                    printf("\n%i ", ++line);
    yylex();
}
*/
