cmake_minimum_required(VERSION 2.8)
project( STEP_1 )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( read_webcam read_webcam.cpp )
target_link_libraries( read_webcam ${OpenCV_LIBS} )