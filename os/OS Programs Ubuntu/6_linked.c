#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int block_number;
    struct node* next;
} Node;

Node* allocateLinked(int file_size) {
    int num_blocks = file_size / 512;
    Node* head = NULL;
    Node* current = NULL;

    int i;
    for (i = 0; i < num_blocks; i++) {
        Node* block = (Node*)malloc(sizeof(Node));
        block->block_number = i;
        block->next = NULL;

        if (head == NULL) {
            head = block;
        } else {
            current->next = block;
        }

        current = block;
    }

    return head;
}

int main() {
    int file_size = 2048; // Size of the file to be allocated
    Node* allocated_blocks;

    allocated_blocks = allocateLinked(file_size);

    if (allocated_blocks == NULL) {
        printf("File allocation failed.\n");
    } else {
        printf("File allocated successfully.\n");
        printf("Allocated blocks: ");

        Node* current = allocated_blocks;
        while (current != NULL) {
            printf("%d ", current->block_number);
            current = current->next;
        }
        printf("\n");
    }

    return 0;
}

