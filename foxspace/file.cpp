#include <foxspace/file.hpp>
#include "private/platform.hpp"

#include <filesystem>
#include <fstream>

//     // TODO: measure permissions
//     // TODO: test what happens if no home directory exists
void Fox::create_directory(const char* path) {
    if (!std::filesystem::is_directory(path)) {
        if (!std::filesystem::create_directories(path)) {
            throw std::runtime_error(
                "Fox::create_directory() failed to create directory.");
        }
    }
}
void Fox::create_file(const char* path) {
    // create directory to file
    if (!std::filesystem::create_directories(path))
        throw std::runtime_error(
            "Fox::create_file() couldn't create directory.");
    // create empty file
    std::fstream file;
    file.open(path);
    file.close();
}

const char* Fox::get_user_config_folder() {
    return Private::getUserConfigDir();
}
const char* Fox::get_user_config_folder(const char* path) {
    return ((std::string)Private::getUserConfigDir())
        .append("/")
        .append(path)
        .c_str();
}
