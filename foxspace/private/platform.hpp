#pragma once

#include <cstdlib>
#include <unistd.h>
#include <string>


namespace Fox::Private
{
    // returns the local user directory as string
    inline std::string getUserConfigDir()
    {
        #if defined(__WIN32)
            // TODO test
            return std::getenv("APPDATA");
        #else
            std::string path = std::getenv("HOME");
            return path.append("/.config");
        #endif
    }
    inline bool is_user_root()
    {
        #if defined(_WIN32)
            return false;
        #else
            // if the user id is 0, he is root
            if(getuid() == 0 || geteuid() == 0)
                return true;
            // user is not root
            return false;
        #endif
    }
}







