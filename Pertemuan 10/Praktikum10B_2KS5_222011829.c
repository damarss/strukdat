#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char nama[30];
    struct node *left;
    struct node *right;
    int height;
};

struct node *newNode(char nama[30]) {
    struct node *node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->nama, nama);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
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

struct node *insert(struct node *root, char new_nama[30]) {
    if (root == NULL) {
        return (newNode(new_nama));
    }
    if (strcmp(new_nama, root->nama) < 0) {
        root->left = insert(root->left, new_nama);
    } else if (strcmp(new_nama, root->nama) > 0) {
        root->right = insert(root->right, new_nama);
    }
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalancedFactor(root);
    if (balance > 1 && strcmp(new_nama, root->left->nama) < 0)
        return rightRotate(root);
    if (balance < -1 && strcmp(new_nama, root->right->nama) > 0)
        return leftRotate(root);
    if (balance < -1 && strcmp(new_nama, root->right->nama) < 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    if (balance > 1 && strcmp(new_nama, root->left->nama) > 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    return root;
}

void search_node(struct node* root, char nama[30]) {
    struct node* cursor = root;
    while(strcmp(cursor->nama, nama) != 0){
        if(cursor != NULL){
            if(strcmp(nama, cursor->nama) > 0){
                cursor = cursor->right;
            }
            else {
                cursor = cursor->left;
            }
            if(cursor == NULL){
                printf("\nNode %s tidak ditemukan", nama);
                return;
            }
        }
    }

    printf("\nNode %s ditemukan", nama);
    return;
}

struct node *deleteNode(struct node *root, char deletedData[30]) {
    if (root == NULL) {
        return root;
    }

    struct node *cursor;
    if (strcmp(deletedData, root->nama) > 0)
        root->right = deleteNode(root->right, deletedData);
    else if (strcmp(deletedData, root->nama) < 0)
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
            strcpy(root->nama, cursor->nama);
            root->right = deleteNode(root->right, cursor->nama);
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

void displayPreorder(struct node* root) {
    if(root == NULL)
        return;
    printf("%s ", root->nama); //root
    displayPreorder(root->left); //subtree kiri
    displayPreorder(root->right); //subtree kanan
}

void displayInorder(struct node* root) {
    if(root == NULL)
        return;
    displayInorder(root->left); //subtree kiri
    printf("%s ", root->nama); //root
    displayInorder(root->right); //subtree kanan
}

void displayPostorder(struct node* root) {
    if(root == NULL)
        return;
    displayPostorder(root->left); //subtree kiri
    displayPostorder(root->right); //subtree kanan
    printf("%s ", root->nama); //root
}

void displayCurrentLevel(struct node* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%s ", root->nama);
    else if (level > 1) {
        displayCurrentLevel(root->left, level - 1);
        displayCurrentLevel(root->right, level - 1);
    }
}

void displayLevelOrder(struct node* root) {
    int h = getHeight(root);
    for (int i = 1; i <= h; i++)
        displayCurrentLevel(root, i);
}


int main() {
    struct node* root = NULL;
    root = insert(root, "Jamal");
    root = insert(root, "Kurniawan");
    root = insert(root, "Ilham");
    root = insert(root, "Mega");
    root = insert(root, "Lala");
    root = insert(root, "Deddy");
    root = insert(root, "Suci");
    root = insert(root, "Windah");
    root = insert(root, "Corbuzier");

    printf("Pre-Order: ");
    displayPreorder(root);
    printf("\n");

    printf("In-Order: ");
    displayInorder(root);
    printf("\n");

    printf("Post-Order: ");
    displayPostorder(root);
    printf("\n");

    printf("Level-Order: ");
    displayLevelOrder(root);
    printf("\n");

    printf("\nCari Lala");
    search_node(root, "Lala");

    printf("\n\nHapus Lala\n");
    deleteNode(root, "Lala");
    printf("Node Lala sudah dihapus\n\n");

    printf("Pre-Order: ");
    displayPreorder(root);
    printf("\n");

    printf("In-Order: ");
    displayInorder(root);
    printf("\n");

    printf("Post-Order: ");
    displayPostorder(root);
    printf("\n");
    
    printf("Level-Order: ");
    displayLevelOrder(root);
    printf("\n"); 

    return 0;
}
