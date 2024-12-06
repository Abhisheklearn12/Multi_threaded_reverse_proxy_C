// 😇Let's build a "Basic Multithreaded Reverse Proxy Server in C from Scratch"
// 1. Under 130+ lines.
// 2. Great for understanding the fundamentals.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <netdb.h>

#define BUFFER_SIZE 8192
#define PORT 8080

typedef struct {
    int client_sock;
} thread_args_t;

// Updated handle_client function
void *handle_client(void *args) {
    thread_args_t *client_args = (thread_args_t *)args;
    int client_sock = client_args->client_sock;

    // Serve a static file (index.html)
    const char *file_path = "/mnt/c/Users/Abhishek Kumar/Desktop/Multithreaded_reverse_proxy_in_c/index.html";
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Failed to open file");
        const char *error_response =
            "HTTP/1.1 404 Not Found\r\n"
            "Content-Type: text/plain\r\n"
            "Content-Length: 13\r\n"
            "\r\n"
            "404 Not Found";
        send(client_sock, error_response, strlen(error_response), 0);
        close(client_sock);
        free(client_args);
        return NULL;
    }

    // Read the contents of the file
    char file_buffer[4096];
    size_t file_size = fread(file_buffer, 1, sizeof(file_buffer), file);
    fclose(file);

    // Prepare and send the HTTP response
    char response_header[256];
    snprintf(response_header, sizeof(response_header),
             "HTTP/1.1 200 OK\r\n"
             "Content-Type: text/html\r\n"
             "Content-Length: %zu\r\n"
             "\r\n",
             file_size);

    send(client_sock, response_header, strlen(response_header), 0);
    send(client_sock, file_buffer, file_size, 0);

    // After solving some errors found in above
    //Let's continue tomorrrow from here (ALL the best).

    // Let's get started from here

    // Clean up and close the connection
    close(client_sock);
    free(client_args);

    return NULL;

}

// Main function from where everything got started

int main() {
    int server_sock;
    struct sockaddr_in server_addr;

    // Create the server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock <0) {
        perror("Failed to create sockt");
        exit(EXIT_FAILURE);
    }

    // Configure the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address and port
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind");
        close(server_sock);
        exit(EXIT_FAILURE);

    }

    // Start listening for incoming connections
    if (listen(server_sock, 10) < 0) {
        perror("Failed to listen");
        close(server_sock);
        exit(EXIT_FAILURE);

    }

    printf("Reverse proxy server running on port %d...\n", PORT);

    // Main loop to handle client connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        // Accept a new client connection
        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("Failed to accept connection");
            continue;
        }


        // Allocate memory for thread arguments
        thread_args_t *args = malloc(sizeof(thread_args_t));
        if(!args) {
            perror("Failed to allocate memory for thread arguments");
            close(client_sock);
            continue;
        }
        args->client_sock = client_sock;

        // Create a new thread to handle the client
        pthread_t thread_id;
        if(pthread_create(&thread_id, NULL, handle_client, args) != 0) {
            perror("Failed to create thread");
            close(client_sock);
            free(args);
            continue;
        }

        // Detach the thread to allow it to clean up its resources
        pthread_detach(thread_id);
    }

    // Close the server socket
    close(server_sock);
    return 0;

}

// Finally it's complete, let's check it on terminal.
// Now let's write HTML code, to see the result.
// Now open terminal

// Finally prgram is successful, now close the port.
// Here's the steps==>

// Now port is closed, Hooray....
