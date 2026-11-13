/*
    MIT License

    Copyright (c) 2016-2019, Alexey Dynda

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/
/**
 * @file ssd1306.h SSD1306 basic draw functions
 */

#ifndef _SSD1306_H_
#define _SSD1306_H_

#include "nano_gfx_types.h"
#include "ssd1306_generic.h"

// Color Drivers

#ifdef ENABLE_COLOR_DRIVER_1_BIT
#include "ssd1306_1bit.h"
#endif
#ifdef ENABLE_COLOR_DRIVER_8_BIT
#include "ssd1306_8bit.h"
#endif
#if defined(ENABLE_COLOR_DRIVER_16_BIT) || \
    defined(ENABLE_NANO_ENGINE)
#include "ssd1306_16bit.h"
#endif

#ifdef ENABLE_FONT_DRIVER
#include "ssd1306_fonts.h"
#endif


// Display Drivers

#include "lcd/lcd_common.h"
#if defined(ENABLE_DISPLAY_DRIVER_SSD1306) || \
    defined(ENABLE_NANO_ENGINE)
#include "lcd/oled_ssd1306.h"
#endif
#ifdef ENABLE_DISPLAY_DRIVER_SSD1325
#include "lcd/oled_ssd1325.h"
#endif
#ifdef ENABLE_DISPLAY_DRIVER_SSD1327
#include "lcd/oled_ssd1327.h"
#endif
#ifdef ENABLE_DISPLAY_DRIVER_SSD1331
#include "lcd/oled_ssd1331.h"
#endif
#ifdef ENABLE_DISPLAY_DRIVER_SSD1351
#include "lcd/oled_ssd1351.h"
#endif
#ifdef ENABLE_DISPLAY_DRIVER_SSD1106
#include "lcd/oled_sh1106.h"
#endif
#ifdef ENABLE_DISPLAY_DRIVER_PCD8544
#include "lcd/lcd_pcd8544.h"
#endif
#ifdef ENABLE_DISPLAY_DRIVER_ILI9163
#include "lcd/lcd_il9163.h"
#endif
#ifdef ENABLE_DISPLAY_DRIVER_ILI9341
#include "lcd/lcd_ili9341.h"
#endif
#ifdef ENABLE_DISPLAY_DRIVER_COMPOSITE_VIDEO
#include "lcd/composite_video.h"
#endif

#if defined(ENABLE_DISPLAY_DRIVER_SSD1306) || \
    defined(ENABLE_DISPLAY_DRIVER_SSD1325) || \
    defined(ENABLE_DISPLAY_DRIVER_SSD1327) || \
    defined(ENABLE_DISPLAY_DRIVER_SSD1351) || \
    defined(ENABLE_DISPLAY_DRIVER_SSD1351) || \
    defined(ENABLE_DISPLAY_DRIVER_SSD1106)
#include "lcd/oled_template.h"
#endif

#include "ssd1306.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup LCD_INTERFACE_API
 * Returns display height in pixels
 */
lcduint_t      ssd1306_displayHeight(void);

/**
 * @ingroup LCD_INTERFACE_API
 * Returns display width in pixels
 */
lcduint_t      ssd1306_displayWidth(void);

#ifdef __cplusplus
}
#endif

#endif // _SSD1306_H_
