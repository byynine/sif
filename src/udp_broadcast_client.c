#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 9000

int main() {
    int sock;
    struct sockaddr_in broadcast_addr;
    int broadcast_enable = 1;

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) { perror("socket"); return 1; }

    if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST,
                   &broadcast_enable, sizeof(broadcast_enable)) < 0)
    {
        perror("setsockopt");
        close(sock);
        return 1;
    }

    broadcast_addr.sin_family = AF_INET;
    broadcast_addr.sin_port = htons(PORT);
    broadcast_addr.sin_addr.s_addr = inet_addr("255.255.255.255");

    char *msg = "hello from broadcast client";

    if (sendto(sock, msg, strlen(msg), 0,
               (struct sockaddr*)&broadcast_addr,
               sizeof(broadcast_addr)) < 0)
    {
        perror("sendto");
        close(sock);
        return 1;
    }

    printf("broadcast sent\n");

    close(sock);
    return 0;
}
