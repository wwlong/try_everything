#include <stdio.h>
/*core_dump_test.c*/
 #include <stdio.h>
const char *str = "test";
void core_test(){
    str[1] = 'T';
}

int main(){
    core_test();
    return 0;
}
