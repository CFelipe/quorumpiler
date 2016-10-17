#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    fprintf(fp, "    node [fontname=\"Heuristica Regular\"];\n");
    //
    print_to_file_aux(fp, root, root);

    fprintf(fp, "}\n");
}

int main() {
    node n1 = new_node('A');
    node n2 = new_node('B');
    node n3 = new_node('C');
    node n4 = new_node('D');
    node n5 = new_node('E');
    n1.child = &n2;
    n2.right = &n3;
    n2.child = &n4;
    n4.child = &n5;

    print_tree(n1, 0);

    FILE *fp;

    if((fp = fopen("graph.dot", "w")) == 0){
        printf("Erro");
        exit(1);
    }

    print_to_file(fp, n1);
    fclose(fp);

    return 1;
}
