#include <stdio.h>
#include <stdlib.h>   //用于EXIT_SUCCESSGN EXIT——FAILURE 
#include <fcntl.h>  
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>  
#include <assert.h>  
int main()
{
    char *file_path = "/dev/video0";
    int fd = open(file_path, O_RDWR);
    if(fd < 0) {
        printf("open failed, fd : %d\n", fd);
        return -1;
    }
    //内存映射
    
    char *start_addr = mmap(NULL, 512, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(MAP_FAILED == start_addr) {
        perror("mmap failed\n");
        exit(EXIT_FAILURE); 
    }
    munmap(start_addr, 512);
    close(fd);
    return 0;
}