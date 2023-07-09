#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void displayPreorder(struct node* node)
{
    if(node == NULL)
        return;
    printf("%d ", node->data); //root
    displayPreorder(node->left); //subtree kiri
    displayPreorder(node->right); //subtree kanan
}

void displayInorder(struct node* node)
{
    if(node == NULL)
        return;
    displayInorder(node->left); //subtree kiri
    printf("%d ", node->data); //root
    displayInorder(node->right); //subtree kanan
}

void displayPostorder(struct node* node)
{
    if(node == NULL)
        return;
    displayPostorder(node->left); //subtree kiri
    displayPostorder(node->right); //subtree kanan
    printf("%d ", node->data); //root
}

struct node* insert(struct node* root, int newData)
{
    if(root == NULL)
    {
        root = newNode(newData);
    }
    else
    {
        int is_left = 0;
        struct node* cursor = root;
        struct node* prev = NULL;
        while(cursor != NULL)
        {
            prev = cursor;
            if(newData < cursor->data)
            {
                is_left = 1;
                cursor = cursor->left;
            }
                else if(newData > cursor->data)
            {
                is_left = 0;
                cursor = cursor->right;
            }
        }
        if(is_left == 1)
            prev->left = newNode(newData);
        else
            prev->right = newNode(newData);
    }
    return root;
}

void search_node(struct node* root, int data)
{
    struct node* cursor = root;
    while(cursor->data != data){
        if(cursor != NULL){
            if(data > cursor->data){
            cursor = cursor->right;
            }
            else {
            cursor = cursor->left;
            }
            if(cursor == NULL){
                printf("\nNode %d tidak ditemukan", data);
                return;
            }
        }
    }

    printf("\nNode %d ditemukan", data);
    return;
}

struct node *delete_node(struct node *root, int deletedData) {
    if (root == NULL) {
        return;
    }

    struct node *cursor;
    if (deletedData > root->data)
        root->right = delete_node(root->right, deletedData);
    else if (deletedData < root->data)
        root->left = delete_node(root->left, deletedData);
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
            root->right = delete_node(root->right, cursor->data);
        }
    }

    return root;
}

int main() {
    struct node* root = newNode(8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 13);

    printf("Pre-Order: ");
    displayPreorder(root);
    printf("\n");

    printf("In-Order: ");
    displayInorder(root);
    printf("\n");

    printf("Post-Order: ");
    displayPostorder(root);
    printf("\n");

    search_node(root, 4);
    search_node(root, 13);
    search_node(root, 6);

    printf("\n\nHapus node 13 dan 3\n\n");
    root = delete_node(root, 13);
    root = delete_node(root, 3);

    printf("Pre-Order: ");
    displayPreorder(root);
    printf("\n");

    printf("In-Order: ");
    displayInorder(root);
    printf("\n");

    printf("Post-Order: ");
    displayPostorder(root);
    printf("\n");


    search_node(root, 4);
    search_node(root, 13);
    search_node(root, 6);

    return 0;
}
