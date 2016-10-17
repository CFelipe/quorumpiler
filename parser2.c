#include "lex.yy.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
#define T_DOT               25
#define T_ACTION            26
#define T_END               27
#define T_RETURNS           28
#define T_COLON             29
#define T_IS                30
#define T_CLASS             31
#define T_REPEAT            32
#define T_WHILE             33
#define T_UNTIL             34
#define T_IF                35
#define T_ELSEIF            36
#define T_ELSE              37
#define T_USE               38
#define T_CHECK             39
#define T_DETECT            40
#define T_ALWAYS            41

#define T_ERROR             46
#define T_END_OF_FILE       47
#define T_BAD_COMMENT       48

#define NT_STMTS            49
#define NT_TYPE             50
#define NT_CAST_EXPR        51
#define NT_E1P              52
#define NT_E2P              53
#define NT_E3P              54
#define NT_E4P              55
#define NT_E5P              56
#define NT_E6P              57
#define NT_E7               58
#define NT_E8               59
#define NT_LIB              60
#define NT_LIBP             61
#define NT_ARGS             62
#define NT_ARGSP            63
#define NT_ARGS_DEFP        64
#define NT_ACTION_DECL      65
#define NT_ACTION_ARGS      66
#define NT_ACTION_RET       67
#define NT_INSTANCE         68
#define NT_ACTION_CALL      69
#define NT_CLASS_DECL       70
#define NT_INHERITANCE      71
#define NT_ASSIGN           72
#define NT_ID_STMT          73
#define NT_REPEAT_STMT      74
#define NT_REPEAT_STMTP     75
#define NT_IF_STMT          76
#define NT_ELSEIF_STMT      77
#define NT_ELSE_STMT        78
#define NT_USE_STMT         79
#define NT_CHECK_STMT       80
#define NT_DETECT_STMT      81
#define NT_ALWAYS_STMT      82
#define NT_STMT             83
#define NT_ARGS_DEF         84
#define NT_DECLARATION      85
#define NT_ID_STMTP         86
#define NT_E6               87
#define NT_E5               88
#define NT_E4               89
#define NT_E3               90
#define NT_E2               91
#define NT_E1               92
#define NT_EXPR             93

#define STACK_END           94

#define END                 '\0'

