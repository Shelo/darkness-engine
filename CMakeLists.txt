cmake_minimum_required(VERSION 3.3)
project(darkness)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

find_package(OpenGL REQUIRED)
find_package(GLFW REQUIRED)

include_directories(${GLFW_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(sources)
include_directories(include)

set(SOURCE_FILES
        main.cpp
        sources/Application.cpp
        sources/Application.h
        sources/Graphics.cpp
        sources/Graphics.h
        sources/Shader.cpp
        sources/Shader.h
        sources/Macros.h
        sources/Util.h
        sources/Util.cpp
        sources/SpriteBatch.cpp
        sources/SpriteBatch.h
        sources/Texture.cpp sources/Texture.h sources/Camera.cpp sources/Camera.h)

add_executable(darkness ${SOURCE_FILES})

target_link_libraries(darkness ${GLFW_LIBRARIES} ${OPENGL_LIBRARIES})
