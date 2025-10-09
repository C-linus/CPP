#include <iostream>
#include <string>
#include <cctype>
#include <vector>

enum class Case{SENSITIVE, INSENSITIVE};
std::vector<int> FindAll(const std::string &hay_stack, const std::string &needle, Case searchCase, size_t  offset = 0)
{
    std::vector<int> needles;



    if(needle.empty() || needle.size() > hay_stack.size() || offset >= hay_stack.size())
        return needles;

    
    for(size_t i = offset; i + needle.size() <= hay_stack.size(); i++)
    {
        bool match = true;

        for(size_t j = 0; j < needle.size(); j++)
        {
            char srcChar = hay_stack[i + j];
            char searchChar = needle[j];

            if(searchCase == Case::INSENSITIVE)
            {
                srcChar = static_cast<char>(std::tolower(static_cast<unsigned char>(srcChar)));
                searchChar = static_cast<char> (std::tolower(static_cast<unsigned char>(searchChar)));
            }

            if(srcChar != searchChar)
            {
                match = false;
                break;
            }
        }

        if(match)
        {
            needles.push_back(i);
        }
    }

    return needles;
}

int main() {
    std::string text = "Hello World, HELLO Universe hElLO!";

    auto pos = FindAll(text, "HELLO", Case::INSENSITIVE);

   std::cout<<"All needles in the hay stack"<<std::endl;

   for(auto x : pos)
   {
    std::cout<<x<<" ";
   } 
   std::cout<<std::endl;

   return 0;
}