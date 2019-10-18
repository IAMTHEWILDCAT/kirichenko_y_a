cmake_minimum_required(VERSION 3.14)
project(Complex)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Complex
        Complex.h
        main.cpp Rational.h)
