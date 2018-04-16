#include <stdio.h>
#include <sys/time.h>
#include <string.h>

int main()
{
    struct timeval start,end;
    long long unsigned a = 5;

    memset(&start, 0 ,sizeof(struct timeval));
    memset(&end, 0, sizeof(struct timeval));

    gettimeofday(&start, NULL);
    long long unsigned b = a >> 32;
    
    gettimeofday(&end, NULL);
    long long unsigned tmp = (end.tv_sec - start.tv_sec) * 10000000 + (end.tv_usec - start.tv_usec);
    printf("b : %llu\n time ： %llu us\n", b, tmp);
    
    return 0;
}
