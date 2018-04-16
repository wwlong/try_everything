#include <stdio.h>

#define _GNU_SOURCE         /* See feature_test_macros(7) */
#include <string.h>
char *strcasestr(const char *haystack, const char *needle);
int main()
{
    char *str = "12345678";
    char needle[64] = "23";
    
    char *p = strcasestr(str, needle);

    if(NULL == p) {
        perror("NULL == p\n");
        return -1;
    }

    printf("p : %s\n", p);
    printf("%x\n", str);
    printf("%x\n",p);
    return 0;
}
