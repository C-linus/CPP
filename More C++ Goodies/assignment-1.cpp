#include <iostream>
#include <string>
#include <cctype>

enum class Case{SENSITIVE, INSENSITIVE};

size_t Find(const std::string &hay_stack, const std::string &needle, Case searchCase = Case::INSENSITIVE, size_t offset = 0)
{
    
    if(needle.empty())
        return offset;

    if(needle.size() > hay_stack.size() || offset >= hay_stack.size())
        return std::string::npos;


    for(size_t i = offset; i + needle.size() <= hay_stack.size(); i++)
    {
        bool match = true;

        for(size_t  j = 0; j < needle.size(); j++)
        {
            char srcChar = hay_stack[i + j];
            char searchChar = needle[j];

            if(searchCase == Case::INSENSITIVE)
            {
                srcChar = static_cast<char>(std::tolower(static_cast<unsigned char>(srcChar)));
                searchChar = static_cast<char>(std::tolower(static_cast<unsigned char>(searchChar)));
            }

            if(srcChar != searchChar)
            {
                match = false;
                break;
            }
        }
        if(match)
            return i;
    }

    return std::string::npos;
    
}


int main() {
    std::string text = "Hello World, HELLO Universe!";

    size_t pos1 = Find(text, "HELLO", Case::SENSITIVE);
    size_t pos2 = Find(text, "HELLO", Case::INSENSITIVE);

    std::cout << "Sensitive search: " 
              << (pos1 == std::string::npos ? "Not found" : std::to_string(pos1)) << '\n';
    std::cout << "Insensitive search: " 
              << (pos2 == std::string::npos ? "Not found" : std::to_string(pos2)) << '\n';
}
