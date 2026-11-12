cmake_minimum_required (VERSION 3.5)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.c)
file(GLOB_RECURSE HEADER_FILES src/*.h)

if (NOT DEFINED COMPONENT_DIR)
    project (lcdgfx)
    add_library(ssd1306 STATIC ${HEADER_FILES} ${SOURCE_FILES})
    target_include_directories(ssd1306
        PUBLIC
            src
    )
    target_compile_definitions(ssd1306
        PRIVATE
            F_CPU=16000000UL
    )
    target_compile_options(ssd1306
        PRIVATE
            -mmcu=atmega328p
            -Os
    )
else()
    idf_component_register(SRCS ${SOURCE_FILES}
                           INCLUDE_DIRS "src"
                           REQUIRES    driver)
endif()
