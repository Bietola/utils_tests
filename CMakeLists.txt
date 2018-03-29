# initialize project
cmake_minimum_required(VERSION 3.10.0)
project(Proj)

# compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# load packages
set(CMAKE_LIBRARY_PATH /usr/local/lib/SFML)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)
find_package(SFML REQUIRED COMPONENTS graphics window system)

# headers directories
include_directories(${SFML_INCLUDE_DIR})

# project directories
include_directories(headers)

# project sources
file(GLOB SRC src/*.cpp)

# create exectuables
add_executable(Proj ${SRC}) 

# link libraries
target_link_libraries(Proj ${SFML_LIBRARIES} ${SFML_DPENDENCIES})
