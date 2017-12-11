# initialize project
cmake_minimum_required(VERSION 3.10.0)
project(Lander)

# load packages
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/cmake_modules)
find_package(SFML REQUIRED COMPONENTS graphics window system)

# library directories
include_directories(${SFML_INCLUDE_DIR})

# project executables
file(GLOB SRC src/*.cpp)
add_executable(Lander ${SRC})

# link libraries
target_link_libraries(Lander ${SFML_LIBRARIES} ${SFML_DPENDENCIES})
