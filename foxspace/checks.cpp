#include <foxspace/checks.hpp>
#include <stdexcept>
#include "private/platform.hpp"

bool Fox::is_user_root() {
    return Private::is_user_root();
}
void Fox::exit_if_root() {
    if (Private::is_user_root())
        throw std::runtime_error(
            "Running as root / admin is not allowed! Please run as regular "
            "user.");
}
