# initialize project
cmake_minimum_required(VERSION 3.10.0)
project(Lander)

# compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# load packages
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/cmake_modules)
find_package(SFML REQUIRED COMPONENTS graphics window system)

# library directories
include_directories(${SFML_INCLUDE_DIR})

# library sources
# TODO

# project directories
include_directories(headers)

# project sources
file(GLOB SRC src/*.cpp)

# create exectuables
# add_executable(Lander ${SRC} ${IMGUI_SRC})
add_executable(Lander ${SRC}) 

# link libraries
target_link_libraries(Lander ${SFML_LIBRARIES} ${SFML_DPENDENCIES})
target_link_libraries(Lander libBox2D.a libIMGUI.a)

