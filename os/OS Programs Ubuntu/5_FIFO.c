#include <stdio.h>

#define NUM_FRAMES 3
#define NUM_PAGES 10

int main() {
    int frames[NUM_FRAMES];
    int pages[NUM_PAGES] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3};
    int page_faults = 0;
    int frame_index = 0;
    int i, j;

    for (i = 0; i < NUM_FRAMES; i++) {
        frames[i] = -1; // Initialize frames to -1 (indicating empty frame)
    }

    for (i = 0; i < NUM_PAGES; i++) {
        int page = pages[i];
        int found = 0;

        // Check if the page is already in one of the frames
        for (j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        // Page fault occurred
        if (!found) {
            frames[frame_index] = page;
            frame_index = (frame_index + 1) % NUM_FRAMES;
            page_faults++;
        }

        // Print current state of frames
        printf("Page %d: ", page);
        for (j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);

    return 0;
}

