cmake_minimum_required(VERSION 3.20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# DEFINE THE LIBRARY

add_library(EZ_Display OBJECT)

target_sources(EZ_Display
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/font.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ili9341.c
)

target_include_directories(EZ_Display
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# DEFINE THE TEST EXECUTABLE

add_executable(lib_main)

target_sources(lib_main
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/font.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ili9341.c
        main.c
)

target_include_directories(lib_main
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)