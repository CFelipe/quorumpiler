#include "lex.yy.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_token(char tok) {
    switch(tok) {
        case T_COMMA: return ","; break;
        case T_COLON: return ":'"; break;
        case T_LPAREN: return "("; break;
        case T_RPAREN: return ")"; break;
        case T_EQ: return "="; break;
        case T_PLUS: return "+"; break;
        case T_MINUS: return "-"; break;
        case T_TIMES_OP: return "*"; break;
        case T_DIV: return "/"; break;
        case T_NOTEQ: return "not="; break;
        case T_LE: return "<"; break;
        case T_GR: return ">"; break;
        case T_GREQ: return ">="; break;
        case T_LEEQ: return "<="; break;
        case T_AND: return "and"; break;
        case T_OR: return "or"; break;
        case T_DOT: return "."; break;
        case T_BOOLEAN_TYPE: return "boolean"; break;
        case T_INTEGER_TYPE: return "integer"; break;
        case T_NUMBER_TYPE: return "number"; break;
        case T_TEXT_TYPE: return "text"; break;
        case T_REPEAT: return "repeat"; break;
        case T_WHILE: return "while"; break;
        case T_UNTIL: return "until"; break;
        //case T_TIMES: return "times"; break;
        case T_IF: return "if"; break;
        case T_CLASS: return "class"; break;
        case T_ELSE: return "else"; break;
        case T_ELSEIF: return "elseif"; break;
        case T_ACTION: return "action"; break;
        case T_RETURNS: return "returns"; break;
        case T_USE: return "use"; break;
        case T_CHECK: return "check"; break;
        case T_DETECT: return "detect"; break;
        case T_ALWAYS: return "always"; break;
        case T_CAST: return "cast"; break;
        case T_END: return "end"; break;
        case T_TRUE: return "true"; break;
        case T_FALSE: return "false"; break;
        //case T_OUTPUT: return "ouput"; break;
        case T_IS: return "is"; break;
        case T_NUMBER: return "number"; break;
        case T_INTEGER: return "integer"; break;
        case T_ID: return "id"; break;

        case NT_EXPR:   return "EXPR"; break;
        case NT_E1:     return "E1"; break;
        case NT_E1P:    return "E1'"; break;
        case NT_E2:     return "E2"; break;
        case NT_E2P:    return "E2'"; break;
        case NT_E3:     return "E3"; break;
        case NT_E3P:    return "E3'"; break;
        case NT_E4:     return "E4"; break;
        case NT_E4P:    return "E4'"; break;
        case NT_E5:     return "E5"; break;
        case NT_E5P:    return "E5'"; break;
        case NT_E6:     return "E6"; break;
        case NT_E6P:    return "E6'"; break;
        case NT_E7:     return "E7"; break;
        case NT_E8:     return "E8"; break;

        case NT_STMT: return "STMT"; break;
        case NT_STMTS: return "STMTS"; break;
        case NT_TYPE: return "TYPE"; break;
        case NT_CAST_EXPR: return "CAST_EXPR"; break;
        case NT_LIB: return "LIB"; break;
        case NT_LIBP: return "LIB'"; break;
        case NT_ARGS: return "ARGS"; break;
        case NT_ARGSP: return "ARGS'"; break;
        case NT_ARGS_DEF: return "ARGS_DEF"; break;
        case NT_ARGS_DEFP: return "ARGS_DEF'"; break;
        case NT_DECLARATION: return "DECLARATION"; break;
        case NT_ACTION_DECL: return "ACTION_DECL"; break;
        case NT_ACTION_ARGS: return "ACTION_ARGS"; break;
        case NT_ACTION_RET: return "ACTION_RET"; break;
        case NT_INSTANCE: return "INSTANCE"; break;
        case NT_ACTION_CALL: return "ACTION_CALL"; break;
        case NT_CLASS_DECL: return "CLASS_DECL"; break;
        case NT_INHERITANCE: return "INHERITANCE'"; break;
        case NT_ASSIGN: return "ASSIGN"; break;
        case NT_ID_STMT: return "ID_STMT"; break;
        case NT_ID_STMTP: return "ID_STMT'"; break;
        case NT_REPEAT_STMT: return "REPEAT_STMT"; break;
        case NT_REPEAT_STMTP: return "REPEAT_STMT'"; break;
        case NT_IF_STMT: return "IF_STMT"; break;
        case NT_ELSEIF_STMT: return "ELSEIF_STMT"; break;
        case NT_ELSE_STMT: return "ELSE_STMT"; break;
        case NT_USE_STMT: return "USE_STMT"; break;
        case NT_CHECK_STMT: return "CHECK_STMT"; break;
        case NT_DETECT_STMT: return "DETECT_STMT"; break;
        case NT_ALWAYS_STMT: return "ALWAYS"; break;
        //case T_$: return "$"; break;
        default: return "?";
    }
}

