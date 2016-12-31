cmake_minimum_required(VERSION 3.6)
project(jaogll)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2 -lGLEW -lGL")

set(SOURCE_FILES src/jaogll.cpp src/camera2D.cpp src/error.cpp src/glsl_compiler.cpp src/image_loader.cpp src/iomanager.cpp src/input_manager.cpp src/resource_manager.cpp src/sprite_batch.cpp src/texture_cache.cpp src/timing.cpp src/window.cpp)
add_library(jaogll SHARED ${SOURCE_FILES})