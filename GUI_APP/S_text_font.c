#include "lvgl/lvgl.h"

/*******************************************************************************
 * Size: 16 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifndef S_TEXT_FONT
#define S_TEXT_FONT 1
#endif

#if S_TEXT_FONT

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+20 " " */

    /* U+25 "%" */
    0x6, 0x57, 0x0, 0x0, 0x8, 0x0, 0x2, 0x90,
    0x65, 0x0, 0x5, 0x40, 0x0, 0x57, 0x5, 0x80,
    0x0, 0x80, 0x0, 0x5, 0x70, 0x57, 0x0, 0x71,
    0x0, 0x0, 0x19, 0x7, 0x20, 0x17, 0x0, 0x0,
    0x0, 0x34, 0x30, 0x8, 0x0, 0x24, 0x40, 0x0,
    0x0, 0x3, 0x40, 0x9, 0x6, 0x30, 0x0, 0x0,
    0x80, 0x4, 0x90, 0x49, 0x0, 0x0, 0x52, 0x0,
    0x58, 0x3, 0x90, 0x0, 0x7, 0x0, 0x2, 0x90,
    0x56, 0x0, 0x7, 0x0, 0x0, 0x6, 0x46, 0x0,
    0x0, 0x30, 0x0, 0x0, 0x0, 0x0,

    /* U+30 "0" */
    0x0, 0x66, 0x63, 0x0, 0x6, 0x30, 0x9, 0x10,
    0xc, 0x0, 0x5, 0x70, 0x3c, 0x0, 0x3, 0xd0,
    0x5b, 0x0, 0x2, 0xf0, 0x7b, 0x0, 0x1, 0xf0,
    0x5b, 0x0, 0x2, 0xf0, 0x3d, 0x0, 0x3, 0xd0,
    0xd, 0x0, 0x5, 0x70, 0x6, 0x50, 0x9, 0x10,
    0x0, 0x66, 0x73, 0x0,

    /* U+31 "1" */
    0x0, 0xa6, 0x0, 0x9d, 0x60, 0x51, 0xa6, 0x0,
    0xa, 0x60, 0x0, 0xa6, 0x0, 0xa, 0x60, 0x0,
    0xa6, 0x0, 0xa, 0x60, 0x0, 0xa6, 0x0, 0xa,
    0x60, 0x6, 0xeb, 0x30,

    /* U+32 "2" */
    0x0, 0x9d, 0xe6, 0x0, 0x8, 0x30, 0x3f, 0x40,
    0x6, 0x0, 0x9, 0x90, 0x0, 0x0, 0x9, 0x80,
    0x0, 0x0, 0xd, 0x30, 0x0, 0x0, 0x68, 0x0,
    0x0, 0x2, 0x90, 0x0, 0x0, 0x18, 0x0, 0x0,
    0x0, 0x80, 0x0, 0x10, 0x9, 0x10, 0x0, 0x90,
    0x5f, 0xff, 0xff, 0xd0,

    /* U+33 "3" */
    0x0, 0x8d, 0xe6, 0x0, 0x54, 0x3, 0xf0, 0x1,
    0x0, 0xb, 0x0, 0x0, 0x4, 0x10, 0x0, 0x8,
    0xea, 0x0, 0x1, 0x10, 0xc9, 0x0, 0x0, 0x4,
    0xd0, 0x0, 0x0, 0x3d, 0x0, 0x0, 0x5, 0xa0,
    0x40, 0x0, 0xb2, 0x1b, 0xa6, 0x82, 0x0,

    /* U+34 "4" */
    0x0, 0x0, 0x28, 0x0, 0x0, 0x0, 0xc9, 0x0,
    0x0, 0x6, 0x99, 0x0, 0x0, 0x26, 0x79, 0x0,
    0x0, 0x80, 0x79, 0x0, 0x5, 0x30, 0x79, 0x0,
    0x17, 0x0, 0x79, 0x0, 0x7d, 0xdd, 0xee, 0xd3,
    0x0, 0x0, 0x79, 0x0, 0x0, 0x0, 0x79, 0x0,
    0x0, 0x0, 0x79, 0x0,

    /* U+35 "5" */
    0x0, 0xef, 0xff, 0x20, 0x7, 0x0, 0x0, 0x0,
    0x50, 0x0, 0x0, 0x14, 0x0, 0x0, 0x2, 0xdf,
    0xd5, 0x0, 0x16, 0x26, 0xf4, 0x0, 0x0, 0x6,
    0xa0, 0x0, 0x0, 0x2c, 0x0, 0x0, 0x3, 0xa0,
    0x50, 0x0, 0xa3, 0x9, 0xd8, 0x72, 0x0,

    /* U+36 "6" */
    0x0, 0x0, 0x3, 0x10, 0x0, 0x29, 0x40, 0x0,
    0x2c, 0x10, 0x0, 0xd, 0x30, 0x0, 0x7, 0xa0,
    0x0, 0x0, 0xe4, 0x38, 0x90, 0x1f, 0x0, 0xb,
    0x63, 0xe0, 0x0, 0x6b, 0x1f, 0x0, 0x5, 0xc0,
    0xe1, 0x0, 0x7a, 0x8, 0x70, 0xb, 0x30, 0x9,
    0x78, 0x60,

    /* U+37 "7" */
    0x4f, 0xff, 0xff, 0xc4, 0x41, 0x11, 0x36, 0x0,
    0x0, 0x8, 0x0, 0x0, 0x0, 0x90, 0x0, 0x0,
    0x35, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x90,
    0x0, 0x0, 0x35, 0x0, 0x0, 0x7, 0x10, 0x0,
    0x0, 0x80, 0x0, 0x0, 0x7, 0x0, 0x0,

    /* U+38 "8" */
    0x7, 0x67, 0x70, 0x6, 0x60, 0x7, 0x50, 0xb2,
    0x0, 0x49, 0x9, 0x70, 0x6, 0x50, 0x2e, 0x83,
    0x50, 0x0, 0x49, 0xe9, 0x0, 0x56, 0x0, 0xba,
    0xd, 0x10, 0x1, 0xf0, 0xd1, 0x0, 0xf, 0x9,
    0x50, 0x4, 0x90, 0x9, 0x77, 0x80, 0x0,

    /* U+39 "9" */
    0x1, 0x86, 0x94, 0x0, 0xb4, 0x0, 0xd1, 0x2f,
    0x0, 0x9, 0x74, 0xe0, 0x0, 0x7a, 0x2f, 0x0,
    0x6, 0xb0, 0xb6, 0x0, 0x7a, 0x0, 0x88, 0xa,
    0x70, 0x0, 0x0, 0xe1, 0x0, 0x0, 0x78, 0x0,
    0x0, 0x3b, 0x0, 0x1, 0x78, 0x0, 0x0, 0x31,
    0x0, 0x0,

    /* U+4E8C "二" */
    0x0, 0x0, 0x0, 0x36, 0x9b, 0x80, 0x0, 0x0,
    0x0, 0x1a, 0xdb, 0x97, 0x52, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x12,
    0x45, 0x79, 0xad, 0xd9, 0x11, 0xcf, 0xda, 0x98,
    0x76, 0x66, 0x68, 0x93, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,

    /* U+4F59 "余" */
    0x0, 0x0, 0x0, 0x9a, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xd, 0x90, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x8, 0x75, 0x70, 0x0, 0x0, 0x0, 0x0,
    0x5, 0xa0, 0x6, 0xa1, 0x0, 0x0, 0x0, 0x5,
    0xa0, 0x14, 0x68, 0xe6, 0x0, 0x0, 0x8, 0x72,
    0x9e, 0x84, 0x5, 0xef, 0xa5, 0x27, 0x20, 0x0,
    0x94, 0x24, 0x51, 0x11, 0x0, 0x2, 0x98, 0x8c,
    0xa8, 0x88, 0x40, 0x0, 0x0, 0x1, 0x0, 0x84,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xc2, 0x8, 0x42,
    0xd7, 0x0, 0x0, 0x0, 0x7c, 0x0, 0x84, 0x3,
    0xf7, 0x0, 0x0, 0x5, 0x10, 0x4b, 0x50, 0x4,
    0x70, 0x0, 0x0, 0x0, 0x7, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0x0, 0x0, 0x0,
    0x0,

    /* U+5149 "光" */
    0x0, 0x0, 0x0, 0xa7, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7, 0x70, 0x2e, 0x20, 0x0, 0x0,
    0x0, 0x60, 0x65, 0x1c, 0x70, 0x0, 0x0, 0x0,
    0xa, 0x66, 0x46, 0x10, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x63, 0x2, 0x42, 0x0, 0x0, 0x0, 0x13,
    0x6a, 0xb9, 0x98, 0x70, 0x0, 0x0, 0x69, 0x5b,
    0x1b, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe1,
    0xa3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x59, 0xb,
    0x0, 0x0, 0x1, 0x0, 0x0, 0x1d, 0x10, 0xb0,
    0x0, 0x0, 0x70, 0x0, 0xb, 0x40, 0xb, 0x10,
    0x0, 0xc, 0x20, 0x1a, 0x30, 0x0, 0x79, 0x21,
    0x28, 0xf5, 0x5, 0x0, 0x0, 0x0, 0x8e, 0xfe,
    0xc6, 0x0,

    /* U+5316 "化" */
    0x0, 0x0, 0x76, 0x1, 0xc1, 0x0, 0x0, 0x0,
    0x0, 0x9, 0xe0, 0xe, 0x20, 0x0, 0x0, 0x0,
    0x0, 0xe4, 0x0, 0xd0, 0x3, 0xb0, 0x0, 0x0,
    0x7a, 0x0, 0xc, 0x0, 0xdb, 0x10, 0x0, 0x2e,
    0x70, 0x0, 0xb0, 0xb7, 0x0, 0x0, 0xb, 0x3b,
    0x0, 0xc, 0xb5, 0x0, 0x0, 0x8, 0x40, 0xb0,
    0x3, 0xd2, 0x0, 0x0, 0x1, 0x20, 0xa, 0x5,
    0x5b, 0x0, 0x0, 0x1, 0x0, 0x0, 0xb0, 0x0,
    0xb0, 0x0, 0x0, 0x70, 0x0, 0x1b, 0x0, 0xb,
    0x0, 0x0, 0x1c, 0x0, 0x4, 0xb0, 0x0, 0x7a,
    0x54, 0x7e, 0xe0, 0x0, 0x3a, 0x0, 0x0, 0x6a,
    0xba, 0x72, 0x0, 0x0, 0x20, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+571F "土" */
    0x0, 0x0, 0x0, 0xba, 0x10, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x6, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3e, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2c, 0x4, 0x60, 0x0, 0x0, 0x0, 0x2,
    0x59, 0xff, 0xe9, 0x10, 0x0, 0x0, 0x1, 0x89,
    0x9c, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xa0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3a,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x90,
    0x13, 0x55, 0x10, 0x2, 0x34, 0x68, 0xbd, 0xbc,
    0xcc, 0xdd, 0x0, 0x9c, 0x85, 0x20, 0x0, 0x0,
    0x0, 0x0,

    /* U+58E4 "壤" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x97, 0x0, 0x0, 0x0,
    0x0, 0x97, 0x0, 0x1, 0x49, 0xbb, 0x0, 0x0,
    0x0, 0x6a, 0x3, 0x88, 0x52, 0x4, 0x10, 0x0,
    0x0, 0x48, 0x4, 0x59, 0x5b, 0x5c, 0x60, 0x0,
    0x0, 0x47, 0x26, 0x7b, 0x26, 0x65, 0x0, 0x0,
    0x5, 0xbd, 0x80, 0x37, 0xb, 0x84, 0x0, 0x0,
    0x1, 0x55, 0x1, 0x7c, 0x6b, 0x30, 0x0, 0x0,
    0x0, 0x55, 0x10, 0x6c, 0x7c, 0x51, 0x0, 0x0,
    0x0, 0x5a, 0x50, 0x1a, 0x6a, 0x89, 0x20, 0x0,
    0x39, 0xb1, 0x28, 0x8d, 0x60, 0x7a, 0x0, 0x0,
    0x36, 0x0, 0x3, 0xc7, 0x2b, 0x80, 0x0, 0x0,
    0x0, 0x0, 0x89, 0x29, 0x32, 0xad, 0x73, 0x0,
    0x0, 0x6, 0x20, 0x4d, 0x60, 0x6, 0xa9, 0x60,
    0x0, 0x0, 0x0, 0x86, 0x0, 0x0, 0x0, 0x0,

    /* U+5EA6 "度" */
    0x0, 0x0, 0x0, 0x1b, 0x70, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0x88, 0x94, 0x0, 0x0,
    0x0, 0x5, 0xc8, 0x96, 0x39, 0x20, 0x0, 0x0,
    0x0, 0x4, 0xa0, 0xa2, 0xb, 0x50, 0x0, 0x0,
    0x0, 0x5, 0x80, 0x77, 0x5d, 0x9a, 0x50, 0x0,
    0x0, 0x7, 0x85, 0x84, 0xb, 0x0, 0x0, 0x0,
    0x0, 0xa, 0x40, 0x68, 0x9c, 0x0, 0x0, 0x0,
    0x0, 0xd, 0x10, 0x8a, 0x37, 0x20, 0x0, 0x0,
    0x0, 0x2c, 0x2, 0x60, 0x3f, 0x60, 0x0, 0x0,
    0x0, 0x76, 0x0, 0x2a, 0xc7, 0x0, 0x0, 0x0,
    0x0, 0xc0, 0x0, 0x1b, 0xa4, 0x0, 0x0, 0x0,
    0x8, 0x40, 0x39, 0x92, 0x7, 0xc6, 0x30, 0x0,
    0x24, 0x2, 0x41, 0x0, 0x0, 0x5e, 0xfd, 0x80,

    /* U+5F3A "强" */
    0x0, 0x8, 0x31, 0x35, 0x7d, 0xc0, 0x0, 0x68,
    0xd9, 0x1d, 0x30, 0x89, 0x0, 0x0, 0xb, 0x0,
    0xa2, 0x4e, 0x20, 0x0, 0x0, 0xb0, 0x6, 0x9a,
    0x10, 0x0, 0xa, 0x76, 0x0, 0x2, 0xa1, 0x51,
    0x0, 0xa0, 0x0, 0x56, 0x7c, 0x6a, 0xf1, 0x19,
    0x66, 0xa, 0x22, 0x80, 0xc4, 0x7, 0x73, 0xf1,
    0x39, 0x8c, 0x98, 0x0, 0x0, 0xd, 0x0, 0x32,
    0x80, 0x0, 0x0, 0x1, 0xb0, 0x0, 0x27, 0xb,
    0x30, 0x0, 0x49, 0x3, 0x48, 0xc8, 0x7f, 0x20,
    0x8c, 0x51, 0xc8, 0x20, 0x0, 0x95, 0x3, 0xb0,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+6C27 "氧" */
    0x0, 0x0, 0xd5, 0x48, 0xab, 0x30, 0x0, 0x0,
    0x0, 0x58, 0x43, 0x24, 0x0, 0x0, 0x0, 0x0,
    0x19, 0x8, 0xba, 0x60, 0x0, 0x0, 0x0, 0x4,
    0x0, 0x14, 0x69, 0xcc, 0x0, 0x0, 0x0, 0x58,
    0x86, 0xa5, 0x7, 0xa0, 0x0, 0x0, 0x0, 0x75,
    0xd, 0x60, 0x85, 0x0, 0x0, 0x0, 0x4, 0xf9,
    0xb9, 0x18, 0x30, 0x0, 0x0, 0x1, 0x45, 0xd5,
    0x30, 0x75, 0x0, 0x0, 0x0, 0x5, 0x8d, 0x52,
    0x4, 0x80, 0x0, 0x0, 0x0, 0x13, 0xc5, 0xac,
    0x4d, 0x0, 0x1, 0xa, 0xa6, 0x3b, 0x0, 0x0,
    0x7b, 0x2, 0x50, 0x0, 0x0, 0xa0, 0x0, 0x0,
    0xae, 0xc7, 0x0, 0x0, 0x1a, 0x0, 0x0, 0x0,
    0x5c, 0x90, 0x0, 0x0, 0x80, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0,
    0x0,

    /* U+6C34 "水" */
    0x0, 0x0, 0x0, 0x8a, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3d, 0x0, 0x11, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2b, 0x0, 0x9f, 0x10, 0x0,
    0x0, 0x0, 0x34, 0x1a, 0x5, 0xd4, 0x0, 0x0,
    0x3, 0xba, 0xae, 0x2d, 0x7a, 0x10, 0x0, 0x0,
    0x0, 0x0, 0x87, 0x1a, 0x90, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xe1, 0x2a, 0x27, 0x0, 0x0, 0x0,
    0x0, 0x7, 0x80, 0x2a, 0x5, 0xb1, 0x0, 0x0,
    0x0, 0x2c, 0x0, 0x3a, 0x0, 0x8f, 0x94, 0x0,
    0x1, 0xa1, 0x0, 0x3b, 0x0, 0x8, 0xa9, 0x70,
    0x5, 0x0, 0x2, 0x6b, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7, 0xf9, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xa4, 0x0, 0x0, 0x0, 0x0,

    /* U+6D53 "浓" */
    0x0, 0x0, 0x0, 0x5c, 0x0, 0x0, 0x0, 0x4,
    0x30, 0x0, 0x5c, 0x0, 0x0, 0x0, 0x3, 0xe2,
    0x20, 0x8a, 0x7d, 0x90, 0x0, 0x0, 0x3, 0xa5,
    0xd1, 0xc, 0x60, 0x0, 0x10, 0x9, 0x53, 0x90,
    0x0, 0x0, 0x0, 0x8d, 0x2, 0xa, 0x80, 0xb,
    0x40, 0x0, 0x5, 0x0, 0x2a, 0x27, 0x6a, 0x10,
    0x0, 0x0, 0x40, 0xbc, 0x6, 0x90, 0x0, 0x0,
    0x5, 0x37, 0x5b, 0x0, 0xb6, 0x0, 0x0, 0xb,
    0x46, 0xa, 0x0, 0x1e, 0xa1, 0x0, 0x99, 0x20,
    0xb, 0x55, 0x3, 0xff, 0xb5, 0xa5, 0x0, 0x3f,
    0x80, 0x0, 0x2, 0x10, 0x11, 0x0, 0x5a, 0x0,
    0x0, 0x0, 0x0,

    /* U+6E29 "温" */
    0x1, 0x0, 0x0, 0x1, 0x6d, 0xa1, 0x0, 0x4,
    0xe2, 0x49, 0x66, 0x36, 0xf3, 0x0, 0x0, 0x62,
    0xb, 0x4, 0x35, 0xb0, 0x0, 0x0, 0x0, 0xb,
    0x54, 0x28, 0x50, 0x0, 0x77, 0x0, 0x8, 0x45,
    0x7d, 0x0, 0x0, 0x9, 0x0, 0x2, 0x31, 0x1,
    0x0, 0x0, 0x0, 0x50, 0x56, 0x65, 0x75, 0xb6,
    0x0, 0x1, 0x70, 0x92, 0x60, 0xa1, 0x9a, 0x0,
    0x8, 0x30, 0x53, 0x80, 0x90, 0xb2, 0x0, 0x4d,
    0x0, 0x35, 0x70, 0x70, 0xc0, 0x0, 0xb9, 0x0,
    0x28, 0x87, 0xba, 0xeb, 0x91, 0x55, 0x4a, 0x75,
    0x32, 0x10, 0x13, 0x51, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0,

    /* U+6E7F "湿" */
    0x0, 0x10, 0x0, 0x0, 0x27, 0xd8, 0x0, 0x0,
    0x7, 0xe2, 0xb6, 0x76, 0x5a, 0xf3, 0x0, 0x0,
    0x2, 0xa, 0x32, 0x53, 0x8b, 0x0, 0x0, 0x40,
    0x0, 0x6a, 0x54, 0x1b, 0x40, 0x0, 0xb, 0x90,
    0x3, 0x93, 0x67, 0xd0, 0x0, 0x0, 0x16, 0x0,
    0x7, 0x43, 0x33, 0x0, 0x0, 0x0, 0x6, 0x0,
    0x58, 0x1f, 0x8, 0x20, 0x0, 0x4, 0x51, 0x21,
    0xc0, 0xd1, 0xe4, 0x0, 0x0, 0xc0, 0xd, 0x1b,
    0xb, 0x73, 0x0, 0x0, 0x7a, 0x0, 0x40, 0xa0,
    0xa0, 0x0, 0x0, 0xf, 0x50, 0x0, 0x2b, 0x6d,
    0x9b, 0xc8, 0x0, 0x71, 0x7d, 0xa7, 0x54, 0x33,
    0x35, 0x60,

    /* U+7167 "照" */
    0x0, 0x0, 0x10, 0x3, 0x58, 0xbd, 0x20, 0x4,
    0xc6, 0xac, 0x17, 0xe2, 0x2f, 0x10, 0x2, 0xb0,
    0x3b, 0x1, 0xd0, 0x59, 0x0, 0x1, 0xc2, 0x3a,
    0x7, 0x55, 0xd3, 0x0, 0x0, 0xe8, 0x5a, 0x2a,
    0x3, 0x70, 0x0, 0x0, 0xc0, 0x3a, 0x73, 0x47,
    0xa6, 0x0, 0x0, 0xd3, 0x69, 0x1d, 0x10, 0x8c,
    0x0, 0x0, 0xd6, 0xb7, 0xb, 0x23, 0xc3, 0x0,
    0x0, 0x30, 0x31, 0x6, 0x75, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x0, 0x1, 0x0, 0xa, 0x0,
    0x79, 0x9, 0x90, 0x9, 0xb0, 0x4d, 0x0, 0x2,
    0x0, 0x20, 0x1, 0xe8, 0x58, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x45,

    /* U+78B3 "碳" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0xd1, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x50, 0xe0, 0x6b, 0x0,
    0x0, 0x0, 0x14, 0x61, 0xb0, 0xc2, 0xa6, 0x0,
    0x0, 0x48, 0xe8, 0x33, 0xc6, 0x63, 0x60, 0x0,
    0x0, 0x1, 0xd1, 0x0, 0x37, 0x4, 0x73, 0x0,
    0x0, 0x9, 0x77, 0x25, 0xbd, 0xa7, 0x41, 0x0,
    0x0, 0x4c, 0x5b, 0x60, 0xc0, 0xc1, 0x0, 0x0,
    0x0, 0xaa, 0xb, 0x5, 0x70, 0xd0, 0xe4, 0x0,
    0x7, 0x5c, 0xac, 0x1b, 0x64, 0xb6, 0x60, 0x0,
    0x46, 0x8, 0x0, 0xa3, 0x18, 0xc2, 0x0, 0x0,
    0x10, 0x0, 0x9, 0x40, 0xa, 0x2a, 0x10, 0x0,
    0x0, 0x0, 0x52, 0x0, 0x85, 0x4, 0xd4, 0x0,
    0x0, 0x0, 0x0, 0x38, 0x20, 0x0, 0x8f, 0xd7,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+7BB1 "箱" */
    0x0, 0x6, 0xa0, 0x0, 0x79, 0x25, 0x10, 0x0,
    0xba, 0x99, 0xa, 0x78, 0x61, 0x0, 0x58, 0x40,
    0x6, 0x37, 0x20, 0x0, 0x27, 0x16, 0x51, 0x20,
    0x24, 0x0, 0x0, 0x3, 0xc0, 0x0, 0x4, 0xa7,
    0x0, 0x0, 0x1c, 0x94, 0xc6, 0x44, 0xf1, 0x27,
    0xac, 0xa2, 0xb, 0x3, 0x1d, 0x1, 0x51, 0xc8,
    0x0, 0xab, 0xa2, 0xd0, 0x0, 0x89, 0xaa, 0x29,
    0x26, 0x1d, 0x0, 0x5a, 0x28, 0x0, 0xa4, 0x20,
    0xe0, 0x37, 0x4, 0x80, 0xb, 0x57, 0x3e, 0x10,
    0x0, 0x77, 0x0, 0xa2, 0x17, 0xf0, 0x0, 0x6,
    0x40, 0x0, 0x0, 0x1a, 0x0,

    /* U+91CF "量" */
    0x0, 0x0, 0xc9, 0x53, 0x1a, 0xb0, 0x0, 0x0,
    0x0, 0x4, 0x95, 0x71, 0xc5, 0x0, 0x0, 0x0,
    0x0, 0x8, 0x24, 0x7b, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x23, 0x11, 0x22, 0x46, 0x40, 0x16, 0x78,
    0x77, 0x77, 0x77, 0x77, 0x78, 0x20, 0x32, 0x2,
    0x35, 0x66, 0x83, 0x0, 0x0, 0x0, 0x1, 0xd2,
    0x4a, 0x37, 0xe0, 0x0, 0x0, 0x0, 0x8, 0x37,
    0x90, 0xa4, 0x0, 0x0, 0x0, 0x0, 0x38, 0x7a,
    0x57, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x97,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x26, 0x88, 0x20,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x97, 0xac,
    0xc3, 0x0, 0x0, 0x5a, 0x98, 0x65, 0x54, 0x43,
    0x10, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 64, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 211, .box_w = 13, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 78, .adv_w = 120, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 122, .adv_w = 120, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 150, .adv_w = 120, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 233, .adv_w = 120, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 316, .adv_w = 120, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 120, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 478, .adv_w = 256, .box_w = 15, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 546, .adv_w = 256, .box_w = 15, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 651, .adv_w = 256, .box_w = 15, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 749, .adv_w = 256, .box_w = 15, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 847, .adv_w = 256, .box_w = 15, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 937, .adv_w = 256, .box_w = 16, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1057, .adv_w = 256, .box_w = 16, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1161, .adv_w = 256, .box_w = 13, .box_h = 13, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1246, .adv_w = 256, .box_w = 15, .box_h = 15, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1359, .adv_w = 256, .box_w = 16, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1463, .adv_w = 256, .box_w = 14, .box_h = 13, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1554, .adv_w = 256, .box_w = 14, .box_h = 13, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1645, .adv_w = 256, .box_w = 15, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 1735, .adv_w = 256, .box_w = 14, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1826, .adv_w = 256, .box_w = 16, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1938, .adv_w = 256, .box_w = 13, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 2023, .adv_w = 256, .box_w = 15, .box_h = 13, .ofs_x = 1, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x5, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
    0x16, 0x17, 0x18, 0x19, 0x4e6c, 0x4f39, 0x5129, 0x52f6,
    0x56ff, 0x58c4, 0x5e86, 0x5f1a, 0x6c07, 0x6c14, 0x6d33, 0x6e09,
    0x6e5f, 0x7147, 0x7893, 0x7b91, 0x91af
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 37296, .glyph_id_start = 1,
        .unicode_list = (uint16_t *)unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 29, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = gylph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t S_text_font = {
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0)
    .underline_position = -2,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if S_TEXT_FONT*/
