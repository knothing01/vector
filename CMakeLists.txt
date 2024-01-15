cmake_minimum_required(VERSION 3.27)
project(m_vector C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(m_vector
        header.h
        main.c
        source.c)
