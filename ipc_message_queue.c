sender.c

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
 
struct msgbuf
{
    long mtype;
    char mtext[100];
};
int main()
{
    int msqid;
    struct msgbuf msg;
    msqid = msgget(1234, 0666 | IPC_CREAT);
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello Queue");
    msgsnd(msqid, &msg, sizeof(msg.mtext), 0);
    printf("Message Sent Successfully\n");
    return 0;
}

Reciever.c

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
 
struct msgbuf
{
    long mtype;
    char mtext[100];
};
 
int main()
{
    int msqid;
    struct msgbuf msg;
    msqid = msgget(1234, 0666 | IPC_CREAT);
    msgrcv(msqid, &msg, sizeof(msg.mtext), 1, 0);
    printf("Received: %s\n", msg.mtext);
    return 0;
}
