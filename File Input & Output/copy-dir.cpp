#include <iostream>
#include <fstream>
#include <filesystem>
#include <memory>
#include <string>


namespace fs = std::filesystem;

void copyFile(const fs::path& source, const fs::path& destination, std::size_t CHUNK_SIZE = 4096)
{
    fs::path finalDestination = destination;

    if(fs::exists(destination) && fs::is_directory(destination))
    {
        finalDestination /= source.filename();
    }

    else if(!destination.has_extension())
    {
        fs::create_directories(destination);
        finalDestination /= source.filename();
    }

    else
    {
        fs::create_directories(finalDestination.parent_path());
    }

    std::ifstream src(source, std::ios::binary);
    std::ofstream dest(finalDestination, std::ios::binary);

    if(!src.is_open() || !dst.is_open())
    {
        std::cerr << "Error opening file: " << source << std::endl;
        return;
    }

    auto fileSize = fs::file_size(source);
    std::unique_ptr<char []>buffer = std::make_unique<char []>(CHUNK_SIZE);
    std::size_t totalCopied{};

    while(src)
    {
        src.read(buffer,CHUNK_SIZE);
        std::streamsize bytesRead = src.gcount();
        dest.write(buffer,bytesRead);
        totalCopied += bytesRead;

        double progress = (double)totalCopied / file_size * 100;
        std::cout << "\rCopying" << source.filename() << ": " << static_cast<int>(progress) << "%" << std::flush;
    }
    std::cout << "\nFinished copying" << source.filename() << std::endl;
}


void copyDirectory(const fs::path& sourceDir, const fs::path& destinationDir)
{

    if(!fs::exists(sourceDir) || !fs::is_directory(sourceDir))
    {
        std::cerr << "Source directory not found" << sourceDir << std::endl;
        return;
    }

    if(!fs::exists(destinationDir))
    {
        fs::create_directories(destinationDir);
    }

    for(auto& entry : fs::recursive_directory_iterator(sourceDir))
    {
        const auto& path = entry.path();
        auto relativePath = fs::relative(path,sourceDir);
        auto destPath = destinationDir / relativePath;

        if(fs::is_directory(path))
        {
            fs::create_directories(destPath);
        }
        else if(fs::is_regular_file(path))
        {
            copyFile(path,destPath);
        }
    }
}


int main(int argc, char**argv)
{
    if(argc != 3)
    {
        std::cerr << "Usage: copyutil <source> <destination>"<<std::endl;
        return EXIT_FAILURE;
    }

    fs::path source = *(argv + 1);
    fs::path destination = *(argv + 2);

    try
    {
        if(!fs::exists(soucre))
        {
            std::cerr << "Source path does not exist."<<std::endl;
            return EXIT_FAILURE;
        }

        if(fs::is_directory(source))
            copyDirectory(soucre,destination);
        else if(fs::is_regular_file(source))
            copyFile(source,destination);
        else
            std::cerr << "Invalid source type." << std::endl;
    }

    catch(const fs::filesystem_error& e)
    {
        std::cerr << "Filesystem error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}