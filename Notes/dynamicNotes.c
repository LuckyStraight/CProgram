#include <stdio.h>
#include <stdlib.h> // Malloc location

int main()
{
    int x = 4;
    int *ptr = (int *) malloc(sizeof(int)); // allocating 4 bytes of memory in the heap space.

    printf("The address of the ptr itself %p\n", &ptr);
    printf("ptr is pointing to %p\n", ptr);

    if(ptr == NULL)
    {
        printf("malloc didn't find enough space in the heap space\n");
        printf("ptr is pointing to %p\n", ptr);
    }

    else
    {
        printf("The address of the ptr is pointing to %p\n", &ptr);
        *ptr = 3;
    }

    return 0;
}