#include <stdio.h>
#include <unistd.h>
int main()
{
 int fd[2];
 char buf[50];
 pipe(fd);
 if(fork() == 0)
 {
 close(fd[1]);
 read(fd[0], buf, sizeof(buf));
 printf("Child Received: %s\n", buf);

 close(fd[0]);
 }
 else
 {
 close(fd[0]);
 write(fd[1], "Hello Child", 12);
 close(fd[1]);
 }
 return 0;
}
