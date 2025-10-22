#include <iostream>

template<typename T>
T Max(T x, T y)
{
    return x > y ? x : y;
}

int main()
{
    auto num = Max(3.3f,5.8f);
    auto num2 = Max(38,12);
    return 0;
}