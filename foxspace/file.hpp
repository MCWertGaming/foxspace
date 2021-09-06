#pragma once

#include <string>

namespace Fox {
void create_directory(std::string&);
void create_directory(std::string);
void create_file(std::string&);
std::string get_user_config_folder();
std::string get_user_config_folder(const char*);

}  // namespace Fox
