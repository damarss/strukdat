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

    return new_node;
}

struct node *insertNode(struct node *root, int data) {
    if (root == NULL) {
        root = newNode(data);
    } else {
        int is_left = 0;
        struct node *cursor = root;
        struct node *prev = NULL;
        while (cursor != NULL) {
            prev = cursor;
            if (data < cursor->data) {
                is_left = 1;
                cursor = cursor->left;
            } else if (data > cursor->data) {
                is_left = 0;
                cursor = cursor->right;
            }
        }

        if (is_left == 1) {
            prev->left = newNode(data);
        } else {
            prev->right = newNode(data);
        }
    }
    return root;
}

void searchNode(struct node *root, int data) {
    struct node *cursor = root;

    while (cursor->data != data) {
        if (cursor != NULL) {
            if (data > cursor->data) {
                cursor = cursor->right;
            } else {
                cursor = cursor->left;
            }
        }
        if (cursor == NULL) {
            printf("\nNode %d tidak ditemukan", data);
            return;
        }
    }
    printf("\nNode %d ditemukan", data);
    return;
}

void displayPreOrder(struct node *node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->data);
    displayPreOrder(node->left);
    displayPreOrder(node->right);
}

void displayInOrder(struct node *node) {
    if (node == NULL) {
        return;
    }
    displayInOrder(node->left);
    printf("%d ", node->data);
    displayInOrder(node->right);
}

void displayPostOrder (struct node *node) {
    if (node == NULL) {
        return;
    }
    displayPostOrder(node->left);
    displayPostOrder(node->right);
    printf("%d ", node->data);
}

int main() {
    struct node *root = newNode(8);

    root->left = newNode(3);
    root->left->right = newNode(1);
    root->left->left = newNode(6);
    root->left->right->right = newNode(4);
    root->left->right->left = newNode(7);

    root->right = newNode(10);
    root->right->left = newNode(14);
    root->right->left->right = newNode(13);

    printf("Pre-Order: ");
    displayPreOrder(root);
    printf("\n");

    printf("In-Order: ");
    displayInOrder(root);
    printf("\n");

    printf("Post-Order: ");
    displayPostOrder(root);
    printf("\n");

    struct node *root_baru = newNode(8);
    root_baru = insertNode(root_baru, 3);
    root_baru = insertNode(root_baru, 1);
    root_baru = insertNode(root_baru, 6);
    root_baru = insertNode(root_baru, 4);
    root_baru = insertNode(root_baru, 7);
    root_baru = insertNode(root_baru, 10);
    root_baru = insertNode(root_baru, 14);
    root_baru = insertNode(root_baru, 13);

    printf("\n\n\n");
    printf("Pre-Order: ");
    displayPreOrder(root_baru);
    printf("\n");

    printf("In-Order: ");
    displayInOrder(root_baru);
    printf("\n");

    printf("Post-Order: ");
    displayPostOrder(root_baru);
    printf("\n");

    searchNode(root_baru, 18);

    return 0;
}
