#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b) {
    return (a > b) ? (a - b) : (b - a);
}

int find_shortest_distance(int* requests, int n, int head, int* visited) {
    int min_distance = abs_diff(requests[0], head);
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (!visited[i] && abs_diff(requests[i], head) < min_distance) {
            min_distance = abs_diff(requests[i], head);
            index = i;
        }
    }

    return index;
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

    int visited[n];
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (i = 0; i < n; i++) {
        int shortest_index = find_shortest_distance(requests, n, head, visited);
        seek_time += abs_diff(requests[shortest_index], head);
        head = requests[shortest_index];
        visited[shortest_index] = 1;
    }

    printf("Total Seek Time: %d\n", seek_time);

    return 0;
}

