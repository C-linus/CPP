#include <iostream>
#include <utility>
#include <memory>

#include <iostream>
#include <string>


template<typename T, typename... Args>
std::unique_ptr<T> CreateObject(Args&&... args)
{
    return std::make_unique<T>(std::forward<Args>(args)...);
}

struct Employee {
    std::string name;
    int id;
    double salary;

    template<typename S>
    Employee(S&& n, int i, double s)
        : name(std::forward<S>(n)), id(i), salary(s) {}
};

struct Contact {
    std::string name;
    long phone;
    std::string address;
    std::string email;

    template<typename S>
    Contact(S&& n, long p, S&& a, S&& e)
        : name(std::forward<S>(n)), phone(p), address(std::forward<S>(a)), email(std::forward<S>(e)) {}
};





int main()
{
    std::unique_ptr<Employee> emp = CreateObject<Employee>("Bob", 101, 1000) ;
}
