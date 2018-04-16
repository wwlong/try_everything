#include <stdio.h>
#include <stdlib.h>   //用于EXIT_SUCCESSGN EXIT——FAILURE 
#include <fcntl.h>  
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>  
#include <assert.h>  
#include <sys/ioctl.h>
#include <linux/videodev2.h>
int main()
{
    char *file_path = "/dev/video0";
    int fd = open(file_path, O_RDWR|O_NONBLOCK, 0);
    if(fd < 0) {
        printf("open failed, fd : %d\n", fd);
        return -1;
    }
    //内存映射
    //int req;
    struct v4l2_requestbuffers req;
    //CLEAR(req);
    req.count = 4;
    req.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory = V4L2_MEMORY_MMAP;
    ioctl(fd, VIDIOC_REQBUFS, &req);
    char *start_addr = mmap(NULL, 512, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(MAP_FAILED == start_addr) {
        perror("mmap failed\n");
        exit(EXIT_FAILURE); 
    }
    munmap(start_addr, 512);
    close(fd);
    return 0;
}