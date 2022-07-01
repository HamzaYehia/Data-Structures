#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST



typedef struct node {
    struct node* prev;
    struct node* next;
    int val;
} node;


node* create_new_node(int val, node* prev, node* next) {
    node* created_node = (node*)malloc(1 * sizeof(node));

    created_node->val = val;

    created_node->prev = prev;
    created_node->next = next;

    return created_node;
}

void insert_at_beginning(int val, node** head) {
    node* created_node = create_new_node(val, NULL, *head);
    (*head)->prev = created_node;
    *head = created_node;
}


void insert_at_end(int val, node* head) {
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = create_new_node(val, head, NULL);
}


void delete_node(node* node_p, node** prev, node** next) {
    (*prev)->next = *next;
    (*next)->prev = *prev;
    free(node_p);
}

void print_list(node* head) {
    while (head != NULL) {
        printf("%d  ", head->val);
        head = head->next;
    }
    printf("\n");
}


void print_reversed_list(node* head) {
    while (head->next != NULL) {
        head = head->next;
    }

    while (head != NULL) {
        printf("%d  ", head->val);
        head = head->prev;
    }
    printf("\n");
}


node* reverse_list(node* head) {
    while (head->next != NULL) {
        head = head->next;
    }

    node* new_head = head;

    node* prev = head->prev;
    node* next = head->next;

    while (prev != NULL) {
        prev = head->prev;
        next = head->next;

        head->next = prev;
        head->prev = next;

        head = prev;
    }

    return new_head;
}



#endif