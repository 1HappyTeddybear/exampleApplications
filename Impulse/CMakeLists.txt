project(Impulse)

find_package(matrixapplication REQUIRED)

set(MAINSRC
    main.cpp Impulse.cpp Impulse.h)

set(MAINLIBS
        matrixapplication::matrixapplication
)

add_executable(Impulse ${MAINSRC})
target_link_libraries(Impulse ${MAINLIBS}) #-l flag

install(TARGETS Impulse DESTINATION /home/pi/APPS)