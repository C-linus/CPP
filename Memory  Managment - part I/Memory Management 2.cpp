#include <iostream>


int main()
{
    // Allocating array of 5 integers in heap 
    int* ptr = new int[5];

    // Initializing the array with values
    for(int i = 0; i < 5; i++)
    {
        *(ptr + i) = i;
    }

    // Another syntax through uniform initalization (initializer-list)
    // int *ptr = new int[5]{1,2,3,4,5};

    // Deallocating array
    delete []ptr;

    ptr = nullptr;

    return EXIT_SUCCESS;
}