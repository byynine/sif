#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 9000

int main() {
    int sock;
    struct sockaddr_in addr, client;
    socklen_t client_len = sizeof(client);
    char buffer[1024];

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr*)&addr, sizeof(addr));

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&client, &client_len);
        printf("received from %s: %s\n", inet_ntoa(client.sin_addr), buffer);
    }

    close(sock);
    return 0;
}
