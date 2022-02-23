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

node_t* createNewNode(int newNode) {
    /* returns the address of the new node */

    node_t* createdNode = (node_t*)malloc(sizeof(node_t));
    createdNode->value = newNode;
    createdNode->next = NULL;
    return createdNode;
}

void removeNode(node_t* node) {
    /* After using this function you shoud link previous node to
     * another node, or do:
     * previousNode->next = NULL;
     */

    free(node);

}

void printLinkedList(node_t* head)
{
    node_t* temp = head;
    while (temp != NULL)
    {
        printf("%d,", temp->value);
        temp = temp->next;
    }
    printf("\n");
}


#endif