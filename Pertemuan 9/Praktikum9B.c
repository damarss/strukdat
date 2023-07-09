#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char nama[30];
    struct node *left;
    struct node *right;
};

struct node *newNode(char nama[30])
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    strcpy(node->nama, nama);
    node->left = NULL;
    node->right = NULL;
    return node;
}

void displayPreorder(struct node* node)
{
    if(node == NULL)
        return;
    printf("%s ", node->nama); //root
    displayPreorder(node->left); //subtree kiri
    displayPreorder(node->right); //subtree kanan
}

void displayInorder(struct node* node)
{
    if(node == NULL)
        return;
    displayInorder(node->left); //subtree kiri
    printf("%s ", node->nama); //root
    displayInorder(node->right); //subtree kanan
}

void displayPostorder(struct node* node)
{
    if(node == NULL)
        return;
    displayPostorder(node->left); //subtree kiri
    displayPostorder(node->right); //subtree kanan
    printf("%s ", node->nama); //root
}

struct node* insert(struct node* root, char nama[30])
{
    if(root == NULL)
    {
        root = newNode(nama);
    }
    else
    {
        int is_left = 0;
        struct node* cursor = root;
        struct node* prev = NULL;
        while(cursor != NULL)
        {
            prev = cursor;
            if(strcmp(nama, cursor->nama) < 0)
            {
                is_left = 1;
                cursor = cursor->left;
            }
                else if(strcmp(nama, cursor->nama) > 0)
            {
                is_left = 0;
                cursor = cursor->right;
            }
        }
        if(is_left == 1)
            prev->left = newNode(nama);
        else
            prev->right = newNode(nama);
    }
    return root;
}

void search_node(struct node* root, char nama[30])
{
    struct node* cursor = root;
    while(cursor->nama != nama){
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

struct node *delete_node(struct node *root, char nama[30]) {
    if (root == NULL) {
        return;
    }

    struct node *cursor;
    if (strcmp(nama, root->nama) > 0)
        root->right = delete_node(root->right, nama);
    else if (strcmp(nama, root->nama) < 0)
        root->left = delete_node(root->left, nama);
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
            root->right = delete_node(root->right, cursor->nama);
        }
    } 

    return root;
}

int main() {
    struct node* root = newNode("Windah");
    root = insert(root, "Kurniawan");
    root = insert(root, "Ilham");
    root = insert(root, "Mega");
    root = insert(root, "Lala");
    root = insert(root, "Deni");
    root = insert(root, "Suci");
    root = insert(root, "Zerlin");

    printf("Pre-Order: ");
    displayPreorder(root);
    printf("\n");

    printf("In-Order: ");
    displayInorder(root);
    printf("\n");

    printf("Post-Order: ");
    displayPostorder(root);
    printf("\n");

    printf("\n\nHapus Ilham\n");
    delete_node(root, "Ilham");

    printf("Pre-Order: ");
    displayPreorder(root);
    printf("\n");

    printf("In-Order: ");
    displayInorder(root);
    printf("\n");

    printf("Post-Order: ");
    displayPostorder(root);
    printf("\n");


    return 0;
}
