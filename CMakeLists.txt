cmake_minimum_required(VERSION 3.31)
project(CS210_Project_3_Ornelas)

set(CMAKE_CXX_STANDARD 20)

add_executable(CS210_Project_3_Ornelas main.cpp
        FileInOut.cpp
        FileInOut.h
        UserOptions.cpp
        UserOptions.h
        PrintMenu.cpp
        PrintMenu.h
)
