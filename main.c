#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <unistd.h>

int main(void) {
    // we will the following socket from sys/socket.h
    int tcp_socket = socket(
        AF_INET, /* this means we are using IPv4, we could use AF_INET for IPv6*/
        SOCK_STREAM, /* TCP */
        0
    );

    if (tcp_socket == -1) {
        perror("socket()");
        return 1;
    }

    struct sockaddr_in addr = {
        AF_INET,
        0x901f, // 0x1f90 or :8080 in hex is written in the following format
        0, // in_addr
    };

    int status = bind(tcp_socket, &addr, sizeof(addr));
    listen(tcp_socket, 10);

    int client_fd = accept(tcp_socket, 0, 0); // fd meaning file descriptor
    
    char buffer[256] = {0};
    recv(tcp_socket, buffer, 256, 0);

    // request will look something like:
    // GET /file.html ......
    // we are only interested in file.html
    // Thus we will skip the first 5 characters for "GET /"
    // Then we will use the space after file.html to terminate the file
    
    char* f = buffer + 5;
    *strchr(f, ' ') = 0;
    int opened_fd = open(f, O_RDONLY);
    sendfile(client_fd, opened_fd, 0, 256);

    close(opened_fd);
    close(client_fd);
    close(tcp_socket);

    return 0;
}
