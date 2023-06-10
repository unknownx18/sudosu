#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

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

    qsort(requests, n, sizeof(int), compare);

    int head_index = 0;
    for (i = 0; i < n; i++) {
        if (requests[i] >= head) {
            head_index = i;
            break;
        }
    }

    for (i = head_index; i < n; i++) {
        seek_time += abs(requests[i] - head);
        head = requests[i];
    }
    seek_time += abs(head - requests[0]);
    head = requests[0];

    for (i = 1; i < head_index; i++) {
        seek_time += abs(requests[i] - head);
        head = requests[i];
    }

    printf("Total Seek Time: %d\n", seek_time);

    return 0;
}

