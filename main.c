#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
int main(int argc, char ** argv) {
    int fd, src;
    char *srcData;
    fd = open(argv[1],O_RDONLY);
    src = lseek(fd, 0, SEEK_END);
    lseek(fd,0,SEEK_SET);
    srcData = malloc(sizeof(char)*src);
    read(fd,srcData,src);
    close(fd);
    int fd2 = open(argv[2],O_CREAT| O_RDWR| O_TRUNC,S_IRWXU);
    printf("%s",srcData);
    write(fd2,srcData,src);
    close(fd2);
    return 0;
}

