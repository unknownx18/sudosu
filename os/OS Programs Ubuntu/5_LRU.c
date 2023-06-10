#include <stdio.h>

#define NUM_FRAMES 3
#define NUM_PAGES 10

int main() {
    int frames[NUM_FRAMES];
    int pages[NUM_PAGES] = {1, 2, 3, 1, 2, 4, 5, 1, 2, 3};
    int page_faults = 0;

    for (int i = 0; i < NUM_FRAMES; i++) {
        frames[i] = -1; // Initialize frames to -1 (indicating an empty frame)
    }

    for (int i = 0; i < NUM_PAGES; i++) {
        int page = pages[i];
        int page_found = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < NUM_FRAMES; j++) {
            if (frames[j] == page) {
                page_found = 1;
                break;
            }
        }

        // Page fault occurred
        if (!page_found) {
            int lru_frame_index = 0;
            int lru_page_index = i;

            // Find the least recently used frame
            for (int j = 0; j < NUM_FRAMES; j++) {
                int k;
                for (k = i - 1; k >= 0; k--) {
                    if (frames[j] == pages[k]) {
                        if (k < lru_page_index) {
                            lru_frame_index = j;
                            lru_page_index = k;
                        }
                        break;
                    }
                }

                // If a page in the frame is not found in the remaining page sequence
                if (k == -1) {
                    lru_frame_index = j;
                    break;
                }
            }

            frames[lru_frame_index] = page;
            page_faults++;
        }

        // Print the current state of frames
        printf("Page %d: ", page);
        for (int j = 0; j < NUM_FRAMES; j++) {
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

