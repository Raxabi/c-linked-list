#include <stddef.h>
#include <stdlib.h>

#include "includes/node.h"

node_t* node_new(union numeric info) {
    node_t* new_node = malloc(sizeof(node_t));

    // if allocation fails
    if (new_node == NULL) {
        exit(1);
    }

    new_node->index = 0;
    new_node->info = info;
    new_node->next_node = NULL;

    return new_node;
}

node_t* node_with_next_new(union numeric info, node_t* next_node) {
    node_t* new_node = malloc(sizeof(node_t));

    // if allocation fails
    if (new_node == NULL) {
        exit(1);
    }

    new_node->index = 0;
    new_node->info = info;
    new_node->next_node = next_node;

    return new_node;
}

void node_destroy(node_t* node) {
    free(node);
}
