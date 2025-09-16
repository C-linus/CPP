#include <iostream>

int main()
{
    int *ptr1 = new int[3];
    int *ptr2 = new int[3];

    int  **ptrs = new int *[2]{ptr1,ptr2};

    delete [] *ptrs;
    delete [] *(ptrs + 1);
    delete [] ptrs;

    return EXIT_SUCCESS;
}