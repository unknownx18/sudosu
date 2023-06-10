#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char file_path[] = "1_fork.c";
    int file_descriptor;

    // Open the file in read-only mode
    file_descriptor = open(file_path, O_RDONLY);

    if (file_descriptor == -1) {
        printf("Failed to open the file.\n");
    } else {
        printf("File opened successfully with file descriptor: %d\n", file_descriptor);

        // Read the content of the file using the file descriptor
        char buffer[256];
        ssize_t bytes_read;

        while ((bytes_read = read(file_descriptor, buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, bytes_read);
        }

        // Close the file descriptor
        close(file_descriptor);
        printf("\nFile closed.\n");
    }

    return 0;
}

