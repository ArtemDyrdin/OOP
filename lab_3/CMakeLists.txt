cmake_minimum_required(VERSION 3.25)
project(lab_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_3 main.cpp headers/Font.h headers/Text.h)
file(COPY fonts/5.txt fonts/7.txt DESTINATION "fonts/")
