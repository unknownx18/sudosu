#include <stdio.h>

#define NUM_FRAMES 3
#define NUM_PAGES 10

int main() {
    int frames[NUM_FRAMES];
    int pages[NUM_PAGES] = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3};
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
            int optimal_frame_index = 0;
            int optimal_page_index = -1;

            // Find the frame that will not be used for the longest time
            for (int j = 0; j < NUM_FRAMES; j++) {
                int k;
                for (k = i + 1; k < NUM_PAGES; k++) {
                    if (frames[j] == pages[k]) {
                        if (k > optimal_page_index) {
                            optimal_frame_index = j;
                            optimal_page_index = k;
                        }
                        break;
                    }
                }
                // If the page will not be used in the future, select that frame
                if (k == NUM_PAGES) {
                    optimal_frame_index = j;
                    break;
                }
            }

            frames[optimal_frame_index] = page;
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