char current_tok;

void printd(char* str) {
    printf("tok: %s (%i)\n", get_token(current_tok), current_tok);
    printf("nonterm: %s\n", str);
    printf("---\n");
}

void error() {
    printf("Error\n");
    exit(1);
}

void eat(char tok) {
    if(current_tok == tok) {
        printf("eating %s\n", get_token(current_tok));
        current_tok = yylex();
    } else {
        error();
    }
}


void STMT();
void TYPE();
void CAST_EXPR();
void EXPR();
void E1();
void E1P();
void E2();
void E2P();
void E3();
void E3P();
void E4();
void E4P();
void E5();
void E5P();
void E6();
void E6P();
void E7();
void E8();
void LIB();
void LIBP();
void ARGS();
void ARGSP();
void ARGS_DEF();
void ARGS_DEFP();
void ACTION_DECL();
void ACTION_ARGS();
void ACTION_RET();
void INSTANCE();
void ACTION_CALL();
void CLASS_DECL();
void INHERITANCE();
void ASSIGN();
void ID_STMT();
void ID_STMTP();
void REPEAT_STMT();
void REPEAT_STMTP();
void IF_STMT();
void ELSEIF_STMT();
void ELSE_STMT();
void USE_STMT();
void CHECK_STMT();
void DETECT_STMT();
void ALWAYS_STMT();
void DECLARATION();


void STMT() {
    printd("STMT");
    switch(current_tok) {
        case T_REPEAT:
            REPEAT_STMT();
            break;
        case T_IF:
            IF_STMT();
            break;
        case T_CLASS:
            CLASS_DECL();
            break;
        case T_USE:
            USE_STMT();
            break;
        case T_CHECK:
            CHECK_STMT();
            break;
        case T_DETECT:
            DETECT_STMT();
            break;
            ALWAYS_STMT();
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
            DECLARATION();
            break;
        case T_ACTION:
            ACTION_DECL();
            break;
        case T_ID:
            ID_STMT();
            break;
        default:
            error();
    }
}

void STMTS() {
    printd("STMTS");
    switch(current_tok) {
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
        case T_ID:
        case T_ACTION:
        case T_CLASS:
        case T_REPEAT:
        case T_IF:
        case T_USE:
        case T_CHECK:
        case T_DETECT:
            STMT();
            STMTS();
            break;
        case T_ELSE:
        case T_ELSEIF:
            break;
        default:
            error();
    }
}

void TYPE() {
    printd("TYPE");
    switch(current_tok) {
        case T_INTEGER_TYPE:
            eat(T_INTEGER_TYPE);
            break;
        case T_NUMBER_TYPE:
            eat(T_NUMBER_TYPE);
            break;
        case T_BOOLEAN_TYPE:
            eat(T_BOOLEAN_TYPE);
            break;
        case T_TEXT_TYPE:
            eat(T_TEXT_TYPE);
            break;
        default:
            error();
    }
}

void CAST_EXPR() {
    printd("CAST_EXPR");
    switch(current_tok) {
        case T_CAST:
            eat(T_CAST);
            eat(T_LPAREN);
            TYPE();
            eat(T_COMMA);
            eat(T_ID);
            eat(T_RPAREN);
            break;
        default:
            error();
    }
}

void EXPR() {
    printd("EXPR");
    switch(current_tok) {
        case T_CAST:
        case T_LPAREN:
        case T_ID:
        case T_FALSE:
        case T_TRUE:
        case T_NUMBER:
        case T_INTEGER:
            E1();
            break;
        default:
            error();
    }
}

void E1() {
    printd("E1");
    switch(current_tok) {
        case T_CAST:
        case T_LPAREN:
        case T_ID:
        case T_FALSE:
        case T_TRUE:
        case T_NUMBER:
        case T_INTEGER:
            E2();
            E1P();
            break;
        default:
            error();
            break;
    }
}

void E1P() {
    printd("E1'");
    switch(current_tok) {
        case T_OR:
            eat(T_OR);
            E2();
            E1P();
            break;
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
        case T_ID:
        case T_RPAREN:
        case T_ACTION:
        case T_END:
        case T_CLASS:
        case T_REPEAT:
        case T_IF:
        case T_ELSEIF:
        case T_ELSE:
        case T_USE:
        case T_CHECK:
        case T_DETECT:
        case T_ALWAYS:
        case T_$:
            // EPSILON
            break;
        default:
            error();
            break;
    }
}

