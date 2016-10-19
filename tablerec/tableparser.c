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
        case T_$: return "$"; break;
        default: return "?";
    }
}

void print_token(char tok) {
    printf("%s", get_token(tok));
}

typedef struct element {
    char el;
    int id;
} element;

typedef struct {
    element* el;
    int id;
    int top;
    int limit;
} stack;

stack init_stack() {
   stack st;
   st.el = malloc(sizeof(element) * 100);
   st.top = 0;
   st.limit = 100;
   return st;
}

void print_stack(stack st) {
    printf("stack: ");
    int count = 1;
    while(count <= st.top) {
        print_token(st.el[count].el);
        //printf("%i", st.el[count].id);
        printf(" | ");
        ++count;
    }
    printf("\n");
}

void push(stack* st, char symbol, int id) {
    st->top += 1;
    st->id = id;
    st->el[st->top].el = symbol;
    st->el[st->top].id = id;
}

element* pop(stack* st) {
    if(st->top > 0) {
        st->top -= 1;
        return &st->el[st->top + 1];
    }
    return NULL;
}

bool empty(stack st) {
    return st.top == 0;
}

element* top(stack st) {
    if(!empty(st)) {
        return &st.el[st.top];
    } else {
        return NULL;
    }
}

typedef struct node {
    char token;
    struct node* right;
    struct node* child;
} node;

node new_node(char token) {
    node n;
    n.token = token;
    n.right = 0;
    n.child = 0;
    return n;
}

void print_tree(node root, int level) {
    for(int i = 0; i <= level; ++i) {
        printf("|   ");
    }

    printf("%c\n", root.token);

    if(root.right) {
        print_tree(*root.right, level);
    }

    if(root.child) {
        print_tree(*root.child, level + 1);
    }
}

void print_to_file_aux(FILE* fp, node root, node parent) {
    if(root.right) {
        fprintf(fp, "%c -> %c\n", parent.token, root.right->token);
        print_to_file_aux(fp, *root.right, root);
    }

    if(root.child) {
        fprintf(fp, "%c -> %c\n", root.token, root.child->token);
        print_to_file_aux(fp, *root.child, root);
    }
}

void print_to_file(FILE* fp, node root) {
    fprintf(fp, "digraph BST {\n");
    fprintf(fp, "node [fontname=\"Heuristica Regular\", shape=\"box\"];\n");

    print_to_file_aux(fp, root, root);

    fprintf(fp, "}\n");
}

int error() {
    printf("Error\n");
    return 1;
}

