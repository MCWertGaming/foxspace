# disable google-test targets
set(INSTALL_GTEST OFF CACHE BOOL "disable gtest install" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "disable gmock" FORCE)

add_subdirectory(gtest)
