#include <stdio.h>
#include <stdio.h>
#define _GNU_SOURCE
#include <sys/prctl.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
/*
 *  创建pthread时，通过pthread_attr设置该线程的属性
 * */
#define flag_dbg(fmt...)   \
    do {\
        printf("[%s] -- [%d]: ", __FUNCTION__, __LINE__);\
        printf(fmt);\
    }while(0)

#define flag_dbg_error(fmt...)   \
    do {\
        printf("[%s] -- [%d] -- [errno:%d] -- [%s]", __FUNCTION__, __LINE__, errno, strerror(errno));\
        printf(fmt);\
    }while(0)

void *pthread_test(void *args) {
    /*
     *  
     * */
//    pthread_detach(pthread_self()); 
    prctl(PR_SET_NAME,"THREAD1");
    char hahaha[50*1024];
    while(1) {
        printf("thread test\n");
        sleep(1);
        memset(hahaha, 'a', 50*1204);
    }
}


int main() {
    
    /*  
     *设置线程的属性
      线程的优先级
      线程stack size 
     * */
    int ret, stack_size;
    pthread_t pthread0;
    pthread_attr_t attr;
    ret = pthread_attr_init(&attr);
    if(0 != ret) {
        perror("pthread_attr_init fail\n");
        return -1;
    }
    stack_size = 16*1024; 
    ret = pthread_attr_setstacksize(&attr, stack_size);
    if(ret != 0) {
        flag_dbg_error("ret : %d\n", ret);
        perror("pthread_attr_setstacksize failed\n");
        return -1;
    }
//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//                        void *(*start_routine) (void *), void *arg);

    if(0 != (ret = pthread_create(&pthread0, &attr, pthread_test, NULL)))
    {
        flag_dbg_error("pthread create failed : %d\n", ret);
        return -1;
    } 
    char *    pthread_name = "pthread_test0";
//    pthread_setname_np(pthread0, pthread_name);
    pthread_join(pthread0, NULL);

    printf("pthread0 return : %d\n", ret);

    return 0;
}

