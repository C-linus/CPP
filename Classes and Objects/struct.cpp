#include <iostream>

struct Point
{
    int x;
    int y;
};

void DrawLine(Point p1, Point p2)
{
    std::cout<<p1.x<<std::endl;
    std::cout<<p1.y<<std::endl;
    std::cout<<p2.x<<std::endl;
    std::cout<<p2.y<<std::endl;
}

int main()
{
    DrawLine({5,6},{7,8});
    return EXIT_SUCCESS;
}