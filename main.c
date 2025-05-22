#include <stdio.h>
#include <sys/socket.h>

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

    return 0;
}
