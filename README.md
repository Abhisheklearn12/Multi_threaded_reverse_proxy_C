
# Multithreaded Reverse Proxy Server in C

## Introduction

This repository contains the source code for a **Multithreaded Reverse Proxy Server** built in C. The server acts as an intermediary for requests from clients seeking resources from backend servers. It is just a basic verson, but we can make it much more advanced.

## Features

- **Multithreading Support:** Uses a thread pool or dynamically spawns threads to handle multiple concurrent client connections.
- **Load Balancing:** Distributes incoming requests to multiple backend servers based on algorithms like round-robin or least connections (if implemented).
- **Connection Persistence:** Supports persistent connections to backend servers for efficiency (if HTTP/1.1 Keep-Alive is implemented).
- **Customizable Configuration:** Allows configuration of port, backend servers, thread pool size, and more.
- **Request/Response Logging:** Logs client requests and responses from backend servers for debugging and analysis.
- **Error Handling:** Gracefully handles client and server errors, including timeouts and malformed requests.

## Prerequisites

Before running the project, ensure you have the following:

- **C Compiler:** GCC or Clang.
- **POSIX Threads (pthread):** Required for multithreading.
- **Linux Environment:** Tested on Linux-based systems.


## Installation and Setup (In progress)
1. Build using WSL and VScode.


## How It Works

1. **Initialization:**
   - The server reads the configuration file to initialize settings.
   - A thread pool is created to handle client connections.

2. **Client Connection Handling:**
   - The server listens on the specified port for client connections.
   - Each incoming connection is assigned to a thread in the thread pool.

3. **Request Forwarding:**
   - The proxy server parses the client request and forwards it to a backend server.
   - The backend server processes the request and sends the response back to the proxy server.

4. **Response Delivery:**
   - The proxy server relays the response from the backend server to the client.

## Contributing

Contributions are welcome! If you'd like to improve this project, feel free to submit a pull request or open an issue.

## License

This project is licensed under no License. You are free to use, modify, and distribute this software as per you.

## Acknowledgments

- **POSIX Threads Documentation:** For threading implementation.
- **C Networking Tutorials:** For socket programming techniques.
- **Open Source Community:** For various libraries and inspirations.

---
### Further readme will be done in coming days and it will be veyr useful and it can make a lot better.

