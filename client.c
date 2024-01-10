#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <string.h>
#include <unistd.h>

int main() {
    int s = socket(AF_UNIX, SOCK_STREAM, 0);

    struct sockaddr_un server_address;
    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, "connection.tmp");

    connect(s, (struct sockaddr*)&server_address, sizeof(server_address));

    // Now you can send and receive data through the connected socket (s).
    
    // For example, sending a message:
    const char* message = "Hello, server!";
    send(s, message, strlen(message), 0);

    // You can also receive a response from the server:
    char buffer[1024];
    ssize_t received_bytes = recv(s, buffer, sizeof(buffer), 0);

    // Ensure null-termination for string
    buffer[received_bytes] = '\0';

    printf("Received from server: %s\n", buffer);

    // Don't forget to close the socket when done
    close(s);

    return 0;
}

