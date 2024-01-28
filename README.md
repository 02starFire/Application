# Unix Domain Socket Server in C

This is a simple C program demonstrating the creation of a Unix domain socket server.

## Code Explanation

```c
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <string.h>  // Added for strlen()

// Function to handle the interrupt signal (SIGINT)
void interrupt(int signum) {
    printf("Received signal.. exiting...\n");
    exit(signum);
}

int main() {
    // Register signal handler for SIGINT
    signal(SIGINT, &interrupt);

    // Create a Unix domain socket
    int fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return 1;
    }

    // Set up the sockaddr_un structure for binding
    struct sockaddr_un my;
    memset(&my, 0, sizeof(struct sockaddr_un)); // Initialize the structure with zeros
    my.sun_family = AF_UNIX;
    strncpy(my.sun_path, "file.temp", sizeof(my.sun_path) - 1);

    // Bind the socket to the specified address
    if (bind(fd, (struct sockaddr *)&my, sizeof(struct sockaddr_un)) < 0) {
        perror("Bind");
        return 1;
    }

    // Listen for incoming connections with a backlog of 5
    listen(fd, 5);
    perror("listen");

    int client;
    // Accept incoming connections in a loop
    while ((client = accept(fd, NULL, NULL)) >= 0) {
        int pid = fork();
        if (pid < 0) {
            perror("Fork");
            return 2;
        } else if (pid == 0) {
            // Close the original socket in the child process
            close(fd);

            // Handle the client connection in the child process
            // TODO: Implement your logic here

            // Close the client socket and exit the child process
            close(client);
            exit(0);
        } else {
            // Close the client socket in the parent process
            close(client);
        }
    }

    // Clean up: unlink the socket file
    unlink("file.temp");
    perror("unlink");

    return 0;
}
```
## How to use
- Compile the code : "gcc your_file_name.c -o your_output_executable"
- Run the executable : "./your_output_executable"
-    Interrupt the Program:

    Press Ctrl + C to send the interrupt signal (SIGINT) and exit the program.

Feel free to customize the code and add your logic for handling client connections in the child process.
Replace `"your_file_name.c"` and `"your_output_executable"` with your preferred file names when compiling. This Markdown file provides both the code and an explanation of how to compile and run the program.

