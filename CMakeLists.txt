cmake_minimum_required(VERSION 3.0.2)

add_library(observer OBJECT
        ${CMAKE_CURRENT_SOURCE_DIR}/src/subject.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/observer.c)

target_include_directories(observer PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/)