void E2() {
    printd("E2");
    switch(current_tok) {
        case T_CAST:
        case T_LPAREN:
        case T_ID:
        case T_FALSE:
        case T_TRUE:
        case T_NUMBER:
        case T_INTEGER:
            E3();
            E2P();
            break;
        default:
            error();
            break;
    }
}

void E2P() {
    switch(current_tok) {
        case T_AND:
            eat(T_AND);
            E3();
            E2P();
            break;
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
        case T_ID:
        case T_RPAREN:
        case T_OR:
        case T_ACTION:
        case T_END:
        case T_CLASS:
        case T_REPEAT:
        case T_IF:
        case T_ELSEIF:
        case T_ELSE:
        case T_USE:
        case T_CHECK:
        case T_DETECT:
        case T_ALWAYS:
        case T_$:
            // EPSILON
            break;
        default:
            error();
            break;
    }
}

void E3() {
    printd("E3");
    switch(current_tok) {
        case T_CAST:
        case T_LPAREN:
        case T_ID:
        case T_FALSE:
        case T_TRUE:
        case T_NUMBER:
        case T_INTEGER:
            E4();
            E3P();
            break;
        default:
            error();
            break;
    }
}

void E3P() {
    printd("E3'");
    switch(current_tok) {
        case T_NOTEQ:
            eat(T_NOTEQ);
            E4();
            E3P();
            break;
        case T_EQ:
            eat(T_EQ);
            E4();
            E3P();
            break;
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
        case T_ID:
        case T_RPAREN:
        case T_OR:
        case T_AND:
        case T_ACTION:
        case T_END:
        case T_CLASS:
        case T_REPEAT:
        case T_IF:
        case T_ELSEIF:
        case T_ELSE:
        case T_USE:
        case T_CHECK:
        case T_DETECT:
        case T_ALWAYS:
        case T_$:
            //EPSILON
            break;
        default:
            error();
            break;
    }
}

void E4() {
    printd("E4");
    switch(current_tok) {
        case T_CAST:
        case T_LPAREN:
        case T_ID:
        case T_FALSE:
        case T_TRUE:
        case T_NUMBER:
        case T_INTEGER:
            E5();
            E4P();
            break;
        default:
            error();
            break;
    }
}

void E4P() {
    printd("E4'");
    switch(current_tok) {
        case T_GR:
            eat(T_GR);
            E5();
            E4P();
            break;
        case T_GREQ:
            eat(T_GREQ);
            E5();
            E4P();
            break;
        case T_LE:
            eat(T_LE);
            E5();
            E4P();
            break;
        case T_LEEQ:
            eat(T_LEEQ);
            E5();
            E4P();
            break;
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
        case T_ID:
        case T_RPAREN:
        case T_OR:
        case T_AND:
        case T_NOTEQ:
        case T_EQ:
        case T_ACTION:
        case T_END:
        case T_CLASS:
        case T_REPEAT:
        case T_IF:
        case T_ELSEIF:
        case T_ELSE:
        case T_USE:
        case T_CHECK:
        case T_DETECT:
        case T_ALWAYS:
        case T_$:
            // EPSILON
            break;
        default:
            error();
            break;
    }
}

void E5() {
    printd("E5");
    switch(current_tok) {
        case T_CAST:
        case T_LPAREN:
        case T_ID:
        case T_FALSE:
        case T_TRUE:
        case T_NUMBER:
        case T_INTEGER:
            E6();
            E5P();
            break;
        default:
            error();
            break;
    }
}

void E5P() {
    printd("E5'");
    switch(current_tok) {
        case T_PLUS:
            eat(T_PLUS);
            E6();
            E5P();
            break;
        case T_MINUS:
            eat(T_MINUS);
            E6();
            E5P();
            break;
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
        case T_ID:
        case T_RPAREN:
        case T_OR:
        case T_AND:
        case T_NOTEQ:
        case T_EQ:
        case T_GR:
        case T_LE:
        case T_GREQ:
        case T_LEEQ:
        case T_ACTION:
        case T_END:
        case T_CLASS:
        case T_REPEAT:
        case T_IF:
        case T_ELSEIF:
        case T_ELSE:
        case T_USE:
        case T_CHECK:
        case T_DETECT:
        case T_ALWAYS:
        case T_$:
            //EPSILON
            break;
        default:
            error();
            break;
    }
}

