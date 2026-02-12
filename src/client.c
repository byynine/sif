#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 9000

int main() {
    int sock;
    struct sockaddr_in addr;
    char buffer[1024] = {0};

    // 1. Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // 2. Configure server address
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    // 3. Connect
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("connect");
        close(sock);
        return 1;
    }

    // 4. Send message
    char *msg = "hello from client";
    send(sock, msg, strlen(msg), 0);

    // 5. Receive response
    read(sock, buffer, sizeof(buffer));
    printf("server replied: %s\n", buffer);

    close(sock);

    return 0;
}
