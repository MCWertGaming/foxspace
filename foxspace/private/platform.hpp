#pragma once
#include <cstdlib>
#include <string>
#if not defined(_WIN32)
#include <unistd.h>
#endif

namespace Fox::Private {
// returns the local user directory as string
inline std::string getUserConfigDir() {
#if defined(_WIN32)
    return std::getenv("APPDATA");
#else
    return ((std::string)std::getenv("HOME")).append("/.config");
#endif
}
inline bool is_user_root() {
#if defined(_WIN32)
    return false;
#else
    // if the user id is 0, he is root
    if (getuid() == 0 || geteuid() == 0)
        return true;
    // user is not root
    return false;
#endif
}
}  // namespace Fox::Private
