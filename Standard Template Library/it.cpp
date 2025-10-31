#include <iostream>
#include <vector>
#include <typeinfo>

int main() {
    std::vector<int>::iterator it;
    std::cout << typeid(it).name() << '\n';
    std::cout << typeid(*it).name() << '\n';

}
