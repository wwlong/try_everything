#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
    int fd; 
    char *file_path = "/dev/video0";
    fd = open(file_path, O_CREAT | O_RDWR, 0777);
    if (fd < 0) { 
        perror("open");
        exit(-1);
    }   

    printf("fd = %d\n", fd);

    return 0;
}