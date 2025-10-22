#include <iostream>
#include <fstream>
#include <filesystem>
#include <memory>

#define SIZE 4096 

namespace fs = std::filesystem;

void copy_binary_file(const fs::path& source, const fs::path& destination,std::size_t CHUNK_SIZE = 4096)
{
    // Check if the source file exists and is a file
    if(!fs::exists(source) || fs::is_directory(source))
    {
        std::cerr << "Error: Source file does not exist or is a directory."<<std::endl;
        return;
    }


    // Prevent Overwriting
    if(fs::exists(destination))
    {
        std::cerr << "Error: Destination file already exists. Copy operation aborted."<<std::endl;
        return;
    }

    // Open source in binary mode
    std::ifstream src(source,std::ios::binary);
 
    if(!src)
    {
        std::cerr << "Error: Unable to open source file for reading"<<std::endl;
        return;
    }

    // Open destination in binary mode
    std::ofstream dst(destination,std::ios::binary);

    if(!dst)
    {
        std::cerr << "Error: Unable to open destination file for writing"<<std::endl;
        return;
    }

    std::unique_ptr<char[]> buffer = std::make_unique<char []>(CHUNK_SIZE);

    while(src.read(buffer.get(),CHUNK_SIZE) || src.gcount() > 0)
    {
        dst.write(buffer.get(),src.gcount());
        if(!dst)
        {
            std::cerr << "Error: Failed to write to destination file."<<std::endl;
            return;
        }
    }

    if(src.bad())
    {
        std::cerr << "Error: Failed to read from file."<<std::endl;
        return;
    }

    std::cout << "File copied successfully from " << source << " to " << destination << "\n";
}

int main()
{
    fs::path destination{},source{};

    try{
        std::cout << "Enter source file path: ";
        std::getline(std::cin,source);
        std::cout << "Enter destination path: ";
        std::getline(std::cin,destination);

        copy_binary_file(source,destination,SIZE);
    }
    catch(const fs::filesystem_error& e)
    {
        std::cerr << "Filesystem error: "<< e.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}