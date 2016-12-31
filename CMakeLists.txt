cmake_minimum_required(VERSION 3.6)
project(jaogll)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2 -lGLEW -lGL")

set(SOURCE_FILES camera2D.h error.h gl_texture.h glsl_compiler.h image_loader.h input_manager.h iomanager.h jaogll.h logger.h resource_manager.h sprite_batch.h texture_cache.h timing.h vertex.h window.h external/picoPNG.cpp external/picoPNG.h sprite.h src/sprite.cpp src/jaogll.cpp src/camera2D.cpp src/error.cpp src/glsl_compiler.cpp src/image_loader.cpp src/iomanager.cpp src/input_manager.cpp src/resource_manager.cpp src/sprite_batch.cpp src/texture_cache.cpp src/timing.cpp src/window.cpp)
add_library(jaogll SHARED ${SOURCE_FILES})