#include <stdio.h>
#define MAX 100

int queue[MAX];
int itemCount = 0;

void enqueue(int data) {
    if (itemCount == MAX) {
        printf("Queue penuh\n");
    } else {
        if (itemCount == 0) {
            queue[itemCount] = data;
        } else {
            int i;
            for (i = itemCount - 1; i >= 0; i--) {
                if (data < queue[i]) {
                    queue[i+1] = queue[i];
                } else {
                    break;
                }
            }
            queue[i+1] = data;
        }
        itemCount++;
    }
}

void dequeue() {
    if (itemCount == 0) {
        printf("Queue kosong\n");
        return;
    }
    for (int i = 0; i < itemCount; i++) {
        queue[i] = queue[i+1];
    }
    itemCount--;
}

void display() {
    if (itemCount == 0) {
        printf("Queue kosong\n");
        return;
    }
    printf("Isi Queue: ");
    for (int i = 0; i < itemCount; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void main() {
    enqueue(2);
    enqueue(1);
    enqueue(0);
    enqueue(-2);
    display();
    dequeue();
    display();
}