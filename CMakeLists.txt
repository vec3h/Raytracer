cmake_minimum_required(VERSION 3.9)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(OpenGL REQUIRED)


include(build/conanbuildinfo.cmake)
conan_basic_setup()


set(SOURCE_FILES main.cpp GL/GL.cpp GL/GL.h Math/Vec3.h Primitives/Sphere.h
        Renderer/Raytracer.h Renderer/Raytracer.cpp Camera/Camera.cpp Camera/Camera.h
        Scene/Scene.cpp Scene/Scene.h Primitives/Renderable.h
        TaskManager/TaskManager.cpp TaskManager/TaskManager.h Lights/Light.cpp Lights/Light.h Math/Vec2.h Primitives/Box.h)


add_executable(Raytracer ${SOURCE_FILES})

target_link_libraries(Raytracer ${CONAN_LIBS})