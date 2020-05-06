project(cubeTestApp)

find_package(matrixapplication REQUIRED)

add_executable(cubetestapp main.cpp CubeTest.cpp Color2.cpp Color2.h)
target_link_libraries(cubetestapp matrixapplication::matrixapplication)