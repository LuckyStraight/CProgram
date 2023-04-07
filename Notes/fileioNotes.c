#include <stdio.h>

int main()
{
    FILE *ptr;

    ptr = fopen("num.txt", "r");

    if(ptr == NULL)
    {
        printf("The file did not open successfully!\n");
    }
    else
    {
        printf("ptf points to %p\n", ptr);

        int var;
        int result;

        while((fscanf(ptr, "%d", &var) != &var)  != -1)
        {
            //fscanf(ptr, "%d", &var);
            printf("After reading the first line, var = %d", var);
            printf("ptr points to %p\n", ptr);
        }


    }
    fclose(ptr);


    FILE *ptr2 = fopen("morning.txt", "w"); //for pen mode just change w to a.

    int val = 55;

    fprintf(ptr2,"It's October 19th ...\n");
    fprintf(ptr2,"The val = %d\n", val);

    fclose(ptr2);


    return 0;
}