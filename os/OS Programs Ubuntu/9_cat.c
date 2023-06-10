#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./cat <file1> <file2> ...\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            printf("Failed to open file: %s\n", argv[i]);
            continue;
        }

        while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
            bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
            if (bytes_written != bytes_read) {
                printf("Error writing to stdout.\n");
                return 1;
            }
        }

        if (bytes_read == -1) {
            printf("Error reading from file: %s\n", argv[i]);
            return 1;
        }

        close(fd);
    }

    return 0;
}

