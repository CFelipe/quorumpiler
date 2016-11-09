%{
#include <stdio.h>

int yylex();
int yyerror(char *s);
int yydebug = 1;
%}

%debug

%token INTEGER_TYPE
%token NUMBER_TYPE
%token BOOLEAN_TYPE
%token TEXT_TYPE
%token CAST
%token LPAREN
%token COMMA
%token ID
%token RPAREN
%token OR
%token AND
%token NOTEQ
%token EQ
%token GR
%token LE
%token GREQ
%token LEEQ
%token PLUS_OP
%token MINUS_OP
%token TIMES_OP
%token DIV_OP
%token FALSE
%token TRUE
%token NUMBER
%token TEXT
%token INTEGER
%token DOT
%token ACTION
%token END
%token RETURNS
%token COLON
%token CLASS
%token IS
%token REPEAT
%token WHILE
%token UNTIL
%token IF
%token ELSEIF
%token ELSE
%token USE
%token CHECK
%token DETECT
%token ALWAYS
%token TIMES
%token OUTPUT
%token RETURN
%token BAD_COMMENT
%token ERROR
%token END_OF_FILE

%left OR
%left AND
%right EQ NOTEQ
%nonassoc GR LE GREQ LEEQ
%left PLUS_OP MINUS_OP
%left TIMES_OP DIV_OP

%start stmts

%%

stmt        :  repeat_stmt
            |  if_stmt
            |  class_decl
            |  use_stmt
            |  check_stmt
            |  detect_stmt
            |  always_stmt
            |  declaration
            |  action_decl
            |  id_stmt
            |  output_stmt
            |  return_stmt
            ;

stmts       :  stmt stmts
            |
            ;

type        :  INTEGER_TYPE
            |  NUMBER_TYPE
            |  BOOLEAN_TYPE
            |  TEXT_TYPE
            ;

cast_expr   :  CAST LPAREN type COMMA ID RPAREN
            ;

expr        :  expr PLUS_OP expr    {$$ = $1 + $3;}
            |  expr MINUS_OP expr   {$$ = $1 - $3;}
            |  expr TIMES_OP expr   {$$ = $1 * $3;}
            |  expr DIV_OP expr     {$$ = $1 / $3;}
            |  expr OR expr         {$$ = $1 || $3;}
            |  expr AND expr        {$$ = $1 && $3;}
            |  expr EQ expr         {$$ = $1 = $3;}
            |  expr NOTEQ expr      {$$ = $1 != $3;}
            |  expr GR expr         {$$ = $1 > $3;}
            |  expr LE expr         {$$ = $1 < $3;}
            |  expr GREQ expr       {$$ = $1 >= $3;}
            |  expr LEEQ expr       {$$ = $1 <= $3;}
            |  cast_expr
            |  ID action_call
            |  FALSE
            |  TRUE
            |  NUMBER               {$$ = $1;}
            |  INTEGER              {$$ = $1;}
            |  ID                   {$$ = $1;}
            |  TEXT
            |  MINUS_OP expr        {$$ = - $2;}
            |  LPAREN expr RPAREN   {$$ = $2;}
            ;

lib         :  ID libp
            ;

libp        :  DOT ID libp
            |
            ;

args        :  expr argsp
            |
            ;

argsp       :  COMMA expr argsp
            |
            ;

args_def    :  type ID args_defp
            ;

args_defp   :  COMMA type ID args_defp
            |
            ;

declaration :  type ID EQ expr
            ;

action_decl :  ACTION ID action_args action_ret stmts END
            ;

action_args :  LPAREN args_def RPAREN
            |
            ;

action_ret  :  RETURNS type
            |
            ;

instance    :  COLON ID instance
            |
            ;

action_call :  LPAREN args RPAREN
            ;

class_decl  :  CLASS ID inheritance action_decl END
            ;

inheritance :  IS args
            |
            ;

assign      :  EQ expr
            ;

id_stmt     :  ID id_stmtp
            ;

id_stmtp    :  instance action_call
            |  assign
            ;

repeat_stmt :  REPEAT repeat_stmtp stmts END
            ;

repeat_stmtp:  WHILE expr
            |  UNTIL expr
            |  INTEGER TIMES
            ;

if_stmt     :  IF expr stmts elseif_stmt
            ;

elseif_stmt :  ELSEIF expr stmts elseif_stmt
            |  else_stmt
            ;

else_stmt   :  ELSE stmts END
            |  END
            ;

use_stmt    :  USE lib
            ;

check_stmt  :  CHECK stmts END
            ;

detect_stmt :  DETECT ID IS ID stmts END
            ;

always_stmt :  ALWAYS stmts END
            ;

output_stmt :  OUTPUT ID
            |  OUTPUT TEXT
            ;

return_stmt :  RETURN expr
            ;

%%

int yyerror(char *s) {
    printf("%s\n",s);
    return 1;
}

int main(void) {
    return(yyparse());
}
