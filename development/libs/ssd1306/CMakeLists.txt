cmake_minimum_required(VERSION 3.5)

project(lcdgfx)

include(cmake/LIB_SSD1306_CONFIG.cmake)

set(SSD1306_CORE_SRCS
    src/ssd1306_generic.c
    src/ssd1306_hal/avr/platform.c
    src/lcd/lcd_common.c
    src/intf/spi/ssd1306_spi.c
    src/intf/spi/ssd1306_spi_avr.c
    src/intf/ssd1306_interface.c
)

if(SSD1306_ENABLE_NANO_ENGINE)
    set(SSD1306_ENABLE_DISPLAY_DRIVER_SSD1306 ON)
    set(SSD1306_ENABLE_COLOR_DRIVER_1_BIT ON)
    set(SSD1306_ENABLE_COLOR_DRIVER_8_BIT ON)
    set(SSD1306_ENABLE_COLOR_DRIVER_16_BIT ON)
    list(APPEND SSD1306_CORE_SRCS
        src/nano_engine/canvas.cpp
        src/nano_engine/core.cpp
        src/nano_gfx.cpp
        src/sprite_pool.cpp
        src/ssd1306_console.cpp
    )
endif()

if(SSD1306_ENABLE_COLOR_DRIVER_1_BIT)
    list(APPEND SSD1306_CORE_SRCS src/ssd1306_1bit.c)
endif()

if(SSD1306_ENABLE_COLOR_DRIVER_8_BIT)
    list(APPEND SSD1306_CORE_SRCS src/ssd1306_8bit.c)
endif()

if(SSD1306_ENABLE_COLOR_DRIVER_16_BIT)
    list(APPEND SSD1306_CORE_SRCS src/ssd1306_16bit.c)
endif()

if(SSD1306_ENABLE_FONT_DRIVER)
    list(APPEND SSD1306_CORE_SRCS src/ssd1306_fonts.c)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_SSD1306)
    list(APPEND SSD1306_CORE_SRCS src/lcd/oled_ssd1306.c)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_SSD1325)
    list(APPEND SSD1306_CORE_SRCS src/lcd/oled_ssd1335.c)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_SSD1327)
    list(APPEND SSD1306_CORE_SRCS src/lcd/oled_ssd1327.c)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_SSD1331)
    list(APPEND SSD1306_CORE_SRCS src/lcd/oled_ssd1331.c)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_SSD1351)
    list(APPEND SSD1306_CORE_SRCS src/lcd/oled_ssd1351.c)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_SH1106)
    list(APPEND SSD1306_CORE_SRCS src/lcd/oled_sh1106.c)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_PCD8544)
    list(APPEND SSD1306_CORE_SRCS src/lcd/led_pcd8544.c)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_ILI9163)
    list(APPEND SSD1306_CORE_SRCS src/lcd/lcd_ili9163.c)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_ILI9341)
    list(APPEND SSD1306_CORE_SRCS src/lcd/lcd_ili9341.c)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_COMPOSITE_VIDEO)
    list(APPEND SSD1306_CORE_SRCS src/lcd/composite_video.c)
endif()

add_library(ssd1306 STATIC ${SSD1306_CORE_SRCS})

target_include_directories(ssd1306 PUBLIC src)

if(SSD1306_ENABLE_COLOR_DRIVER_1_BIT)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_COLOR_DRIVER_1_BIT)
endif()

if(SSD1306_ENABLE_COLOR_DRIVER_8_BIT)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_COLOR_DRIVER_8_BIT)
endif()

if(SSD1306_ENABLE_COLOR_DRIVER_16_BIT)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_COLOR_DRIVER_16_BIT)
endif()

if(SSD1306_ENABLE_FONT_DRIVER)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_FONT_DRIVER)
endif()

if(SSD1306_ENABLE_NANO_ENGINE)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_NANO_ENGINE)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_SSD1306)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_DISPLAY_DRIVER_SSD1306)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_SSD1325)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_DISPLAY_DRIVER_SSD1325)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_SSD1327)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_DISPLAY_DRIVER_SSD1327)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_SSD1331)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_DISPLAY_DRIVER_SSD1331)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_SSD1351)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_DISPLAY_DRIVER_SSD1351)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_SSD1106)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_DISPLAY_DRIVER_SSD1106)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_PCD8544)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_DISPLAY_DRIVER_PCD8544)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_ILI9163)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_DISPLAY_DRIVER_ILI9163)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_ILI9341)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_DISPLAY_DRIVER_ILI9341)
endif()

if(SSD1306_ENABLE_DISPLAY_DRIVER_COMPOSITE_VIDEO)
    target_compile_definitions(ssd1306 PUBLIC ENABLE_DISPLAY_DRIVER_COMPOSITE_VIDEO)
endif()

target_compile_options(ssd1306
    PRIVATE
        -mmcu=atmega328p
        -Os
)