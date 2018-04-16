#include <stdio.h>
int file_operation_demo();
int main ()
{
    file_operation_demo();

    return 0;
}

int file_operation_demo()
{
    char *file_name_prefix = "nemo_cap.jpg";
    char *file_name[128];
    FILE *nemo_cap = fopen(file_name_prefix, "wb");
    if (NULL == nemo_cap)
    {
        perror("fopen failed\n");
        return -1;
    }
    fwrite("hahahaha\0", 9, 1, nemo_cap);
    fflush(nemo_cap);
    fclose(nemo_cap);
}
