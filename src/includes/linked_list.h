#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>

#include "node.h"

/**
 * A succesive data structure
 * which his field is chained with another field of the same type
 */
struct LinkedList {
    node_t* init;
};

/**
 * Returns a new linked list pointer with the parameter `value` as info of firts node
 * @param value - value of the first node
 * @returns a new LinkedList struct pointer
 */
struct LinkedList* linked_list_new(union numeric value);

/**
 * @param ll - LinkedList from which will get the last node
 * @returns the last node in the LinkedList `ll`
 */
node_t* ll_get_last(struct LinkedList* ll);

/**
 * Sets a new node at the being of the linked list
 * @param ll - LinkedList where will be place the node at the first position
 * @param info - info of the new first node
 */
void ll_set_first(struct LinkedList* ll, union numeric info);

/**
 * Sets a node at the end of the linked list
 * @param ll - LinkedList where will be placed the node at the last position
 * @param info - info of the new last node
 */
void ll_set_last(struct LinkedList* ll, union numeric info);

/**
 * Delete the the last node in the list passed as parameter,
 * settings his reference to null and freeying his allocated memory
 * @param ll - LinkedList which his last node will be deleted
 */
void ll_drop_last(struct LinkedList* ll);

/**
 * Prints the info of all the nodes
 * @param ll - LinkedList to print the info of all his nodes
 */
void ll_print(struct LinkedList* ll);

/**
 * Iterates over all the node
 * and returning the amount of elements in the linked list
 * @param ll - LinkedList which loop thought counting his nodes
 * @returns the number of nodes of the LinkedList 
 */
size_t ll_count(struct LinkedList* ll);

/**
 * Increment the field `index` in all nodes that belogs to the LinkedList `ll`
 * @param ll - LinkedList where the field `index` of all node will be increased or decreased
 */
void increment_indexes(struct LinkedList* ll);

/**
 * Frees the memory allocated for a LinkedList and all his nodes freeing the memory holded by these nodes using `node_destroy`
 * @param ll - LinkedList struct which all his nodes will be freed
 */
void ll_drop(struct LinkedList* ll);

#endif // LINKED_LIST_H
