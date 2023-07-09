#include <stdio.h>
#include <stdlib.h>

struct item {
    int key;
    int value;
};

struct hashtable_item {
    int flag;
    /*flag = 0: tidak ada data
    flag = 1: ada data
    flag = 2: sebelumnya ada datanya */
    struct item *data;
};

struct hashtable_item *array;
int max;

/*inisialisasi hash table array*/
void init_array() {
    int i;
    for (i = 0; i < max; i++) {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

// setiap key akan meng-generate sebuah indeks yang berkorespondensi
int hashcode(int key) {
    return (key % max);
}

int size = 0; //ukuran hashtable
int maxSize;

int size_of_hashtable() {
    return size;
}

void insert(int key, int value) {
    int index = hashcode(key);
    int i = index;
    //membuat item baru untuk dimasukkan ke array hash table
    struct item *new_item = (struct item*)malloc(sizeof(struct item));
    new_item->key = key;
    new_item->value = value;
/*
    //Linear Probing
    while (array[i].flag == 1) {
        if (array[i].data->key == key) {
            //saat sudah ada key yang diberikan
            printf("\nKey already exists, hence updating its value");
            array[i].data->value = value;
            return;
        }
        i = (i + 1) % max; //maju satu langkah
        if (i == index) //jika sudah mengecek satu-satu index sampai index semula berarti penuh
        {
            printf("\nHash table is full, cannot insert any more item\n");
            return;
        }
    }
*/

    //Quadratic Probing
    int j = 1;
    while (array[i].flag == 1) {
        if (array[i].data->key == key) {
            //saat sudah ada key yang diberikan
            printf("\nKey already exists, hence updating its value");
            array[i].data->value = value;
            return;
        }
        ulang:
        i = (index % max) + (j*j);
        if (i >= max)
            i %= max;
        if (size == maxSize) 
        {
            printf("\nHash table is full, cannot insert any more item\n");
            return;
        }
        j++;
    }
    if (array[i].flag == 2) {
        printf("Index can't be used to store data anymore\nUsing another index\n");
        goto ulang;
    }
    array[i].flag = 1;
    array[i].data = new_item;
    size++;
    printf("\nKey (%d) has been inserted\n", key);
}

void remove_element(int key) {
    int index = hashcode(key);
    int i = index;

    //mencari ruang kosong di array
    while (array[i].flag != 0) {
        if (array[i].flag == 1 && array[i].data->key == key) {
            //saat data key cocok dengan key yang diberikan
            array[i].flag = 2;
            array[i].data = NULL;
            size--;
            maxSize--;
            printf("\nKey (%d) has been removed\n", key);
            return;
        }
        i = (i + 1) % max;
        if (i == index) {
            break;
        }
    }
    printf("This key does not exist\n");
}

void display() {
    int i;
    for (i = 0; i < max; i++) {
        struct item *current = (struct item*) array[i].data;
        if (current == NULL) {
            printf("\nArray (%d) has no elements\n", i);
        } else {
            printf("\nArray (%d) has elements -: \n%d(key) and %d(value)", i, current->key, current->value);
        }
    }
}

int main() {
    int choice, key, value, n;
    printf("Max: ");
    scanf("%d", &max);
    maxSize = max;
    array = (struct hashtable_item*)malloc(max * sizeof(struct hashtable_item));
    init_array();
    do {
        printf("\nImplementation of Hash Table in C with Linear Probing\n\n");
        printf("MENU-:  \n1. Inserting item in the Hashtable"
                       "\n2. Removing item from the Hashtable"
                       "\n3. Check the size of Hashtable"
                       "\n4. Display Hashtable"
                       "\n5. Exit"
                    "\n\n Please enter your choice-:");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("Inserting element in Hashtable\n");
            printf("Enter key-:\t");
            scanf("%d", &key);
            printf("Enter value-:\t");
            scanf("%d", &value);
            insert(key, value);
            break;
        case 2:
            printf("Deleting in Hashtable \n Enter the key to delete-:");
            scanf("%d", &key);
            remove_element(key);
            break;
        case 3:
            n = size_of_hashtable();
            printf("Size of Hashtable is-:%d\n", n);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Thanks for using this program!\n");
            break;
        default:
            printf("Wrong Input\n");
        }
    } while(choice != 5);
    getchar();

    return 0;
}