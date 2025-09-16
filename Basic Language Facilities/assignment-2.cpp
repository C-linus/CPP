#include <iostream>
using namespace std;


void Add(int a, int b, int &result)
{
    result = a + b;
}

void Factorial(int a, int &result)
{
    result = 1;
    for(int i = 2; i <= a; i++)
        result *= i;
}

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


int main()
{
    int a{0},b{0},result{0};
    cout << "Init of variables"<<endl;
    cout << "Value of a:"<<a<<endl;
    cout << "Value of b:"<<b<<endl;
    cout << "Value of result:"<<result<<endl;

    a = 5;
    b = 6;
    Add(a,b,result);

    cout << "After addition by reference(alias)"<<endl;
    cout << "Value of a:"<<a<<endl;
    cout << "Value of b:"<<b<<endl;
    cout << "Value of result:"<<result<<endl;


    Swap(a,b);
    cout << "After Swap"<<endl;
    cout << "Value of a:"<<a<<endl;
    cout << "Value of b:"<<b<<endl;


    Factorial(a,result);
    cout << "After Swap"<<endl;
    cout << "Factorial of a:"<<result<<endl;

    return 0;
}