#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr = (int *)malloc(sizeof(int));

    if(ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    *ptr = 5;
    printf("%d\n",ptr);
    free(ptr);
    return EXIT_SUCCESS;
}