#include <iostream>

int Add(int x, int y);

int main()
{
    int x,y;
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;

    int result = Add(x,y);
    std::cout << "Result :" << result << std::endl;
}

int Add(int x, int y)
{
    return x + y;
}