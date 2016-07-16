cmake_minimum_required(VERSION 2.8.3)
project( job )

set( CMAKE_BUILD_TYPE Release )
set( CMAKE_CXX_FLAGS "-std=c++11 -O2 -Wall -march=native" )

# eigen　，这个库只需添加头文件就行
include_directories(/usr/local/include/eigen3)


set(SRC_List 
	src/leshi.cpp
	)

add_executable( run  ${SRC_List})

