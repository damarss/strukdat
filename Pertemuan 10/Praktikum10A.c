#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *newNode(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

int max(int a, int b) {
    if (a > b)
        return a;
    else return b;
}

int getHeight(struct node *N) {
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalancedFactor(struct node *N) {
    if (N == NULL)
        return 0;
    return (getHeight(N->left) - getHeight(N->right));
}

struct node *rightRotate(struct node *T) {
    struct node *new_root = T->left;
    struct node *orphan = new_root->right;

    new_root->right = T;
    T->left = orphan;

    T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
    new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) + 1;

    return new_root;
}

struct node *leftRotate(struct node *T) {
    struct node *new_root = T->right;
    struct node *orphan = new_root->left;

    new_root->left = T;
    T->right = orphan;

    T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
    new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) + 1;

    return new_root;
}

struct node *insert(struct node *root, int new_data) {
    if (root == NULL) {
        return (newNode(new_data));
    }
    if (new_data < root->data) {
        root->left = insert(root->left, new_data);
    } else if (new_data > root->data) {
        root->right = insert(root->right, new_data);
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalancedFactor(root);
    if (balance > 1 && new_data < root->left->data)
        return rightRotate(root);
    if (balance < -1 && new_data > root->right->data)
        return leftRotate(root);
    if (balance < -1 && new_data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    if (balance > 1 && new_data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    return root;
}

struct node *deleteNode(struct node *root, int deletedData) {
    if (root == NULL) {
        return;
    }

    struct node *cursor;
    if (deletedData > root->data)
        root->right = deleteNode(root->right, deletedData);
    else if (deletedData < root->data)
        root->left = deleteNode(root->left, deletedData);
    else {
        //1 CHILD
        if (root->left == NULL) {
            cursor = root->right;
            free(root);
            root = cursor;
        } else if (root->right == NULL) {
            cursor = root->left;
            free(root);
            root = cursor;
        } else {    //CHILDS NODE
            cursor = root->right;
            while (cursor->left != NULL) {
                cursor = cursor->left;
            }
            root->data = cursor->data;
            root->right = deleteNode(root->right, cursor->data);
        }
    }

    if (root == NULL) {
        return root;
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalancedFactor(root);
    //left left
    if (balance > 1 && getBalancedFactor(root->left) >= 0)
        return rightRotate(root);
    //right right
    if (balance < -1 && getBalancedFactor(root->right) <= 0)
        return leftRotate(root);
    //right left
    if (balance < -1 && getBalancedFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    //left right
    if (balance > 1 && getBalancedFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    return root;
}

void displayPreorder(struct node *node)
{
    if(node == NULL)
        return;
    printf("%d ", node->data); //root
    displayPreorder(node->left); //subtree kiri
    displayPreorder(node->right); //subtree kanan
}

void displayInorder(struct node *node)
{
    if(node == NULL)
        return;
    displayInorder(node->left); //subtree kiri
    printf("%d ", node->data); //root
    displayInorder(node->right); //subtree kanan
}

void displayPostorder(struct node *node)
{
    if(node == NULL)
        return;
    displayPostorder(node->left); //subtree kiri
    displayPostorder(node->right); //subtree kanan
    printf("%d ", node->data); //root
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    printf("Pre-Order : ");
    displayPreorder(root);
    printf("\n");

    printf("In-Order  : ");
    displayInorder(root);
    printf("\n");

    printf("Post-Order: ");
    displayPostorder(root);
    printf("\n");

    printf("\nHapus node 10\n");
    root = deleteNode(root, 10);
    printf("Hapus node 6\n\n");
    root = deleteNode(root, 6);

    printf("Pre-Order : ");
    displayPreorder(root);
    printf("\n");

    printf("In-Order  : ");
    displayInorder(root);
    printf("\n");

    printf("Post-Order: ");
    displayPostorder(root);
    printf("\n");

    return 0;
}
