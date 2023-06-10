#include <stdio.h>

#define MAX_BLOCKS 100

int main() {
    int file_size, num_blocks;
    int blocks[MAX_BLOCKS];
    int index_block[MAX_BLOCKS];

    // Read file size and number of blocks
    printf("Enter the file size: ");
    scanf("%d", &file_size);

    printf("Enter the number of blocks: ");
    scanf("%d", &num_blocks);

    // Read block numbers
    printf("Enter the block numbers: ");
    for (int i = 0; i < num_blocks; i++) {
        scanf("%d", &blocks[i]);
    }

    // Read index block
    printf("Enter the index block: ");
    for (int i = 0; i < num_blocks; i++) {
        scanf("%d", &index_block[i]);
    }

    // Check if the file can be allocated
    int allocated_size = 0;
    for (int i = 0; i < num_blocks; i++) {
        allocated_size += blocks[i];
    }

    if (allocated_size >= file_size) {
        printf("File allocated successfully.\n");
        printf("Allocated Blocks: ");
        for (int i = 0; i < num_blocks; i++) {
            printf("%d ", blocks[i]);
        }
        printf("\n");
        printf("Index Block: ");
        for (int i = 0; i < num_blocks; i++) {
            printf("%d ", index_block[i]);
        }
        printf("\n");
    } else {
        printf("Insufficient space to allocate the file.\n");
    }

    return 0;
}

