#ifndef BST_H
#define BST_H



typedef struct node {
    int val;
    struct node* left;
    struct node* right;
}node;


node* getNewNode(int newVal) {
    node* createdNode = (node*)malloc(1 * sizeof(node));

    createdNode->val = newVal;
    createdNode->left = NULL;
    createdNode->right = NULL;

    return createdNode;
}


node* insert(node* root, int newVal) {
    if (root == NULL) {
        root = getNewNode(newVal);
    }

    else if (newVal <= root->val) {
        root->left = insert(root->left, newVal);
    }

    else if (newVal > root->val) {
        root->right = insert(root->right, newVal);
    }

    return root;
}


bool search(node* root, int searchedVal) {
    if (root == NULL) return false;

    else if (searchedVal == root->val) return true;

    else if (searchedVal <= root->val) {
        return search(root->left, searchedVal);
    }

    else if (searchedVal > root->val) {
        return search(root->right, searchedVal);
    }
}


int getMin(node* rootPtr) {
    if (rootPtr == NULL) return -1;
    else if (rootPtr->left == NULL) return rootPtr->val;

    getMin(rootPtr->left);
}

int getMax(node* rootPtr) {
    if (rootPtr == NULL) return -1;
    else if (rootPtr->right == NULL) return rootPtr->val;

    getMax(rootPtr->right);
}


void preOrder(node* root) {
    if (root == NULL) {
        printf("-empty-\n");
        return;
    }

    printf("%d\n", root->val);

    preOrder(root->left);

    preOrder(root->right);
}

void inOrder(node* root) {
    if (root == NULL) {
        printf("-empty-\n");
        return;
    }

    inOrder(root->left);

    printf("%d\n", root->val);

    inOrder(root->right);
}

void postOrder(node* root) {
    if (root == NULL) {
        printf("-empty-\n");
        return;
    }

    postOrder(root->left);

    postOrder(root->right);

    printf("%d\n", root->val);
}


node* findNode(node* root, int key) {
    if (root == NULL) return NULL;

    while (root != NULL) {
        if (key < root->val) {
            root = root->left;
        }
        else if (key > root->val) {
            root = root->right;
        }
        else {
            return root;
        }
    }
}

node* getdMinNode(node* root) {
    if (root == NULL) return NULL;

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}


node* inOrderSuccessor(node* root, int key) {
    node* current = findNode(root, key);
    if (current == NULL) return NULL;

    // case 1: has right subtree
    if (current->right != NULL) {
        return getdMinNode(current->right);
    }
    // case 2: no right subtree
    else {
        node* successor = NULL;
        node* ancestor = root;

        while (ancestor != current) {
            if (current->val < ancestor->val) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else {
                ancestor = ancestor->right;
            }
        }

        return successor;
    }
}



#endif