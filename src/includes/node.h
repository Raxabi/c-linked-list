#ifndef NODE_H
#define NODE_H

#include <stdint.h>

union numeric {
    uint8_t u8;
    int8_t i8;

    uint16_t u16;
    int16_t i16;

    uint32_t u32;
    int32_t i32;

    uint64_t u64;
    int64_t i64;
};

/**
 * Data type which stores a value and his chained to another element of the same type
 */
typedef struct node {
    struct node* next_node;
    union numeric info;
    uint32_t index;
} node_t; 

/**
 * Returns a new node pointer
 * @param info - info of the new node
 * @returns A new node pointer which has `info` as value of his `info` field
 */
node_t* node_new(union numeric info);

/**
 * Returns a new node pointer but filling his `next_node` field.
 * See `node_new` too
 * @param info - info of the new node
 * @param next_node - sets the next node for the next node
 * @returns A new node pointer which his `next_node` field is `next_node`
 */
node_t* node_with_next_new(union numeric info, node_t* next_node);

/**
 * Frees the memory allocated for a node
 * @param node - node to free the memory
 */
void node_destroy(node_t* node);

#endif // NODE_H
