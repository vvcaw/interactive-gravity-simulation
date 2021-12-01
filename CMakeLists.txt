cmake_minimum_required(VERSION 3.1)
project(Sth)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS audio graphics window system REQUIRED)

add_executable(Sth main.cpp Particle.h calculate.h calculate.cpp)

target_link_libraries(Sth sfml-system)
target_link_libraries(Sth sfml-graphics)
target_link_libraries(Sth sfml-window)