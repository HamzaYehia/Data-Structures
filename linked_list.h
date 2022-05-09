/* Read about linked list:
 * https://en.wikipedia.org/wiki/Linked_list#:~:text=In%20computer%20science%2C%20a%20linked,which%20together%20represent%20a%20sequence.
 */


#ifndef LINKED_LIST_H
#define LINKED_LIST_H



typedef struct node {
    int value;          // data part
    struct node* next; // address part
} node;


node* create_new_node(int val) {
    node* created_node = (node*)malloc(1 * sizeof(node));

    if (created_node == NULL) {
        printf("Creating new node  with value (%d) failed\n", val);
        return NULL;
    }

    created_node->value = val;
    created_node->next = NULL;
    return created_node;
}

void insert_at_beginning(int value, node** head) {
    node* temp = (node*)malloc(1 * sizeof(node));
    temp->value = value;
    temp->next = *head;
    *head = temp;
}

void delete_node(node* node) {
    /*
     * after using this function the user should
     * link the previous node with the next node manualy
     */

    if (node == NULL) return;

    free(node);
}

void delete_node_and_link_next(node* node_p, node* prev, node* next) {
    if (node_p == NULL) return;

    free(node_p);
    prev->next = next;
}

void print_linked_list(node* head_node) {

    while (head_node != NULL) {
        printf("%d, ", head_node->value);
        head_node = head_node->next;
    }
    printf("\n");
}


#endif