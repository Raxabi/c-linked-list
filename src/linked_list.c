#include <stdio.h>
#include <stdlib.h>

#include "includes/node.h"
#include "includes/linked_list.h"

struct LinkedList* linked_list_new(union numeric value) {
    struct LinkedList* ll = malloc(sizeof(struct LinkedList));

    // if allocation fails
    if (ll == NULL) {
        exit(1);
    }

    ll->init = node_new(value);

    return ll;
}

node_t* ll_get_last(struct LinkedList* ll) {
    node_t* node = ll->init;

    while (node->next_node != NULL)
        node = node->next_node;

    return node;
}

void ll_set_first(struct LinkedList* ll, union numeric info) {
    // fnode represents the (f)irst node
    node_t* fnode = ll->init;
    node_t* new_node = node_with_next_new(info, fnode);

    ll->init = new_node;
}

void ll_set_last(struct LinkedList* ll, union numeric info) {
    node_t* new_node = node_new(info);
    node_t* last_node = ll_get_last(ll);

    last_node->next_node = new_node;
}

void ll_drop_last(struct LinkedList* ll) {
    node_t* fnode = ll->init;

    // gets the penultimate node
    while (fnode->next_node->next_node != NULL)
        fnode = fnode->next_node;

    printf("penultimate: %d\n", fnode->info.i32);

    // frees memory holded by last node
    node_destroy(fnode->next_node);
    fnode->next_node = NULL;
}

void ll_print(struct LinkedList* ll) {
    node_t* node = ll->init;

    printf("LinkedList -> ");
    while (node != NULL) {
        printf("%d -> ", node->info.i32);

        if (node->next_node == NULL)
            printf("NULL\n");

        node = node->next_node;
    }
}

size_t ll_count(struct LinkedList* ll) {
    size_t count = 0;
    node_t* node = ll->init;

    while (node != NULL) {
        node = node->next_node;
        count++;
    }
    
    return count;
}

void ll_drop(struct LinkedList* ll) {
    node_t* sup = ll->init;
    node_t* node_to_drop = NULL;
    while (sup != NULL) {
        node_to_drop = sup;
        sup = sup->next_node;
        node_destroy(node_to_drop);
    }

    // finally, we free the linked list pointer
    free(ll);
}