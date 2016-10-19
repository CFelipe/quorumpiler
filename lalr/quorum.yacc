%{
%}

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
%token TEXT

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

expr        :  expr PLUS_OP expr
            |  expr MINUS_OP expr
            |  expr TIMES_OP expr
            |  expr DIV_OP expr
            |  MINUS_OP expr
            |  LPAREN expr RPAREN
            ;

lib         :  ID lib'
            ;

lib'        :  DOT ID lib'
            |
            ;

args        :  ID args'
            |
            ;

args'       :  COMMA ID args'
            |
            ;

args_def    :  type ID args_def'
            ;

args_def'   :  COMMA type ID args_def'
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

action_call |  LPAREN args RPAREN
            ;

class_decl  :  CLASS ID inheritance declaration action_decl END
            ;

inheritance :  IS args
            |
            ;

assign      :  EQ expr
            ;

id_stmt     :  ID id_stmt'
            ;

id_stmt'    :  instance action_call
            |  assign
            ;

repeat_stmt :  REPEAT repeat_stmt' stmts END
            ;

repeat_stmt':  WHILE expr
            |  UNTIL expr
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
