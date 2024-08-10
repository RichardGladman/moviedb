cmake_minimum_required(VERSION 3.5)

project(MovieDb LANGUAGES CXX)

find_package(ansicodes REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MovieDb main.cpp
    menu.h menu.cpp
    movie.h movie.cpp
    movies.h movies.cpp
    printable.cpp printable.h
    input.h input.cpp)

target_include_directories(MovieDb PRIVATE /usr/local/include/ansicodes)
target_link_libraries(MovieDb PRIVATE ansicodes::ansicodes_lib)

include(GNUInstallDirs)
install(TARGETS MovieDb
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
