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


void printBST(node* root) {
    if (root == NULL) {
        printf("-empty-\n");
        return;
    }
    else {
        printf("%d\n", root->val);
    }

    printBST(root->left);
    
    printBST(root->right);
}



#endif