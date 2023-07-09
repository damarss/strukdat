#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
}

struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        root = newNode(data);
    } else {
        int isLeft = 0;
        struct node *cursor = root;
        struct node *prev = NULL;
        while (cursor != NULL) {
            prev = cursor;
            if (data < cursor->data) {
                isLeft = 1;
                cursor = cursor->left;
            } else if (data > cursor->data) {
                isLeft = 0;
                cursor = cursor->right;
            }
        }
        if (isLeft == 1) {
            prev->left = newNode(data);
        } else {
            prev->right = newNode(data);
        }
    }
    return root;
}

void search(struct node *root, int data) {
    struct node *cursor = root;
    while (cursor->data != data) {
        if (data < cursor->data) {
            cursor = cursor->left;
        } else if (data > cursor->data) {
            cursor = cursor->right;
        }
        if (cursor == NULL) {
            printf("Data %d tidak ditemukan\n", data);
            return;
        }
    }
    printf("Data %d ditemukan\n", data);
}

struct node *delete(struct node *root, int data) {
    if (root == NULL) {
        return NULL;
    }
    struct node *cursor = root;
    if (data < cursor->data) {
        root->left = delete(root->left, data);
    } else if (data > cursor->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL) {
            cursor = root->right;
            free(root);
            root = cursor;
        } else if (root->right == NULL) {
            cursor = root->left;
            free(root);
            root = cursor;
        } else {
            cursor = root->right;
            while (cursor->left != NULL) {
                cursor = cursor->left;
            }
            root->data = cursor->data;
            root->right = delete(root->right, cursor->data);
        }
    }
    return root;
}

void displayPreOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    displayPreOrder(root->left);
    displayPreOrder(root->right);
}

void displayInOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    displayInOrder(root->left);
    printf("%d ", root->data);
    displayInOrder(root->right);
}

void displayPostOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    displayPostOrder(root->left);
    displayPostOrder(root->right);
    printf("%d ", root->data);
}

void main() {
    struct node *root = newNode(5);
    root = insert(root,2);
    root = insert(root,3);
    root = insert(root,7);
    root = insert(root,1);
    root = delete(root,1);
    displayPreOrder(root);
    printf("\n");
    displayInOrder(root);
    printf("\n");
    displayPostOrder(root);
    search(root,11);
}