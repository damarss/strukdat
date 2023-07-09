#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* newNode(int data)
{
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root)
{
    return !root;
}

void push(struct StackNode* *root, int data)
{
    struct StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

int pop(struct StackNode** root)
{
    if (isEmpty(*root)) {
      return INT_MIN;
    }
    struct StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(struct StackNode* root)
{
    if (isEmpty(root)) {
      return INT_MIN;
    }
    return root->data;
}

void toBinary(int n) {
    struct StackNode* stack = NULL;
    unsigned int value = n;
    while (value > 0) {
        push(&stack, value % 2);
        value /= 2;
    }
    while (!isEmpty(stack)) {
        printf("%d", pop(&stack));
    }
    printf("\n");
}

void toOctal(int n) {
    struct StackNode* stack = NULL;
    while (n > 0) {
      push(&stack, n % 8);
      n = n / 8;
    }
    while (!isEmpty(stack)) {
      printf("%d", pop(&stack));
    }
    printf("\n");
}

int main()
{
    int choose, number;
    printf("Enter the number: ");
    scanf("%d", &number);
    printf("Choose the base: \n1. Binary\n2. Octal\n");
    scanf("%d", &choose);
    switch (choose) {
      case 1:
        toBinary(number);
        break;
      case 2:
        toOctal(number);
        break;
      default:
        printf("Invalid choice\n");
    }
    return 0;
}


