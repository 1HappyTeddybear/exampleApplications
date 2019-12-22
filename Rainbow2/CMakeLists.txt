project(Rainbow2)

find_package(matrixapplication REQUIRED)

set(MAINSRC
    main.cpp rainbow.cpp rainbow.h)

set(MAINLIBS
        matrixapplication::matrixapplication
)

add_executable(Rainbow2 ${MAINSRC})
target_link_libraries(Rainbow2 ${MAINLIBS}) #-l flag

install(TARGETS Rainbow2 DESTINATION /home/pi/APPS)