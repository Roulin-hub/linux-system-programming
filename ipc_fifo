writer.c
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
 
int main()
{
    int fd;
    mkfifo("myfifo", 0666);
    fd = open("myfifo", O_WRONLY);
    write(fd, "Hello FIFO", 10);
    close(fd);
    return 0;
}

Reader.c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
 
int main()
{
    int fd, n;
    char buf[50];
    fd = open("myfifo", O_RDONLY);
    n = read(fd, buf, sizeof(buf)-1);
    buf[n] = '\0';
    printf("Received: %s\n", buf);
    close(fd);
    return 0;
}
