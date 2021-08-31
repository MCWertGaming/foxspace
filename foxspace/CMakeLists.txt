# configure information header
configure_file(info.hpp.in info.hpp)

# a list of all source files
set(FOXSPACE_SOURCES math.cpp time.cpp)

# create a compile target for foxspace
add_library(foxspace ${FOXSPACE_SOURCES})
target_include_directories(foxspace PUBLIC ${PROJECT_SOURCE_DIR} ${PROJECT_BINARY_DIR})
set_target_properties(foxspace PROPERTIES
    PUBLIC_HEADER "foxspace/math.hpp;foxspace/time.hpp;foxspace/info.hpp")

# enable warnings and set compile features
foreach(target foxspace)
    # Force Microsoft Visual Studio to decode sources files in UTF-8
    if (MSVC)
        target_compile_options(${target} PUBLIC "/utf-8")
    endif()
    # Add as many warning as possible:
    if (WIN32)
        if (MSVC)
            target_compile_options(${target} PRIVATE "/W4")
            target_compile_options(${target} PRIVATE "/WX")
            target_compile_options(${target} PRIVATE "/wd4244")
            target_compile_options(${target} PRIVATE "/wd4267")
            target_compile_options(${target} PRIVATE "/D_CRT_SECURE_NO_WARNINGS")
        endif()
        # Force Win32 to UNICODE
        target_compile_definitions(${target} PRIVATE UNICODE _UNICODE)
    else()
        target_compile_options(${target} PRIVATE "-Wall")
        target_compile_options(${target} PRIVATE "-Wextra")
        target_compile_options(${target} PRIVATE "-pedantic")
        target_compile_options(${target} PRIVATE "-Werror")
        target_compile_options(${target} PRIVATE "-Wno-sign-compare")
    endif()
endforeach(target foxspace)
