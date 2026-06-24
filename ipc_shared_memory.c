writer.c

#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
 int shmid;
 char *ptr;
 shmid = shmget(1234, 1024, 0666 | IPC_CREAT)
 ptr = (char *)shmat(shmid, NULL, 0);
 strcpy(ptr, "Hello Shared Memory");
 printf("Data Written Successfully\n");
 return 0;
}

Reader.c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
 
int main()
{
    int shmid;
    char *ptr;
    shmid = shmget(1234, 1024, 0666);
    ptr = (char *)shmat(shmid, NULL, 0);
    printf("Data Read: %s\n", ptr);
    return 0;
}

