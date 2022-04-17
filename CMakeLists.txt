cmake_minimum_required(VERSION 2.8)

project(Demo2)

add_definitions(-std=c++11)
set(OpenCV_DIR /home/pi/Downloads/opencv-4.5.2/build)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(.)

add_library(MyHead Ser.cpp Tast_One.cpp Tast_two.cpp)

add_executable(Demo2 main.cpp)

target_link_libraries(Demo2 
        MyHead
        ${OpenCV_LIBS}
)





