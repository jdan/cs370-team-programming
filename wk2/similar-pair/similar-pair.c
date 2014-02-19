#include <stdio.h>

/* Linked list of integers */
typedef struct s_llnode {
    int value;
    struct s_llnode *next;
} llnode_t;

/* Returns a new linked list from a given int and next */
llnode_t *new_node(int value, llnode_t *next) {
    llnode_t *ret = (llnode_t*)malloc(sizeof(llnode_t));

    ret->value = value;
    ret->next = next;

    return ret;
}

int main(int argc, char **argv) {
    int i, n, T;

    /**
     * An array of nodes representing the tree
     * i.e. nodes[3] will point to a linked list of node 3's children
     * nodes[0] is the root
     */
    llnode_t **nodes;

    scanf("%d %d\n", &n, &T);

    nodes = (llnode_t**)malloc(n * sizeof(llnode_t*));
}
