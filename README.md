# FOX NAMESPACE
Yet another opensource C++ library for every day developing. A rewrite of the [FOLF-namespace](https://github.com/FOLF-projects/folf-namespace) developed by Myself and a friend of mine.

# Whats inside?
FOX provides many functions for universal usage. It's split into multiple headers to make it easier to integrate. FOLF currently provides:

- consoleOperations.h
    - provides functions for manipulating the console on various plattforms
- numberOperations.h
    - provides functions for manipulating numbers
- more comming soon

# supported plattforms (may work on other systems as well)
- Windows (10)
- Linux (x86_64)
- comming soon
    - MacOS
    - Unix (OpenBSD)
    - Linux (armv7, armv8a)

# use FOX in your own project
Move FOX's source into your project directory (src/fox as example).
Now just unclude this inside your CMakeLists.txt

```
add_subdirectory("${PROJECT_SOURCE_DIR}/src/fox/")
project(your-project path/to/your/source ${fox-source})
```
That's it! Now you can just include the headers inside your source files
#### Please note, that using C++20 is highly recommended (especially when using FOX)

# ways to contribute
Just provide feedback, or extend FOX-namespace via pull-request

# License
FOX is licensed under [MIT](https://placeholder.invalid)
