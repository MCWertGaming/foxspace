# disable google-test targets
set(INSTALL_GTEST OFF CACHE BOOL "disable gtest install" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "disable gmock" FORCE)

# try to find required packages
find_package(GTest QUIET)
find_package(Git QUIET)

# check if google test is installed and if so just use it
if (GTest_FOUND)
    message(STATUS "Using locally installed google test")
    include_directories(${GTest_INCLUDE_DIRS})
endif(GTest_FOUND)

# check if git is installed, skip if google test is installed
if (Git_FOUND AND NOT GTest_FOUND)
    message(STATUS "Using git submodule for google test")
    # initialising google test git sub module at {project_folder}/dependencies/gtest
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init dependencies/gtest WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} RESULT_VARIABLE GIT_SUBMOD_RESULT)
elseif(NOT Git_FOUND AND NOT GTest_FOUND)
    # prints an error if neither google test or git is installed
    message(FATAL_ERROR "No installed version of google test or git found! Please install one in order to build foxspace's unit testing")
endif(Git_FOUND AND NOT GTest_FOUND)

# check for git failture and include the sub module directory on success
if(GIT_SUBMOD_RESULT EQUAL "0")
    message(STATUS "Google test git sub module sucessfully initialised")
    add_subdirectory(gtest)
elseif(NOT GIT_SUBMOD_RESULT EQUAL "0" AND NOT GTest_FOUND)
    message(FATAL_ERROR "Initialisation of the google test sub module failed! Please check if your git installation is working correctly")
endif(GIT_SUBMOD_RESULT EQUAL "0")
