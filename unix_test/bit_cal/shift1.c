#include <stdio.h>


int main()
{
    int a = 3;
    int b;
    b = a >> 1 <<1;
    printf("a >> 1 << 1 : %d\n", b);
    b = a >>2 << 2;
    printf("a >> 2 << 2 : %d\n", b);

    return 0;
}
