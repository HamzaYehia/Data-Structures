/* Read about linked list:
 * https://en.wikipedia.org/wiki/Linked_list#:~:text=In%20computer%20science%2C%20a%20linked,which%20together%20represent%20a%20sequence.
 */


#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node* next;
    int value;
} node_t;

node_t* head;   // keeps track of the first Node


node_t* createNewNode(int newNode) {
    /* After using this function
     * you should link the previous Node
     * to the created Node
     */

    node_t* createdNode = (node_t*)malloc(sizeof(node_t));
    createdNode->value = newNode;
    createdNode->next = NULL;
    return createdNode;
}

void deleteNode(node_t* node) {
    /* After using this function you shoud link the previous Node to
     * another Node, or do:
     * previousNode->next = NULL;
     */

    free(node);

}

void printLinkedList(node_t* headNode) {
    while (headNode != NULL) {
        printf("%d,", headNode->value);
        headNode = headNode->next;
    }
    printf("\n");
}


#endif