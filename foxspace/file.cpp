#include "private/platform.hpp"
#include <foxspace/file.hpp>

#include <filesystem>
#include <fstream>
#include <fstream>

void Fox::create_directory(std::string& path)
{
    if (!std::filesystem::create_directories(path))
    {
        std::runtime_error("Fox::create_directory() failed to create directory.");
    }
}
void Fox::create_file(std::string& path)
{
    // create directory to file
    if(!std::filesystem::create_directories(path))
        std::runtime_error("Fox::create_file() couldn't create directory.");
    // create empty file
    std::fstream file;
    file.open(path);
    file.close();
}

std::string Fox::get_user_config_folder()
{
    return Private::getUserConfigDir();
}
std::string Fox::get_user_config_folder(const char* path)
{
    std::string full_path = Private::getUserConfigDir();
    // TODO into one line?
    full_path.append("/").append(path);
    return full_path;
}
