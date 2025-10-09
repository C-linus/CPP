#include <iostream>
enum Color(RED,GREEN,BLUE);

void FillColor(Color color){

    if(color == RED)
    {
        std::cout<<"RED"<<std::endl;
    }

    else if(color == GREEN)
    {
        std::cout << "GREEN" << std::endl;
    }

    else if(color == BLUE)
    {
        std::cout<< "BLUE" << std::endl;
    }
}


int main()
{
    Color c = Color::RED;
    FillColor(c);
    FillColor(Color::GREEN);
    FillColor(static_cast<Color>(2));
}