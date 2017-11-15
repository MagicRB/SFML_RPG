cmake_minimum_required(VERSION 2.8.9)
project(SFML_TEST)

include_directories(include)

file(GLOB SOURCES "src/*.cpp" "include/*.h")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

add_executable(SFML_TEST ${SOURCES})

target_link_libraries(SFML_TEST sfml-window sfml-graphics sfml-system)