int main(int argc, char *argv[]) {
    FILE *fp;

    if((fp = fopen("graph2.dot", "w")) == 0){
        printf("Erro ao abrir arquivo");
        exit(1);
    }

    fprintf(fp, "digraph BST {\n");
    //fprintf(fp, "node [fontname=\"Heuristica Regular\"];\n");
    fprintf(fp, "node [fontname=\"Heuristica Regular\", shape=\"box\", height=0.25];\n");

    //char* tok;
    char tok = yylex();
    //char input[] = {T_INTEGER_TYPE, T_ID, T_EQ, T_ID, T_TIMES_OP, T_LPAREN, T_ID, T_PLUS, T_ID, T_RPAREN, T_END};
    //char input[] = {T_REPEAT, T_WHILE, T_TRUE, T_ID, T_EQ, T_NUMBER, T_END, END};
    char a;
    char x;
    int ip = 0;
    int count = 0;
    int t_id = 0;

    stack st = init_stack();
    push(&st, T_$, t_id);
    ++t_id;
    push(&st, NT_STMT, t_id);
    fprintf(fp, "%i [label=\"%s\"]\n", t_id, get_token(NT_EXPR));
    ++t_id;

    char r[91][10] = {
                     {END},
                     {NT_REPEAT_STMT, END},
                     {NT_IF_STMT, END},
                     {NT_CLASS_DECL, END},
                     {NT_USE_STMT, END},
                     {NT_CHECK_STMT, END},
                     {NT_DETECT_STMT, END},
                     {NT_ALWAYS_STMT, END},
                     {NT_DECLARATION, END},
                     {NT_ACTION_DECL, END},
                     {NT_ID_STMT, END},
                     {NT_STMT, NT_STMTS, END},
                     {END},
                     {T_INTEGER_TYPE, END},
                     {T_NUMBER_TYPE, END},
                     {T_BOOLEAN_TYPE, END},
                     {T_TEXT_TYPE, END},
                     {T_CAST, T_LPAREN, NT_TYPE, T_COMMA, T_ID, T_RPAREN, END},
                     {NT_E1, END},
                     {NT_E2, NT_E1P, END},
                     {T_OR, NT_E2, NT_E1P, END},
                     {END},
                     {NT_E3, NT_E2P, END},
                     {T_AND, NT_E3, NT_E2P, END},
                     {END},
                     {NT_E4, NT_E3P, END},
                     {T_NOTEQ, NT_E4, NT_E3P, END},
                     {T_EQ, NT_E4, NT_E3P, END},
                     {END},
                     {NT_E5, NT_E4P, END},
                     {T_GR, NT_E5, END},
                     {T_LE, NT_E5, END},
                     {T_GREQ, NT_E5, END},
                     {T_LEEQ, NT_E5, END},
                     {END},
                     {NT_E6, NT_E5P, END},
                     {T_PLUS, NT_E6, NT_E5P, END},
                     {T_MINUS, NT_E6, NT_E5P, END},
                     {END},
                     {NT_E7, NT_E6P, END},
                     {T_TIMES_OP, NT_E7, NT_E6P, END},
                     {T_DIV, NT_E7, NT_E6P, END},
                     {END},
                     {NT_CAST_EXPR, END},
                     {T_FALSE, END},
                     {T_TRUE, END},
                     {T_NUMBER, END},
                     {T_INTEGER, END},
                     {T_ID, END},
                     {NT_E8, END},
                     {T_LPAREN, NT_E1, T_RPAREN, END},
                     {T_ID, NT_LIBP, END},
                     {T_DOT, T_ID, NT_LIBP, END},
                     {END},
                     {T_ID, NT_ARGSP, END},
                     {END},
                     {T_COMMA, T_ID, NT_ARGSP, END},
                     {END},
                     {NT_TYPE, T_ID, NT_ARGS_DEFP, END},
                     {T_COMMA, NT_TYPE, T_ID, NT_ARGS_DEFP, END},
                     {END},
                     {NT_TYPE, T_ID, T_EQ, NT_EXPR, END},
                     {T_ACTION, T_ID, NT_ACTION_ARGS, NT_ACTION_RET, NT_STMTS, END},
                     {T_LPAREN, NT_ARGS_DEF, T_RPAREN, END},
                     {END},
                     {T_RETURNS, NT_TYPE, END},
                     {END},
                     {T_COLON, T_ID, NT_INSTANCE, END},
                     {END},
                     {T_LPAREN, NT_ARGS, T_RPAREN, END},
                     {T_CLASS, T_ID, NT_INHERITANCE, NT_DECLARATION, NT_ACTION_DECL, T_END, END},
                     {T_IS, NT_ARGS, END},
                     {END},
                     {T_EQ, NT_EXPR, END},
                     {T_ID, NT_ID_STMTP, END},
                     {NT_INSTANCE, NT_ACTION_CALL, END},
                     {NT_ASSIGN, END},
                     {T_REPEAT, NT_REPEAT_STMTP, NT_STMTS, END},
                     {T_WHILE, NT_EXPR, END},
                     {T_IF, NT_EXPR, NT_STMTS, NT_ELSEIF_STMT, END},
                     {T_ELSEIF, NT_EXPR, NT_STMTS, NT_ELSEIF_STMT, END},
                     {NT_ELSE_STMT, END},
                     {T_ELSE, NT_STMTS, END},
                     {T_END, END},
                     {T_USE, NT_LIB, END},
                     {T_CHECK, NT_STMTS, END},
                     {T_DETECT, T_ID, T_IS, NT_STMTS, END},
                     {T_ALWAYS, NT_STMTS, T_END, END},
                     {ERROR},
                     {ERROR}
                     };

    char rules2[46][46] = {
                            {8,8,8,8,90,90,90,10,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,9,89,90,90,3,90,1,90,90,2,89,89,4,5,6,7,89, 0},
                            {11,11,11,11,90,90,90,11,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,11,12,90,90,11,90,11,90,90,11,12,12,11,11,11,11,90, 0},
                            {13,14,15,16,90,89,89,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,90,90,90,89,90,89,90,90,89,90,90,89,89,89,89,90, 0},
                            {89,89,89,89,17,90,90,89,89,89,89,89,89,89,89,89,89,89,89,89,89,90,90,90,90,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {89,89,89,89,18,18,90,18,90,90,90,90,90,90,90,90,90,90,90,90,90,18,18,18,18,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {89,89,89,89,19,19,90,19,89,90,90,90,90,90,90,90,90,90,90,90,90,19,19,19,19,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {21,21,21,21,90,90,90,21,21,20,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,21,21,90,90,21,90,21,90,90,21,21,21,21,21,21,21,21, 0},
                            {89,89,89,89,22,22,90,22,89,89,90,90,90,90,90,90,90,90,90,90,90,22,22,22,22,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {24,24,24,24,90,90,90,24,24,24,23,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,24,24,90,90,24,90,24,90,90,24,24,24,24,24,24,24,24, 0},
                            {89,89,89,89,25,25,90,25,89,89,89,90,90,90,90,90,90,90,90,90,90,25,25,25,25,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {28,28,28,28,90,90,90,28,28,28,28,26,27,90,90,90,90,90,90,90,90,90,90,90,90,90,28,28,90,90,28,90,28,90,90,28,28,28,28,28,28,28,28, 0},
                            {89,89,89,89,29,29,90,29,89,89,89,89,89,90,90,90,90,90,90,90,90,29,29,29,29,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {34,34,34,34,90,90,90,34,34,34,34,34,34,30,31,32,33,90,90,90,90,90,90,90,90,90,34,34,90,90,34,90,34,90,90,34,34,34,34,34,34,34,34, 0},
                            {89,89,89,89,35,35,90,35,89,89,89,89,89,89,89,89,89,90,90,90,90,35,35,35,35,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {38,38,38,38,90,90,90,38,38,38,38,38,38,38,38,38,38,36,37,90,90,90,90,90,90,90,38,38,90,90,38,90,38,90,90,38,38,38,38,38,38,38,38, 0},
                            {89,89,89,89,39,39,90,39,89,89,89,89,89,89,89,89,89,89,89,90,90,39,39,39,39,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {42,42,42,42,90,90,90,42,42,42,42,42,42,42,42,42,42,42,42,40,41,90,90,90,90,90,42,42,90,90,42,90,42,90,90,42,42,42,42,42,42,42,42, 0},
                            {89,89,89,89,43,49,90,48,89,89,89,89,89,89,89,89,89,89,89,89,89,44,45,46,47,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {89,89,89,89,90,50,90,89,89,89,89,89,89,89,89,89,89,89,89,89,89,90,90,90,90,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {89,89,89,89,90,90,90,51,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {53,53,53,53,90,90,90,53,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,52,53,53,90,90,53,90,53,90,90,53,53,53,53,53,53,53,53, 0},
                            {55,55,55,55,90,90,90,54,55,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90, 0},
                            {57,57,57,57,90,90,56,90,57,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90, 0},
                            {58,58,58,58,90,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90, 0},
                            {90,90,90,90,90,90,59,90,60,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90, 0},
                            {61,61,61,61,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,62,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {90,90,90,90,90,64,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,64,90,90,90,90,90,90,90,90,90,90,90,90,90,90, 0},
                            {66,66,66,66,90,66,90,66,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,66,90,65,90,66,90,66,90,90,66,90,90,66,66,66,66,90, 0},
                            {90,90,90,90,90,68,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,67,90,90,90,90,90,90,90,90,90,90,90,90,90, 0},
                            {89,89,89,89,90,69,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,70,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {72,72,72,72,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,71,90,90,90,90,90,90,90,90,90,90,90, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,73,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {89,89,89,89,90,90,90,74,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {89,89,89,89,90,75,90,89,90,90,90,90,76,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,75,89,90,89,90,90,89,89,89,89,89,89,89,89, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,89,90,77,90,90,89,89,89,89,89,89,89,89, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,90,90,90,89,90,89,78,79,89,90,90,89,89,89,89,90, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,89,90,89,90,90,80,89,89,89,89,89,89,89, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,82,90,90,89,90,89,90,90,89,81,82,89,89,89,89,89, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,84,90,90,89,90,89,90,90,89,89,83,89,89,89,89,89, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,89,90,89,90,90,89,89,89,85,89,89,89,89, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,89,90,89,90,90,89,89,89,89,86,89,89,89, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,87,89,89, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,88,89, 0},
                            {89,89,89,89,90,90,90,89,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,89,89,90,90,89,90,89,90,90,89,89,89,89,89,89,89,89, 0}};

    char* symbol;

    while(top(st)->el != T_$) {
        printf("---\n");

        /*
        if(tok = END_OF_FILE) {
            return 1
        }
        */

        x = top(st)->el;
        a = tok;
        //a = input[ip];
        printf("input: ");
        print_token(tok);
        //print_token(input[ip]);
        printf(" | %i \n", tok);
        print_stack(st);

        if(x <= 41 || x == T_$) {
            x -= 1;
            a -= 1;
            printf("term\n");
            printf("(x: %i, a: %i)\n", x, a);
            if(x == a) {
                int top_id = top(st)->id;
                fprintf(fp, "%i [label=\"%s\"]\n", top_id, get_token(pop(&st)->el));
                //++ip;
                tok = yylex();
            } else {
                return error();
            }
        } else {
            printf("(x: %i, a: %i)\n", x, a);
            x -= 49;
            a -= 1;
            printf("nonterm\n");
            printf("(x: %i, a: %i)\n", x, a);
            if(r[rules2[x][a]][0] != ERROR) {
                int top_id = top(st)->id;
                pop(&st);
                symbol = r[rules2[x][a]];
                count = 0;
                printf("rule (%i): ", rules2[x][a]);
                print_token(x + 49);
                printf(" -> ");

                while(*symbol) {
                    print_token(*symbol);
                    printf(" ");
                    ++count;
                    ++symbol;
                }
                printf("\n");

                --count;
                --symbol;

                for(int i = 0; i <= count; ++i) {
                    fprintf(fp, "%i -> %i\n", top_id, t_id + count - i);
                    //printf("%i ", t_id + count - i);
                }
                //printf("\n");

                while(count >= 0) {
                    push(&st, *symbol, t_id);
                    fprintf(fp, "%i [label=\"%s\"]\n", t_id, get_token(*symbol));
                    ++t_id;
                    --symbol;
                    --count;
                }

            } else {
                return error();
            }
        }
    }

    fprintf(fp, "}\n");
    fclose(fp);
}
