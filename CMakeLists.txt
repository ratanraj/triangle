cmake_minimum_required(VERSION 3.15)
project(triangle)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
add_executable(triangle src/main.cpp src/Game.cpp src/Game.h src/TextureManager.cpp src/TextureManager.h src/Map.cpp src/Map.h src/GameObject.cpp src/GameObject.h)
target_link_libraries(triangle ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})