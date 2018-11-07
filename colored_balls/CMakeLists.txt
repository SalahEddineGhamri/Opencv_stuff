
cmake_minimum_required(VERSION 2.8)
project( HSV_BALLS )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( colored_balls_app main.cpp hsv_balls.cpp hsv_balls.hpp )
target_link_libraries( colored_balls_app ${OpenCV_LIBS} )