char* get_token(char tok) {
    switch(tok) {
        case T_COMMA: return ","; break;
        case T_COLON: return ":'"; break;
        case T_LPAREN: return "("; break;
        case T_RPAREN: return ")'"; break;
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

        case NT_STMTS:      return "STMTS"; break;
        case NT_TYPE:       return "TYPE"; break;
        case NT_CAST_EXPR:  return "CAST_EXPR"; break;
        case NT_LIB:        return "LIB"; break;
        case NT_LIBP:        return "LIB'"; break;
        case NT_ARGS:        return "ARGS"; break;
        case NT_ARGSP:        return "ARGS'"; break;
        case NT_ARGS_DEF:        return "ARGS_DEF"; break;
        case NT_ARGS_DEFP:        return "ARGS_DEF'"; break;
        /*
        case 44: return "id"; break;
        case 45: return "text"; break;
        case 46: return "error"; break;
        case 47: return "end_of_file"; break;
        case 48: return "bad comment"; break;

        case 49: return "STMT"; break;
        case 50: return "STMTS"; break;
        case 51: return "TYPE"; break;
        case 52: return "CAST_EXPR"; break;
        case 54: return "E1"; break;
        case 55: return "E1'"; break;
        case 56: return "E2"; break;
        case 57: return "E2'"; break;
        case 58: return "E"; break;
        case 60: return "E4"; break;
        case 61: return "E4'"; break;
        case 62: return "E5"; break;
        case 63: return "E5'"; break;
        case 64: return "E6"; break;
        case 65: return "E6'"; break;
        case 66: return "E7"; break;
        case 67: return "E8"; break;
        case 68: return "LIB"; break;
        case 69: return "LIB'"; break;
        case 70: return "ARGS"; break;
        case 71: return "ARGS'"; break;
        case 72: return "ARGS_DEF"; break;
        case 73: return "ARGS_DEF'"; break;
        case 74: return "DECLARATION"; break;
        case 75: return "ACTION_DECL"; break;
        case 76: return "ACTION_ARGS"; break;
        case 77: return "ACTION_RET"; break;
        case 78: return "INSTANCE"; break;
        case 79: return "ACTION_CALL"; break;
        case 80: return "CLASS_DECL"; break;
        case 81: return "INHERITANCE'"; break;
        case 82: return "ASSIGN"; break;
        case 83: return "ID_STMT'"; break;
        case 84: return "ID_STMT'"; break;
        case 85: return "REPEAT_STMT"; break;
        case 86: return "REPEAT_STMT'"; break;
        case 87: return "IF_STMT"; break;
        case 88: return "ELSEIF_STMT"; break;
        case 89: return "ELSE_STMT"; break;
        case 90: return "USE_STMT"; break;
        case 91: return "CHECK_STMT"; break;
        case 92: return "DETECT_STMT"; break;
        case 93: return "ALWAYS"; break;
        */
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

    char* tok;
    char input[] = {T_ID, T_TIMES_OP, T_LPAREN, T_ID, T_PLUS, T_ID, T_RPAREN, END};
    char a;
    char x;
    int ip = 0;
    int count = 0;
    int t_id = 0;

    stack st = init_stack();
    push(&st, STACK_END, t_id);
    ++t_id;
    push(&st, NT_EXPR, t_id);
    fprintf(fp, "%i [label=\"%s\"]\n", t_id, get_token(NT_EXPR));
    ++t_id;

    char r[90][10] = {
                     {NT_REPEAT_STMT, END},
                     {IF_STMT, END},
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
                     {T_ID, END},
                     {NT_E8, END},
                     {T_LPAREN, NT_E1, T_RPAREN, END},
                     {T_ID, NT_LIBP, END},
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

    char* rules[45][44] = {
                            {r[0],r[ 8],r[ 8],r[ 8],r[ 8],r[89],r[89],r[89],r[10],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[ 9],r[88],r[89],r[89],r[ 3],r[89],r[ 1],r[89],r[89],r[ 2],r[88],r[88],r[ 4],r[ 5],r[ 6],r[89],r[ 7],r[88]},
                            {r[0],r[11],r[11],r[11],r[11],r[89],r[89],r[89],r[11],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[11],r[12],r[89],r[89],r[11],r[89],r[11],r[89],r[89],r[11],r[12],r[12],r[11],r[11],r[11],r[89],r[11],r[89]},
                            {r[0],r[13],r[14],r[15],r[16],r[89],r[88],r[88],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[89],r[88],r[89]},
                            {r[0],r[88],r[88],r[88],r[88],r[17],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[18],r[18],r[89],r[18],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[18],r[18],r[18],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[19],r[19],r[89],r[19],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[19],r[19],r[19],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[21],r[21],r[21],r[21],r[89],r[89],r[89],r[21],r[21],r[20],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[21],r[21],r[89],r[89],r[21],r[89],r[21],r[89],r[89],r[21],r[21],r[21],r[21],r[21],r[21],r[89],r[21],r[21]},
                            {r[0],r[88],r[88],r[88],r[88],r[22],r[22],r[89],r[22],r[88],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[22],r[22],r[22],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[24],r[24],r[24],r[24],r[89],r[89],r[89],r[24],r[24],r[24],r[23],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[24],r[24],r[89],r[89],r[24],r[89],r[24],r[89],r[89],r[24],r[24],r[24],r[24],r[24],r[24],r[89],r[24],r[24]},
                            {r[0],r[88],r[88],r[88],r[88],r[25],r[25],r[89],r[25],r[88],r[88],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[25],r[25],r[25],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[28],r[28],r[28],r[28],r[89],r[89],r[89],r[28],r[28],r[28],r[28],r[26],r[27],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[28],r[28],r[89],r[89],r[28],r[89],r[28],r[89],r[89],r[28],r[28],r[28],r[28],r[28],r[28],r[89],r[28],r[28]},
                            {r[0],r[88],r[88],r[88],r[88],r[29],r[29],r[89],r[29],r[88],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[29],r[29],r[29],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[34],r[34],r[34],r[34],r[89],r[89],r[89],r[34],r[34],r[34],r[34],r[34],r[34],r[30],r[31],r[32],r[33],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[34],r[34],r[89],r[89],r[34],r[89],r[34],r[89],r[89],r[34],r[34],r[34],r[34],r[34],r[34],r[89],r[34],r[34]},
                            {r[0],r[88],r[88],r[88],r[88],r[35],r[35],r[89],r[35],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[89],r[35],r[35],r[35],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[38],r[38],r[38],r[38],r[89],r[89],r[89],r[38],r[38],r[38],r[38],r[38],r[38],r[38],r[38],r[38],r[38],r[36],r[37],r[89],r[89],r[89],r[89],r[89],r[89],r[38],r[38],r[89],r[89],r[38],r[89],r[38],r[89],r[89],r[38],r[38],r[38],r[38],r[38],r[38],r[89],r[38],r[38]},
                            {r[0],r[88],r[88],r[88],r[88],r[39],r[39],r[89],r[39],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[89],r[39],r[39],r[39],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[42],r[42],r[42],r[42],r[89],r[89],r[89],r[42],r[42],r[42],r[42],r[42],r[42],r[42],r[42],r[42],r[42],r[42],r[42],r[40],r[41],r[89],r[89],r[89],r[89],r[42],r[42],r[89],r[89],r[42],r[89],r[42],r[89],r[89],r[42],r[42],r[42],r[42],r[42],r[42],r[89],r[42],r[42]},
                            {r[0],r[88],r[88],r[88],r[88],r[43],r[48],r[89],r[47],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[44],r[45],r[46],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[49],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[50],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[52],r[52],r[52],r[52],r[89],r[89],r[89],r[52],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[51],r[52],r[52],r[89],r[89],r[52],r[89],r[52],r[89],r[89],r[52],r[52],r[52],r[52],r[52],r[52],r[89],r[52],r[52]},
                            {r[0],r[54],r[54],r[54],r[54],r[89],r[89],r[89],r[53],r[54],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89]},
                            {r[0],r[56],r[56],r[56],r[56],r[89],r[89],r[55],r[89],r[56],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89]},
                            {r[0],r[57],r[57],r[57],r[57],r[89],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89]},
                            {r[0],r[89],r[89],r[89],r[89],r[89],r[89],r[58],r[89],r[59],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89]},
                            {r[0],r[60],r[60],r[60],r[60],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[61],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[89],r[89],r[89],r[89],r[89],r[63],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[63],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89]},
                            {r[0],r[65],r[65],r[65],r[65],r[89],r[65],r[89],r[65],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[65],r[89],r[64],r[89],r[65],r[89],r[65],r[89],r[89],r[65],r[89],r[89],r[65],r[65],r[65],r[89],r[65],r[89]},
                            {r[0],r[89],r[89],r[89],r[89],r[89],r[67],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[66],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[68],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[69],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[71],r[71],r[71],r[71],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[70],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[72],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[73],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[74],r[89],r[88],r[89],r[89],r[89],r[89],r[75],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[74],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[76],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[88],r[89],r[88],r[77],r[78],r[88],r[89],r[89],r[88],r[88],r[88],r[89],r[88],r[89]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[79],r[88],r[88],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[81],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[80],r[81],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[83],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[82],r[88],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[84],r[88],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[85],r[88],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[86],r[89],r[88],r[88]},
                            {r[0],r[88],r[88],r[88],r[88],r[89],r[89],r[89],r[88],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[89],r[88],r[88],r[89],r[89],r[88],r[89],r[88],r[89],r[89],r[88],r[88],r[88],r[88],r[88],r[88],r[89],r[87],r[88]}
                        };


    char* symbol;

    while(top(st)->el != STACK_END) {
        printf("---\n");
        //tok = yylex();

        /*
        if(tok = END_OF_FILE) {
            return 1
        }
        */

        x = top(st)->el;
        a = input[ip];
        printf("input: ");
        print_token(input[ip]);
        printf("\n");
        print_stack(st);

        if(x <= 41 || x == STACK_END) {
            x -= 1;
            a -= 1;
            printf("term\n");
            printf("(x: %i, a: %i)\n", x, a);
            if(x == a) {
                int top_id = top(st)->id;
                //pop(&st);
                fprintf(fp, "%i [label=\"%s\"]\n", top_id, get_token(pop(&st)->el));
                ++ip;
            } else {
                return error();
            }
        } else {
            printf("(x: %i, a: %i)\n", x, a);
            x -= 49;
            a -= 1;
            printf("nonterm\n");
            printf("(x: %i, a: %i)\n", x, a);
            if(rules[x][a][0] != ERROR) {
                int top_id = top(st)->id;
                pop(&st);
                symbol = rules[x][a];
                count = 0;
                printf("rule: ");
                print_token(x + 1);
                printf(" -> ");

                while(*symbol) {
                    print_token(*symbol);
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
