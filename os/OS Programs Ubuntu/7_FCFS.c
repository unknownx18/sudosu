#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, i, seek_time = 0;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int requests[n];

    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Calculate total seek time
    for (i = 0; i < n; i++) {
        seek_time += abs(requests[i] - head);
        head = requests[i];
    }

    printf("Total Seek Time: %d\n", seek_time);

    return 0;
}

