reciever.c

#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
 
int main()
{
    int sfd;
    char buf[100] = {0};
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);
    sfd = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    server.sin_addr.s_addr = INADDR_ANY;
    bind(sfd, (struct sockaddr *)&server, sizeof(server));
    recvfrom(sfd, buf, sizeof(buf), 0,
             (struct sockaddr *)&client, &len);
    printf("Received: %s\n", buf);
    close(sfd);
    return 0;
}

Sender.c

#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
 
int main()
{
    int sfd;
    struct sockaddr_in server;
    sfd = socket(AF_INET, SOCK_DGRAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(5000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    sendto(sfd,
           "Hello UDP",
           10,
           0,
           (struct sockaddr *)&server,
           sizeof(server));
    close(sfd);
    return 0;
}