void E6() {
    printd("E6");
    switch(current_tok) {
        case T_CAST:
        case T_LPAREN:
        case T_ID:
        case T_FALSE:
        case T_TRUE:
        case T_NUMBER:
        case T_INTEGER:
            E7();
            E6P();
            break;
        default:
            error();
            break;
    }
}

void E6P() {
    printd("E6P");
    switch(current_tok) {
        case T_TIMES_OP:
            eat(T_TIMES_OP);
            E6();
            E5P();
            break;
        case T_DIV:
            eat(T_DIV);
            E7();
            E6P();
            break;
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
        case T_ID:
        case T_RPAREN:
        case T_OR:
        case T_AND:
        case T_NOTEQ:
        case T_EQ:
        case T_GR:
        case T_LE:
        case T_GREQ:
        case T_LEEQ:
        case T_PLUS:
        case T_MINUS:
        case T_ACTION:
        case T_END:
        case T_CLASS:
        case T_REPEAT:
        case T_IF:
        case T_ELSEIF:
        case T_ELSE:
        case T_USE:
        case T_CHECK:
        case T_DETECT:
        case T_ALWAYS:
        case T_$:
            // EPSILON
            break;
        default:
            error();
            break;
    }
}

void E7() {
    printd("E7");
    switch(current_tok) {
        case T_CAST:
            CAST_EXPR();
            break;
        case T_FALSE:
            eat(T_FALSE);
            break;
        case T_TRUE:
            eat(T_TRUE);
            break;
        case T_NUMBER:
            eat(T_NUMBER);
            break;
        case T_INTEGER:
            eat(T_INTEGER);
            break;
        case T_ID:
            eat(T_ID);
            break;
        case T_LPAREN:
            E8();
            break;
        default:
            error();
            break;
    }
}

void E8() {
    printd("E8");
    switch(current_tok) {
        case T_LPAREN:
            eat(T_LPAREN);
            E1();
            eat(T_RPAREN);
            break;
        default:
            error();
            break;
    }
}

void LIB() {
    printd("LIB");
    switch(current_tok) {
        case T_ID:
            eat(T_ID);
            LIBP();
            break;
        default:
            error();
            break;
    }
}

void LIBP() {
    printd("LIB'");
    switch(current_tok) {
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
        case T_ID:
        case T_ACTION:
        case T_END:
        case T_CLASS:
        case T_REPEAT:
        case T_IF:
        case T_ELSEIF:
        case T_ELSE:
        case T_USE:
        case T_CHECK:
        case T_DETECT:
        case T_ALWAYS:
        case T_$:
            // EPSILON
            break;
        case T_DOT:
            eat(T_DOT);
            eat(T_ID);
            LIBP();
            break;
        default:
            error();
            break;

    }
}

void ARGS() {
    printd("ARGS");
    switch(current_tok) {
        case T_ID:
            eat(T_ID);
            ARGSP();
            break;
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
        case T_RPAREN:
            //EPSILON;
            break;
        default:
            error();
            break;
    }
}

void ARGSP() {
    printd("ARGS'");
    switch(current_tok) {
        case T_COMMA:
            eat(T_COMMA);
            eat(T_ID);
            ARGSP();
            break;
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
        case T_RPAREN:
            //EPSILON;
            break;
        default:
            error();
            break;
    }
}

void ARGS_DEF() {
    printd("ARGS_DEF");
    switch(current_tok) {
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
            TYPE();
            eat(T_ID);
            ARGS_DEFP();
            break;
        default:
            error();
            break;
    }
}

void ARGS_DEFP() {
    printd("ARGS_DEF'");
    switch(current_tok) {
        case T_COMMA:
            eat(T_COMMA);
            TYPE();
            eat(T_ID);
            ARGS_DEFP();
            break;
        case T_RPAREN:
            // EPSILON
            break;
        default:
            error();
            break;
    }
}

void DECLARATION() {
    printd("DECLARATION");
    switch(current_tok) {
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
            TYPE();
            eat(T_ID);
            eat(T_EQ);
            EXPR();
            break;
        default:
            error();
            break;
    }
}

void ACTION_DECL() {
    printd("ACTION_DECL");
    switch(current_tok) {
        case T_ACTION:
            eat(T_ACTION);
            eat(T_ID);
            ACTION_ARGS();
            ACTION_RET();
            STMTS();
            eat(T_END);
            break;
        default:
            error();
            break;
    }
}

