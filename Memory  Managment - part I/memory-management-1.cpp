#include <iostream>

int main()
{
    int *ptr = new int(5);
    std::cout << *ptr << std::endl;
    delete ptr;
    ptr = nullptr;

    return EXIT_SUCCESS;
}