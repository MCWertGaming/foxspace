cmake_minimum_required(VERSION 3.16)
project(foxspace
    VERSION 1.0.0
    DESCRIPTION "FoxSpace - Yet another C++ library for making developer's life easier."
    HOMEPAGE_URL "https://github.com/MCWertGaming/foxspace"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# option(FOXSPACE_BUILD_EXAMPLES "Enables building of examples" ON)
option(FOXSPACE_ENABLE_TESTING "Enables building of unit testing targets" ON)
option(FOXSPACE_ENABLE_INSTALL "Enables install generation of foxspace" ON)

add_subdirectory(fox)

if (FOXSPACE_ENABLE_TESTING)
    # enable unit testing
    include(CTest)
    enable_testing()
    # add tests
    add_subdirectory(tests)
    # add dependencies, currently only gtest
    add_subdirectory(dependencies)
endif(FOXSPACE_ENABLE_TESTING)

if (FOXSPACE_ENABLE_INSTALL)
    include(GNUInstallDirs)
    install(TARGETS foxspace
        EXPORT FoxSpaceTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        PRIVATE_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )
    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
        FoxSpaceConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY AnyNewerVersion
    )
    configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/FoxSpaceConfig.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/FoxSpaceConfig.cmake"
        INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/FoxSpace
    )
    install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/FoxSpaceConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/FoxSpaceConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/FoxSpace
    )
endif(FOXSPACE_ENABLE_INSTALL)