void ACTION_ARGS() {
    printd("ACTION_ARGS");
    switch(current_tok) {
        case T_LPAREN:
            eat(T_LPAREN);
            ARGS_DEF();
            eat(T_RPAREN);
            break;
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
        case T_ID:
        case T_ACTION:
        case T_END:
        case T_RETURNS:
        case T_CLASS:
        case T_REPEAT:
        case T_IF:
        case T_ELSEIF:
        case T_ELSE:
        case T_USE:
        case T_CHECK:
        case T_DETECT:
        case T_ALWAYS:
        case T_$:
            //EPSILON
            break;
        default:
            error();
            break;
    }

}

void ACTION_RET() {
    printd("ACTION_RET");
    switch(current_tok) {
        case T_RETURNS:
            eat(T_RETURNS);
            TYPE();
            break;
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
        case T_ID:
        case T_ACTION:
        case T_END:
        case T_CLASS:
        case T_REPEAT:
        case T_IF:
        case T_ELSEIF:
        case T_ELSE:
        case T_USE:
        case T_CHECK:
        case T_DETECT:
        case T_ALWAYS:
        case T_$:
            //EPSILON
            break;
        default:
            error();
            break;
    }
}

void INSTANCE() {
    printd("INSTANCE");
    switch(current_tok) {
        case T_COLON:
            eat(T_COLON);
            eat(T_ID);
            INSTANCE();
            break;
        case T_LPAREN:
            //EPSILON
            break;
        default:
            error();
            break;
    }
}

void ACTION_CALL() {
    printd("ACTION_CALL");
    switch(current_tok) {
        case T_LPAREN:
            eat(T_LPAREN);
            ARGS();
            eat(T_RPAREN);
            break;
        default:
            error();
            break;
    }
}

void CLASS_DECL() {
    printd("CLASS_DECL");
    switch(current_tok) {
        case T_CLASS:
            eat(T_CLASS);
            eat(T_ID);
            INHERITANCE();
            DECLARATION();
            ACTION_DECL();
            eat(T_END);
            break;
        default:
            error();
            break;
    }
}

void INHERITANCE() {
    printd("INHERITANCE");
    switch(current_tok) {
        case T_IS:
            eat(T_IS);
            ARGS();
            break;
        case T_INTEGER_TYPE:
        case T_NUMBER_TYPE:
        case T_BOOLEAN_TYPE:
        case T_TEXT_TYPE:
            //EPSILON
            break;
        default:
            error();
            break;
    }
}

void ASSIGN() {
    printd("ASSIGN");
    switch(current_tok) {
        case T_EQ:
            eat(T_EQ);
            EXPR();
        default:
            error();
            break;
    }
}

void ID_STMT() {
    printd("ID_STMT");
    eat(T_ID);
    ID_STMTP();
}

void ID_STMTP() {
    printd("ID_STMT'");
    INSTANCE();
    ACTION_CALL();

    ASSIGN();
}

void REPEAT_STMT() {
    printd("REPEAT_STMT");
    eat(T_REPEAT);
    REPEAT_STMTP();
    STMTS();
    eat(T_END);
}

void REPEAT_STMTP() {
    printd("REPEAT_STMT'");
    eat(T_WHILE);
    EXPR();

    eat(T_UNTIL);
    EXPR();
}

void IF_STMT() {
    printd("IF_STMT");
    eat(T_IF);
    EXPR();
    STMTS();
    ELSEIF_STMT();
}

void ELSEIF_STMT() {
    printd("ELSEIF_STMT");
    eat(T_ELSEIF);
    EXPR();
    STMTS();
    ELSEIF_STMT();

    ELSE_STMT();
}

void ELSE_STMT() {
    printd("ELSE_STMT");
    eat(T_ELSE);
    STMTS();
    eat(T_END);

    eat(T_END);
}

void USE_STMT() {
    printd("USE_STMT");
    eat(T_USE);
    LIB();
}

void CHECK_STMT() {
    printd("CHECK_STMT");
    eat(T_CHECK);
    STMTS();
    eat(T_END);
}

void DETECT_STMT() {
    printd("DETECT_STMT");
    eat(T_DETECT);
    eat(T_ID);
    eat(T_IS);
    eat(T_ID);
    STMTS();
    eat(T_END);
}

void ALWAYS_STMT() {
    printd("ALWAYS_STMT");
    eat(T_ALWAYS);
    STMTS();
    eat(T_END);
}

int main(int argc, char *argv[]) {
    FILE *fp;

    if((fp = fopen("graph3.dot", "w")) == 0){
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    fprintf(fp, "digraph BST {\n");
    fprintf(fp, "node [shape=\"box\", height=0.25];\n");

    current_tok = yylex();
    E1();

    fprintf(fp, "}\n");
    fclose(fp);
}
