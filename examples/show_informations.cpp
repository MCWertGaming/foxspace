#include <iostream>

#include <foxspace/checks.hpp>
#include <foxspace/file.hpp>

int main() {
    std::cout << "Your local user config directory: "
              << Fox::get_user_config_folder() << '\n';
    std::cout << "Directory inside of your local user config dir: "
              << Fox::get_user_config_folder("foxspace") << '\n';
    if (Fox::is_user_root())
        std::cout << "You are root! How dare you?\n";
    else
        std::cout << "You are not root! Well done\n";
    return 0;
}
