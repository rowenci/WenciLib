cmake_minimum_required(VERSION 3.26)
project(
        WenciLib
        LANGUAGES CXX
        DESCRIPTION "my own tool lib"
        VERSION 0.0.1
)

set(CMAKE_CXX_STANDARD 17)
set(lib_name WenciLib)

add_subdirectory(ThirdParty)
add_subdirectory(./src/Timer)

aux_source_directory(./src wenci_src)
file(GLOB_RECURSE wenci_include ./include/*.h)
add_executable(${lib_name} ./src/main.cpp)
target_include_directories(${lib_name} PUBLIC include)
target_link_libraries(${lib_name} PUBLIC spdlog)
target_precompile_headers(${lib_name} PUBLIC ./include/PCH.h)