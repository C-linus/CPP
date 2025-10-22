#include <iostream>
#include <filesystem>

int main()
{
    using namespace std::filesystem;

    path p{R"(E:/temp/test.txt)"};
    if(p.has_filename())
    {
        std::cout<< p.filename() <<std::endl;
    }

    for(const auto &x : p)
    {
        std::cout << x << std::endl;
    }
}