/* Read about linked list:
 * https://en.wikipedia.org/wiki/Linked_list#:~:text=In%20computer%20science%2C%20a%20linked,which%20together%20represent%20a%20sequence.
 */


#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H



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


void insert_at_beginning(int val, node** head_p) {
    node* created_node = (node*)malloc(1 * sizeof(node));
    created_node->value = val;
    created_node->next = *head_p;
    *head_p = created_node;
}


void insert_at_index(int val, int index, node** head_p) {

    node* created_node = (node*)malloc(1 * sizeof(node));
    created_node->value = val;

    if (*head_p == NULL || index == 0) {
        created_node->next = *head_p;
        *head_p = created_node;
        return;
    }

    node* prev_node = *head_p;

    for (int i = 0; i < index - 1; i++) {
        prev_node = prev_node->next;
    }

    created_node->next = prev_node->next;
    prev_node->next = created_node;

}


// this function doesn't work with the last node of a linked list
void delete_node(struct node* node_p) {

    node* following_node = node_p->next;

    if (following_node != NULL) {
        node_p->value = following_node->value;
        node_p->next = following_node->next;
    }
    else {
        node_p = NULL;
        free(node_p);
    }
    free(following_node);
}

void delete_node_(node* node_p) {
    /*
     * after using this function the user should
     * link the previous node with the next node manualy
     */

    if (node_p == NULL) return;

    free(node_p);
}

void delete_node_at_index(int index, node** head_p) {
    node* prev_node = *head_p;

    if (index == 0) {
        *head_p = (*head_p)->next;
        free(prev_node);
        return;
    }

    for (int i = 0; i < index - 1; i++) {
        prev_node = prev_node->next;
    }

    node* following_node = prev_node->next;

    prev_node->next = following_node->next;

    free(following_node);
}

void delete_node_and_link_next(node* node_p, node* prev, node* next) {
    if (node_p == NULL) {
        prev->next = next;
        return;
    }

    free(node_p);
    prev->next = next;
}


node* reverse_list(node* head) {
    if (head == NULL || head->next == NULL) return head;

    node* prev, * current, * following;

    prev = NULL;
    current = head;

    while (current != NULL) {
        following = current->next;

        current->next = prev;

        prev = current;
        current = following;
    }
    head = prev;
    return head;
}



void print_linked_list(node* head_node) {

    while (head_node != NULL) {
        printf("%d, ", head_node->value);
        head_node = head_node->next;
    }
    printf("\n");
}

void print_linked_list_rec(node* head) {
    if (head == NULL) {
        printf("\n");
        return;
    }

    printf("%d, ", head->value);
    print_linked_list_rec(head->next);
}

void print_reversed_linked_list(node* head) {
    if (head == NULL) return;

    print_reversed_linked_list(head->next);
    printf("%d, ", head->value);
}



#endif