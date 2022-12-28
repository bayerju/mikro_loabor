#ifndef FONT_H
#define	FONT_H

#include <stdint.h>

// font: variable Breite, H�he 8 Pixel
const unsigned char font[] = {
    1,0x00,                     // Space
    1,0x5E,                     // !
    3,0x06,0x00,0x06,			// "
    5,0x28,0x7C,0x28,0x7C,0x28, // #
    5,0x24,0x2A,0x7F,0x2A,0x10,	// $
    3,0x62,0x18,0x46,			// %
    5,0x30,0x4C,0x5A,0x24,0x50,	// &
    1,0x06,                     // '
    2,0x3C,0x42,                // (
    2,0x42,0x3C,                // )
    5,0x28,0x10,0x7C,0x10,0x28,	// *
    3,0x10,0x38,0x10,			// +
    1,0xC0,                     // ,
    3,0x10,0x10,0x10,			// -
    1,0x40,                     // .
    3,0x60,0x18,0x06,			// /
    4,0x3C,0x42,0x42,0x3C,		// 0
    3,0x44,0x7E,0x40,			// 1
    4,0x44,0x62,0x52,0x4C,		// 2
    3,0x4A,0x4A,0x34,			// 3
    4,0x1E,0x10,0x7C,0x10,		// 4
    3,0x4E,0x4A,0x32,			// 5
    4,0x3C,0x4A,0x4A,0x30,		// 6
    3,0x62,0x12,0x0E,			// 7
    4,0x34,0x4A,0x4A,0x34,		// 8
    4,0x0C,0x52,0x52,0x3C,		// 9
    1,0x48,                     // :
    2,0x80,0x68,                // ;
    3,0x10,0x28,0x44,			// <
    3,0x28,0x28,0x28,			// =
    3,0x44,0x28,0x10,			// >
    3,0x02,0x52,0x0C,			// ?
    5,0x3C,0x42,0x52,0x2A,0x3C,	// @
    4,0x7C,0x12,0x12,0x7C,		// A
    4,0x7E,0x4A,0x4A,0x34,		// B
    4,0x3C,0x42,0x42,0x24,		// C
    4,0x7E,0x42,0x42,0x3C,		// D
    3,0x7E,0x4A,0x4A,			// E
    3,0x7E,0x0A,0x0A,			// F
    4,0x3C,0x42,0x52,0x34,		// G
    4,0x7E,0x08,0x08,0x7E,		// H
    3,0x42,0x7E,0x42,			// I
    3,0x42,0x42,0x3E,			// J
    4,0x7E,0x08,0x14,0x62,      // K
    3,0x7E,0x40,0x40,			// L
    5,0x7E,0x04,0x08,0x04,0x7E,	// M
    5,0x7E,0x04,0x18,0x20,0x7E,	// N
    4,0x3C,0x42,0x42,0x3C,		// O
    4,0x7E,0x12,0x12,0x0C,		// P
    4,0x3C,0x42,0x42,0xBC,		// Q
    4,0x7E,0x12,0x12,0x6C,		// R
    4,0x44,0x4A,0x4A,0x30,		// S
    3,0x02,0x7E,0x02,			// T
    4,0x3E,0x40,0x40,0x3E,		// U
    5,0x06,0x18,0x60,0x18,0x06,	// V
    5,0x3E,0x40,0x3E,0x40,0x3E,	// W
    5,0x42,0x24,0x18,0x24,0x42,	// X
    4,0x9E,0xA0,0xA0,0x7E,		// Y
    4,0x62,0x52,0x4A,0x46,		// Z
    2,0x7E,0x42,                // [
    3,0x06,0x18,0x60,			// Backslash
    2,0x42,0x7E,                // ]
    3,0x20,0x10,0x20,			// ^
    4,0x80,0x80,0x80,0x80,		// _
    2,0x04,0x08,                // `
    4,0x20,0x54,0x54,0x78,		// a
    4,0x7E,0x44,0x44,0x38,		// b
    4,0x38,0x44,0x44,0x28,		// c
    4,0x38,0x44,0x44,0x7E,		// d
    4,0x38,0x54,0x54,0x58,		// e
    2,0x7C,0x0A,                // f
    4,0x98,0xA4,0xA4,0x7C,		// g
    4,0x7E,0x04,0x04,0x78,		// h
    1,0x7A,                     // i
    2,0x40,0x3A,                // j
    4,0x7E,0x10,0x28,0x44,		// k
    1,0x7E,                     // l
    5,0x7C,0x04,0x78,0x04,0x78,	// m
    4,0x7C,0x04,0x04,0x78,		// n
    4,0x38,0x44,0x44,0x38,		// o
    4,0xFC,0x24,0x24,0x18,		// p
    4,0x18,0x24,0x24,0xFC,		// q
    2,0x7C,0x04,                // r
    4,0x48,0x54,0x54,0x20,		// s
    3,0x04,0x3E,0x44,			// t
    4,0x3C,0x40,0x40,0x3C,      // u
    5,0x0C,0x30,0x40,0x30,0x0C,	// v
    5,0x3C,0x40,0x3C,0x40,0x3C,	// w
    5,0x44,0x28,0x10,0x28,0x44,	// x
    4,0x9C,0xA0,0xA0,0x7C,		// y
    3,0x64,0x54,0x4C,			// z
    3,0x08,0x36,0x41,			// {
    1,0xFF,                     // |
    3,0x41,0x36,0x08,           // }
    4,0x20,0x10,0x20,0x10,		// ~
 };

// font big: feste Breite 10 Pixel, H�he: 16 Pixel
const unsigned char font2 [][20] = {
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x20
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x1B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x21
    {0x00,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x22
    {0x00,0x01,0x20,0x19,0xA0,0x07,0x78,0x01,0x26,0x19,0xA0,0x07,0x78,0x01,0x26,0x01,0x20,0x01,0x00,0x00},	// 0x23
    {0x00,0x00,0x00,0x00,0x1C,0x18,0x26,0x10,0x42,0x10,0xFF,0x3F,0x82,0x11,0x02,0x0F,0x00,0x00,0x00,0x00},	// 0x24
    {0x1C,0x10,0x22,0x08,0x22,0x04,0x22,0x03,0x9C,0x00,0x40,0x0E,0x30,0x11,0x08,0x11,0x04,0x11,0x02,0x0E},	// 0x25
    {0x00,0x07,0x80,0x08,0x5C,0x10,0x62,0x10,0xA2,0x11,0x32,0x13,0x1C,0x1C,0x00,0x18,0x00,0x16,0x80,0x01},	// 0x26
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x27
    {0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0x07,0x18,0x18,0x0C,0x30,0x04,0x20,0x02,0x40,0x02,0x40,0x00,0x00},	// 0x28
    {0x00,0x00,0x02,0x40,0x02,0x40,0x04,0x20,0x0C,0x30,0x18,0x18,0xE0,0x07,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x29
    {0x00,0x00,0x08,0x00,0x18,0x00,0xF0,0x00,0x4E,0x00,0xF0,0x00,0x18,0x00,0x08,0x00,0x00,0x00,0x00,0x00},	// 0x2A
    {0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0xE0,0x1F,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x00},	// 0x2B
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x98,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x2C
    {0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00},	// 0x2D
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x2E
    {0x00,0x00,0x00,0x40,0x00,0x30,0x00,0x0C,0x00,0x03,0xC0,0x00,0x30,0x00,0x0C,0x00,0x02,0x00,0x00,0x00},	// 0x2F
    {0x00,0x00,0xF0,0x03,0x0C,0x0C,0x02,0x10,0x02,0x10,0x02,0x10,0x0C,0x0C,0xF0,0x03,0x00,0x00,0x00,0x00},	// 0x30
    {0x00,0x00,0x04,0x10,0x04,0x10,0x04,0x10,0xFE,0x1F,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x00,0x00,0x00},	// 0x31
    {0x00,0x00,0x06,0x18,0x02,0x14,0x02,0x12,0x02,0x11,0xC2,0x10,0x3C,0x10,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x32
    {0x00,0x00,0x00,0x00,0x02,0x10,0x42,0x10,0x42,0x10,0x42,0x10,0xBC,0x0F,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x33
    {0x00,0x03,0xC0,0x02,0x20,0x02,0x18,0x02,0x04,0x02,0xFE,0x1F,0x00,0x02,0x00,0x02,0x00,0x00,0x00,0x00},	// 0x34
    {0x00,0x00,0x00,0x00,0x3E,0x10,0x22,0x10,0x22,0x10,0x42,0x08,0x82,0x07,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x35
    {0x00,0x00,0xF0,0x07,0x4C,0x08,0x22,0x10,0x22,0x10,0x22,0x10,0x42,0x08,0x80,0x07,0x00,0x00,0x00,0x00},	// 0x36
    {0x00,0x00,0x02,0x00,0x02,0x18,0x02,0x07,0xC2,0x00,0x32,0x00,0x0A,0x00,0x06,0x00,0x00,0x00,0x00,0x00},	// 0x37
    {0x00,0x00,0x1C,0x0F,0xA2,0x10,0x42,0x10,0x42,0x10,0xA2,0x10,0xA2,0x09,0x1C,0x06,0x00,0x00,0x00,0x00},	// 0x38
    {0x00,0x00,0x78,0x00,0x84,0x10,0x02,0x11,0x02,0x11,0x02,0x11,0x84,0x0C,0xF8,0x03,0x00,0x00,0x00,0x00},	// 0x39
    {0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x18,0x60,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x3A
    {0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x98,0x60,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x3B
    {0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x80,0x04,0x80,0x04,0x40,0x08,0x40,0x08,0x20,0x10,0x00,0x00},	// 0x3C
    {0x00,0x00,0x80,0x04,0x80,0x04,0x80,0x04,0x80,0x04,0x80,0x04,0x80,0x04,0x80,0x04,0x80,0x04,0x00,0x00},	// 0x3D
    {0x00,0x00,0x20,0x10,0x40,0x08,0x40,0x08,0x80,0x04,0x80,0x04,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00},	// 0x3E
    {0x00,0x00,0x0E,0x00,0x02,0x00,0x02,0x1B,0x82,0x00,0x42,0x00,0x26,0x00,0x1C,0x00,0x00,0x00,0x00,0x00},	// 0x3F
    {0xF0,0x03,0x18,0x0C,0x04,0x18,0xE2,0x13,0x12,0x14,0x0A,0x16,0x8A,0x1B,0xFC,0x07,0x00,0x04,0x00,0x04},	// 0x40
    {0x00,0x10,0x00,0x0E,0x80,0x03,0x70,0x02,0x18,0x02,0x30,0x02,0xC0,0x02,0x00,0x03,0x00,0x0C,0x00,0x10},	// 0x41
    {0x00,0x00,0xF8,0x1F,0x88,0x10,0x88,0x10,0x88,0x10,0x88,0x10,0x48,0x11,0x30,0x0E,0x00,0x00,0x00,0x00},	// 0x42
    {0xC0,0x03,0x30,0x0C,0x10,0x08,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x18,0x10,0x00,0x00,0x00,0x00},	// 0x43
    {0x00,0x00,0xF8,0x1F,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x10,0x08,0xE0,0x07,0x00,0x00,0x00,0x00},	// 0x44
    {0x00,0x00,0xF8,0x1F,0x08,0x11,0x08,0x11,0x08,0x11,0x08,0x11,0x08,0x11,0x08,0x10,0x00,0x00,0x00,0x00},	// 0x45
    {0x00,0x00,0xF8,0x1F,0x08,0x01,0x08,0x01,0x08,0x01,0x08,0x01,0x08,0x01,0x08,0x00,0x00,0x00,0x00,0x00},	// 0x46
    {0x00,0x00,0xC0,0x03,0x30,0x0C,0x10,0x08,0x08,0x10,0x08,0x10,0x08,0x11,0x08,0x11,0x18,0x1F,0x00,0x00},	// 0x47
    {0x00,0x00,0xF8,0x1F,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0xF8,0x1F,0x00,0x00,0x00,0x00},	// 0x48
    {0x00,0x00,0x08,0x10,0x08,0x10,0x08,0x10,0xF8,0x1F,0x08,0x10,0x08,0x10,0x08,0x10,0x00,0x00,0x00,0x00},	// 0x49
    {0x00,0x00,0x00,0x00,0x00,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0xF8,0x0F,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x4A
    {0x00,0x00,0xF8,0x1F,0x80,0x00,0x80,0x01,0x40,0x02,0x20,0x04,0x10,0x04,0x08,0x08,0x00,0x10,0x00,0x00},	// 0x4B
    {0x00,0x00,0xF8,0x1F,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x00,0x00,0x00},	// 0x4C
    {0xF8,0x1F,0x38,0x00,0xE0,0x01,0x00,0x07,0x00,0x06,0xC0,0x01,0x38,0x00,0xF8,0x1F,0x00,0x00,0x00,0x00},	// 0x4D
    {0x00,0x00,0xF8,0x1F,0x10,0x00,0x60,0x00,0x80,0x01,0x00,0x06,0x00,0x08,0xF8,0x1F,0x00,0x00,0x00,0x00},	// 0x4E
    {0x00,0x00,0xE0,0x07,0x10,0x08,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x10,0x10,0x08,0xE0,0x07,0x00,0x00},	// 0x4F
    {0x00,0x00,0xF8,0x1F,0x08,0x01,0x08,0x01,0x08,0x01,0x08,0x01,0x88,0x00,0x70,0x00,0x00,0x00,0x00,0x00},	// 0x50
    {0x00,0x00,0xE0,0x07,0x10,0x08,0x08,0x10,0x08,0x10,0x08,0x10,0x08,0x30,0x10,0x48,0xE0,0x47,0x00,0x00},	// 0x51
    {0x00,0x00,0xF8,0x1F,0x08,0x01,0x08,0x01,0x08,0x03,0x88,0x04,0x70,0x08,0x00,0x10,0x00,0x00,0x00,0x00},	// 0x52
    {0x00,0x00,0x70,0x18,0x48,0x10,0x88,0x10,0x88,0x10,0x08,0x11,0x08,0x09,0x18,0x0E,0x00,0x00,0x00,0x00},	// 0x53
    {0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0xF8,0x1F,0x08,0x00,0x08,0x00,0x08,0x00,0x08,0x00,0x00,0x00},	// 0x54
    {0x00,0x00,0xF8,0x07,0x00,0x18,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x08,0xF8,0x07,0x00,0x00,0x00,0x00},	// 0x55
    {0x08,0x00,0x30,0x00,0xC0,0x01,0x00,0x06,0x00,0x18,0x00,0x18,0x00,0x07,0xC0,0x00,0x30,0x00,0x08,0x00},	// 0x56
    {0x18,0x00,0xE0,0x03,0x00,0x1C,0x00,0x0F,0xE0,0x00,0xC0,0x01,0x00,0x0E,0x00,0x1C,0xE0,0x03,0x18,0x00},	// 0x57
    {0x08,0x10,0x10,0x08,0x20,0x04,0x40,0x02,0x80,0x01,0x80,0x01,0x40,0x02,0x20,0x04,0x10,0x08,0x08,0x10},	// 0x58
    {0x08,0x00,0x10,0x00,0x60,0x00,0x80,0x00,0x00,0x1F,0x80,0x00,0x40,0x00,0x20,0x00,0x10,0x00,0x08,0x00},	// 0x59
    {0x00,0x00,0x08,0x18,0x08,0x14,0x08,0x12,0x08,0x11,0x88,0x10,0x48,0x10,0x28,0x10,0x18,0x10,0x00,0x00},	// 0x5A
    {0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x7F,0x02,0x40,0x02,0x40,0x02,0x40,0x02,0x40,0x00,0x00,0x00,0x00},	// 0x5B
    {0x00,0x00,0x02,0x00,0x0C,0x00,0x30,0x00,0xC0,0x00,0x00,0x03,0x00,0x0C,0x00,0x30,0x00,0x40,0x00,0x00},	// 0x5C
    {0x00,0x00,0x02,0x40,0x02,0x40,0x02,0x40,0x02,0x40,0xFE,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x5D
    {0x00,0x00,0x00,0x04,0x00,0x03,0xE0,0x00,0x38,0x00,0x0E,0x00,0x70,0x00,0x80,0x03,0x00,0x04,0x00,0x00},	// 0x5E
    {0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0x20},	// 0x5F
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x60
    {0x00,0x00,0x00,0x0C,0x20,0x12,0x20,0x11,0x20,0x11,0x20,0x09,0xC0,0x1F,0x00,0x10,0x00,0x00,0x00,0x00},	// 0x61
    {0x00,0x00,0xFE,0x1F,0x40,0x08,0x20,0x10,0x20,0x10,0x20,0x10,0x60,0x08,0x80,0x07,0x00,0x00,0x00,0x00},	// 0x62
    {0x00,0x00,0x80,0x07,0x40,0x08,0x20,0x10,0x20,0x10,0x20,0x10,0x20,0x10,0x20,0x10,0x00,0x00,0x00,0x00},	// 0x63
    {0x00,0x00,0x80,0x07,0x40,0x18,0x20,0x10,0x20,0x10,0x20,0x10,0x40,0x08,0xFE,0x1F,0x00,0x00,0x00,0x00},	// 0x64
    {0x00,0x00,0x80,0x07,0x40,0x09,0x20,0x11,0x20,0x11,0x20,0x11,0x20,0x11,0xC0,0x11,0x00,0x00,0x00,0x00},	// 0x65
    {0x00,0x00,0x20,0x00,0x20,0x00,0xFC,0x1F,0x24,0x00,0x22,0x00,0x22,0x00,0x22,0x00,0x22,0x00,0x00,0x00},	// 0x66
    {0x00,0x00,0x80,0x07,0x40,0x98,0x20,0x90,0x20,0x90,0x20,0x90,0x40,0x48,0xE0,0x3F,0x00,0x00,0x00,0x00},	// 0x67
    {0x00,0x00,0xFE,0x1F,0x80,0x00,0x40,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0xC0,0x1F,0x00,0x00,0x00,0x00},	// 0x68
    {0x00,0x00,0x20,0x00,0x20,0x00,0x26,0x00,0xE6,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x69
    {0x00,0x00,0x00,0x80,0x20,0x80,0x20,0x80,0x26,0x80,0xE6,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x6A
    {0x00,0x00,0xFE,0x1F,0x00,0x01,0x00,0x03,0x80,0x04,0x40,0x04,0x40,0x08,0x20,0x10,0x00,0x00,0x00,0x00},	// 0x6B
    {0x00,0x00,0x00,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0xFE,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x6C
    {0xE0,0x1F,0x40,0x00,0x20,0x00,0x20,0x00,0xC0,0x1F,0x40,0x00,0x20,0x00,0x20,0x00,0xC0,0x1F,0x00,0x00},	// 0x6D
    {0x00,0x00,0xE0,0x1F,0xC0,0x00,0x40,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0xC0,0x1F,0x00,0x00,0x00,0x00},	// 0x6E
    {0x00,0x00,0x80,0x07,0x40,0x08,0x20,0x10,0x20,0x10,0x20,0x10,0x40,0x08,0x80,0x07,0x00,0x00,0x00,0x00},	// 0x6F
    {0x00,0x00,0xE0,0xFF,0x40,0x08,0x20,0x10,0x20,0x10,0x20,0x10,0x60,0x08,0x80,0x07,0x00,0x00,0x00,0x00},	// 0x70
    {0x00,0x00,0x80,0x07,0x40,0x18,0x20,0x10,0x20,0x10,0x20,0x10,0x40,0x08,0xE0,0xFF,0x00,0x00,0x00,0x00},	// 0x71
    {0x00,0x00,0x00,0x00,0xE0,0x1F,0x80,0x00,0x40,0x00,0x20,0x00,0x20,0x00,0xE0,0x00,0x00,0x00,0x00,0x00},	// 0x72
    {0x00,0x00,0xC0,0x18,0x20,0x11,0x20,0x11,0x20,0x12,0x20,0x12,0x20,0x0C,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x73
    {0x00,0x00,0x20,0x00,0x20,0x00,0xF8,0x0F,0x20,0x10,0x20,0x10,0x20,0x10,0x20,0x10,0x00,0x00,0x00,0x00},	// 0x74
    {0x00,0x00,0xE0,0x0F,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x08,0xE0,0x1F,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x75
    {0x20,0x00,0xC0,0x01,0x00,0x06,0x00,0x18,0x00,0x10,0x00,0x0C,0x00,0x03,0xC0,0x00,0x20,0x00,0x00,0x00},	// 0x76
    {0x60,0x00,0x80,0x07,0x00,0x18,0x00,0x0E,0xC0,0x01,0x80,0x01,0x00,0x0E,0x00,0x18,0x80,0x07,0x60,0x00},	// 0x77
    {0x00,0x00,0x20,0x10,0x40,0x08,0x80,0x04,0x00,0x03,0x00,0x03,0x80,0x04,0x40,0x08,0x20,0x10,0x00,0x00},	// 0x78
    {0x20,0x80,0xC0,0x80,0x00,0x83,0x00,0x46,0x00,0x38,0x00,0x18,0x00,0x06,0x00,0x01,0xC0,0x00,0x20,0x00},	// 0x79
    {0x00,0x00,0x20,0x10,0x20,0x18,0x20,0x14,0x20,0x12,0x20,0x11,0xA0,0x10,0x60,0x10,0x20,0x10,0x00,0x00},	// 0x7A
    {0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0xFC,0x3E,0x02,0x40,0x02,0x40,0x02,0x40,0x00,0x00,0x00,0x00},	// 0x7B
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFE,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x7C
    {0x00,0x00,0x00,0x00,0x02,0x40,0x02,0x40,0x02,0x40,0xFC,0x3E,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00},	// 0x7D
    {0x00,0x03,0x80,0x00,0x80,0x00,0x80,0x00,0x00,0x01,0x00,0x01,0x00,0x02,0x00,0x02,0x00,0x02,0x80,0x01},	// 0x7E
    {0x00,0x00,0x80,0x1F,0xC0,0x10,0x20,0x10,0x10,0x10,0x20,0x10,0xC0,0x10,0x80,0x1F,0x00,0x00,0x00,0x00},	// 0x7F
    {0xC0,0x03,0x30,0x0C,0x10,0x08,0x08,0x10,0x08,0x10,0x08,0x90,0x08,0xB0,0x18,0xD0,0x00,0x00,0x00,0x00},	// 0x80
    {0x00,0x00,0xE0,0x0F,0x04,0x10,0x00,0x10,0x00,0x10,0x04,0x08,0xE0,0x1F,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x81
    {0x00,0x00,0x80,0x07,0x40,0x09,0x20,0x11,0x24,0x11,0x22,0x11,0x20,0x11,0xC0,0x11,0x00,0x00,0x00,0x00},	// 0x82
    {0x00,0x00,0x00,0x0C,0x24,0x12,0x22,0x11,0x22,0x11,0x24,0x09,0xC0,0x1F,0x00,0x10,0x00,0x00,0x00,0x00},	// 0x83
    {0x00,0x00,0x00,0x0C,0x24,0x12,0x20,0x11,0x20,0x11,0x24,0x09,0xC0,0x1F,0x00,0x10,0x00,0x00,0x00,0x00},	// 0x84
    {0x00,0x00,0x00,0x0C,0x22,0x12,0x24,0x11,0x20,0x11,0x20,0x09,0xC0,0x1F,0x00,0x10,0x00,0x00,0x00,0x00},	// 0x85
    {0x00,0x00,0x00,0x0C,0x20,0x12,0x22,0x11,0x25,0x11,0x22,0x09,0xC0,0x1F,0x00,0x10,0x00,0x00,0x00,0x00},	// 0x86
    {0x00,0x00,0x80,0x07,0x40,0x08,0x20,0x10,0x20,0x90,0x20,0xB0,0x20,0xD0,0x20,0x10,0x00,0x00,0x00,0x00},	// 0x87
    {0x00,0x00,0x80,0x07,0x44,0x09,0x22,0x11,0x22,0x11,0x24,0x11,0x20,0x11,0xC0,0x11,0x00,0x00,0x00,0x00},	// 0x88
    {0x00,0x00,0x80,0x07,0x40,0x09,0x24,0x11,0x20,0x11,0x20,0x11,0x24,0x11,0xC0,0x11,0x00,0x00,0x00,0x00},	// 0x89
    {0x00,0x00,0x80,0x07,0x40,0x09,0x22,0x11,0x24,0x11,0x20,0x11,0x20,0x11,0xC0,0x11,0x00,0x00,0x00,0x00},	// 0x8A
    {0x00,0x00,0x20,0x00,0x24,0x00,0x20,0x00,0xE0,0x1F,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x8B
    {0x00,0x00,0x20,0x00,0x24,0x00,0x22,0x00,0xE2,0x1F,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x8C
    {0x00,0x00,0x20,0x00,0x20,0x00,0x22,0x00,0xE4,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x8D
    {0x00,0x10,0x00,0x0E,0x81,0x03,0x70,0x02,0x18,0x02,0x30,0x02,0xC1,0x02,0x00,0x03,0x00,0x0C,0x00,0x10},	// 0x8E
    {0x00,0x10,0x00,0x0E,0x80,0x03,0x72,0x02,0x0D,0x02,0x1D,0x02,0xF2,0x02,0x80,0x03,0x00,0x0E,0x00,0x10},	// 0x8F
    {0x00,0x00,0xF8,0x1F,0x08,0x11,0x08,0x11,0x0A,0x11,0x09,0x11,0x08,0x11,0x08,0x10,0x00,0x00,0x00,0x00},	// 0x90
    {0x20,0x0E,0x20,0x13,0x20,0x11,0x20,0x11,0xC0,0x0F,0x20,0x19,0x20,0x11,0x20,0x11,0xC0,0x11,0x00,0x00},	// 0x91
    {0x00,0x10,0x00,0x0C,0x80,0x07,0x60,0x04,0x18,0x04,0xF8,0x1F,0x08,0x11,0x08,0x11,0x08,0x10,0x00,0x00},	// 0x92
    {0x00,0x00,0x80,0x07,0x44,0x08,0x22,0x10,0x22,0x10,0x24,0x10,0x40,0x08,0x80,0x07,0x00,0x00,0x00,0x00},	// 0x93
    {0x00,0x00,0x80,0x07,0x44,0x08,0x20,0x10,0x20,0x10,0x24,0x10,0x40,0x08,0x80,0x07,0x00,0x00,0x00,0x00},	// 0x94
    {0x00,0x00,0x80,0x07,0x42,0x08,0x24,0x10,0x20,0x10,0x20,0x10,0x40,0x08,0x80,0x07,0x00,0x00,0x00,0x00},	// 0x95
    {0x00,0x00,0xE0,0x0F,0x04,0x10,0x02,0x10,0x02,0x10,0x04,0x08,0xE0,0x1F,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x96
    {0x00,0x00,0xE0,0x0F,0x02,0x10,0x04,0x10,0x00,0x10,0x00,0x08,0xE0,0x1F,0x00,0x00,0x00,0x00,0x00,0x00},	// 0x97
    {0x20,0x80,0xC0,0x80,0x04,0x83,0x00,0x46,0x00,0x38,0x04,0x18,0x00,0x06,0x00,0x01,0xC0,0x00,0x20,0x00},	// 0x98
    {0x00,0x00,0xE0,0x07,0x11,0x08,0x08,0x10,0x08,0x10,0x08,0x10,0x09,0x10,0x10,0x08,0xE0,0x07,0x00,0x00},	// 0x99
    {0x00,0x00,0xF8,0x07,0x01,0x18,0x00,0x10,0x00,0x10,0x00,0x10,0x01,0x08,0xF8,0x07,0x00,0x00,0x00,0x00},	// 0x9A
    {0x00,0x00,0x80,0x17,0x40,0x08,0x20,0x14,0x20,0x13,0xA0,0x10,0x40,0x08,0xA0,0x07,0x00,0x00,0x00,0x00},	// 0x9B
    {0x00,0x00,0x00,0x00,0x00,0x10,0x40,0x18,0xFC,0x17,0x42,0x10,0x42,0x10,0x02,0x10,0x00,0x00,0x00,0x00},	// 0x9C
    {0x00,0x00,0xE0,0x17,0x10,0x0C,0x08,0x16,0x08,0x11,0x88,0x10,0x68,0x10,0x30,0x08,0xE8,0x07,0x00,0x00},	// 0x9D
    {0x00,0x00,0x20,0x10,0x40,0x08,0x80,0x04,0x00,0x03,0x00,0x03,0x80,0x04,0x40,0x08,0x20,0x10,0x00,0x00},	// 0x9E
    {0x00,0x00,0x00,0x80,0x20,0x80,0x20,0x80,0xFE,0x7F,0x21,0x00,0x21,0x00,0x01,0x00,0x00,0x00,0x00,0x00},	// 0x9F
    {0x00,0x00,0x00,0x0C,0x20,0x12,0x20,0x11,0x24,0x11,0x22,0x09,0xC0,0x1F,0x00,0x10,0x00,0x00,0x00,0x00},	// 0xA0
    {0x00,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0xE4,0x1F,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xA1
    {0x00,0x00,0x80,0x07,0x40,0x08,0x20,0x10,0x24,0x10,0x22,0x10,0x40,0x08,0x80,0x07,0x00,0x00,0x00,0x00},	// 0xA2
    {0x00,0x00,0xE0,0x0F,0x00,0x10,0x00,0x10,0x04,0x10,0x02,0x08,0xE0,0x1F,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xA3
    {0x00,0x00,0xE0,0x1F,0xC4,0x00,0x42,0x00,0x24,0x00,0x24,0x00,0x22,0x00,0xC0,0x1F,0x00,0x00,0x00,0x00},	// 0xA4
    {0x00,0x00,0xF8,0x1F,0x12,0x00,0x61,0x00,0x83,0x01,0x02,0x06,0x01,0x08,0xF8,0x1F,0x00,0x00,0x00,0x00},	// 0xA5
    {0x00,0x00,0x00,0x00,0x32,0x00,0x4A,0x00,0x4A,0x00,0x4A,0x00,0x7C,0x00,0x40,0x00,0x00,0x00,0x00,0x00},	// 0xA6
    {0x00,0x00,0x00,0x00,0x3C,0x00,0x42,0x00,0x42,0x00,0x42,0x00,0x42,0x00,0x3C,0x00,0x00,0x00,0x00,0x00},	// 0xA7
    {0x00,0x00,0x00,0x70,0x00,0xC8,0x00,0x88,0x00,0x84,0x60,0x83,0x00,0x80,0x00,0xE0,0x00,0x00,0x00,0x00},	// 0xA8
    {0x00,0x00,0x38,0x00,0x44,0x00,0xBA,0x00,0xAA,0x00,0xBA,0x00,0x44,0x00,0x38,0x00,0x00,0x00,0x00,0x00},	// 0xA9
    {0x00,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x07,0x00,0x00},	// 0xAA
    {0x02,0x10,0x7E,0x0C,0x00,0x02,0x80,0x01,0x60,0x00,0x10,0x00,0x8C,0x10,0x82,0x1C,0x80,0x14,0x00,0x13},	// 0xAB
    {0x02,0x10,0x7E,0x0C,0x00,0x02,0x80,0x01,0x60,0x00,0x10,0x06,0x0C,0x05,0x82,0x04,0x80,0x1F,0x00,0x04},	// 0xAC
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xAD
    {0x00,0x00,0x00,0x01,0x80,0x02,0x40,0x04,0x20,0x08,0x00,0x01,0x80,0x02,0x40,0x04,0x20,0x08,0x00,0x00},	// 0xAE
    {0x00,0x00,0x20,0x08,0x40,0x04,0x80,0x02,0x00,0x01,0x20,0x08,0x40,0x04,0x80,0x02,0x00,0x01,0x00,0x00},	// 0xAF
    {0xDB,0x6C,0xDB,0x6C,0x00,0x00,0xDB,0x6C,0xDB,0x6C,0x00,0x00,0xDB,0x6C,0xDB,0x6C,0x00,0x00,0x00,0x00},	// 0xB0
    {0x6C,0xDB,0x6C,0xDB,0xDB,0x6C,0xFF,0xFF,0x6C,0xDB,0xDB,0x6C,0xFF,0xFF,0x6C,0xDB,0xDB,0x6C,0xDB,0x6C},	// 0xB1
    {0xFF,0xFF,0xFF,0xFF,0xDB,0x6C,0xFF,0xFF,0xFF,0xFF,0xDB,0x6C,0xFF,0xFF,0xFF,0xFF,0xDB,0x6C,0xDB,0x6C},	// 0xB2
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xB3
    {0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xB4
    {0x00,0x10,0x00,0x0E,0x80,0x03,0x70,0x02,0x1A,0x02,0x31,0x02,0xC0,0x02,0x00,0x03,0x00,0x0C,0x00,0x10},	// 0xB5
    {0x00,0x10,0x00,0x0E,0x80,0x03,0x72,0x02,0x19,0x02,0x31,0x02,0xC2,0x02,0x00,0x03,0x00,0x0C,0x00,0x10},	// 0xB6
    {0x00,0x10,0x00,0x0E,0x80,0x03,0x71,0x02,0x1A,0x02,0x30,0x02,0xC0,0x02,0x00,0x03,0x00,0x0C,0x00,0x10},	// 0xB7
    {0xF0,0x03,0x0C,0x0C,0xE6,0x19,0x32,0x13,0x12,0x12,0x12,0x12,0x16,0x1A,0x0C,0x0C,0xF0,0x03,0x00,0x00},	// 0xB8
    {0x80,0x02,0x80,0x02,0x80,0x02,0xFF,0xFE,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xB9
    {0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xBA
    {0x80,0x02,0x80,0x02,0x80,0x02,0x80,0xFE,0x80,0x00,0x80,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xBB
    {0x80,0x02,0x80,0x02,0x80,0x02,0xFF,0x02,0x00,0x02,0xFF,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xBC
    {0x00,0x00,0xF0,0x03,0x08,0x04,0x04,0x0C,0x04,0x08,0xFE,0x1F,0x04,0x08,0x04,0x08,0x00,0x00,0x00,0x00},	// 0xBD
    {0x02,0x00,0x04,0x00,0x98,0x04,0xA0,0x04,0xC0,0x1F,0xA0,0x04,0x90,0x04,0x08,0x00,0x04,0x00,0x02,0x00},	// 0xBE
    {0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xBF
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01},	// 0xC0
    {0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0xFF,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01},	// 0xC1
    {0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0xFF,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01},	// 0xC2
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01},	// 0xC3
    {0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01},	// 0xC4
    {0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0xFF,0xFF,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01},	// 0xC5
    {0x00,0x00,0x00,0x0C,0x24,0x12,0x22,0x11,0x24,0x11,0x24,0x09,0xC2,0x1F,0x00,0x10,0x00,0x00,0x00,0x00},	// 0xC6
    {0x00,0x10,0x00,0x0E,0x82,0x03,0x71,0x02,0x1B,0x02,0x32,0x02,0xC1,0x02,0x00,0x03,0x00,0x0C,0x00,0x10},	// 0xC7
    {0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x03,0x00,0x02,0xFF,0x02,0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02},	// 0xC8
    {0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xFF,0x80,0x00,0x80,0xFE,0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02},	// 0xC9
    {0x80,0x02,0x80,0x02,0x80,0x02,0xFF,0x02,0x00,0x02,0xFF,0x02,0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02},	// 0xCA
    {0x80,0x02,0x80,0x02,0x80,0x02,0x80,0xFE,0x80,0x00,0x80,0xFE,0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02},	// 0xCB
    {0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFE,0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02},	// 0xCC
    {0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02},	// 0xCD
    {0x80,0x02,0x80,0x02,0x80,0x02,0xFF,0xFE,0x00,0x00,0xFF,0xFE,0x80,0x02,0x80,0x02,0x80,0x02,0x80,0x02},	// 0xCE
    {0x00,0x00,0x08,0x04,0xF0,0x03,0x10,0x02,0x10,0x02,0x10,0x02,0x10,0x02,0xF0,0x03,0x08,0x04,0x00,0x00},	// 0xCF
    {0x00,0x00,0x82,0x07,0x4A,0x08,0x2E,0x10,0x24,0x10,0x2A,0x10,0x70,0x08,0xC0,0x07,0x00,0x00,0x00,0x00},	// 0xD0
    {0x80,0x00,0xF8,0x1F,0x88,0x10,0x88,0x10,0x08,0x10,0x08,0x10,0x10,0x08,0xE0,0x07,0x00,0x00,0x00,0x00},	// 0xD1
    {0x00,0x00,0xF8,0x1F,0x08,0x11,0x0A,0x11,0x09,0x11,0x09,0x11,0x0A,0x11,0x08,0x10,0x00,0x00,0x00,0x00},	// 0xD2
    {0x00,0x00,0xF8,0x1F,0x09,0x11,0x08,0x11,0x08,0x11,0x08,0x11,0x09,0x11,0x08,0x10,0x00,0x00,0x00,0x00},	// 0xD3
    {0x00,0x00,0xF8,0x1F,0x08,0x11,0x08,0x11,0x09,0x11,0x0A,0x11,0x08,0x11,0x08,0x10,0x00,0x00,0x00,0x00},	// 0xD4
    {0x00,0x00,0x20,0x00,0x20,0x00,0x20,0x00,0xE0,0x1F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xD5
    {0x00,0x00,0x08,0x10,0x08,0x10,0x08,0x10,0xFA,0x1F,0x09,0x10,0x08,0x10,0x08,0x10,0x00,0x00,0x00,0x00},	// 0xD6
    {0x00,0x00,0x08,0x10,0x08,0x10,0x0A,0x10,0xF9,0x1F,0x09,0x10,0x0A,0x10,0x08,0x10,0x00,0x00,0x00,0x00},	// 0xD7
    {0x00,0x00,0x08,0x10,0x09,0x10,0x08,0x10,0xF8,0x1F,0x08,0x10,0x09,0x10,0x08,0x10,0x00,0x00,0x00,0x00},	// 0xD8
    {0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0xFF,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xD9
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01},	// 0xDA
    {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},	// 0xDB
    {0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF},	// 0xDC
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xDD
    {0x00,0x00,0x08,0x10,0x08,0x10,0x09,0x10,0xFA,0x1F,0x08,0x10,0x08,0x10,0x08,0x10,0x00,0x00,0x00,0x00},	// 0xDE
    {0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00},	// 0xDF
    {0x00,0x00,0xE0,0x07,0x10,0x08,0x08,0x10,0x0A,0x10,0x09,0x10,0x08,0x10,0x10,0x08,0xE0,0x07,0x00,0x00},	// 0xE0
    {0x00,0x00,0xFC,0x1F,0x02,0x00,0x02,0x00,0xE2,0x10,0x1C,0x11,0x00,0x12,0x00,0x0C,0x00,0x00,0x00,0x00},	// 0xE1
    {0x00,0x00,0xE0,0x07,0x10,0x08,0x0A,0x10,0x09,0x10,0x09,0x10,0x0A,0x10,0x10,0x08,0xE0,0x07,0x00,0x00},	// 0xE2
    {0x00,0x00,0xE0,0x07,0x10,0x08,0x09,0x10,0x0A,0x10,0x08,0x10,0x08,0x10,0x10,0x08,0xE0,0x07,0x00,0x00},	// 0xE3
    {0x00,0x00,0x80,0x07,0x44,0x08,0x22,0x10,0x24,0x10,0x24,0x10,0x42,0x08,0x80,0x07,0x00,0x00,0x00,0x00},	// 0xE4
    {0x00,0x00,0xE0,0x07,0x12,0x08,0x09,0x10,0x0B,0x10,0x0A,0x10,0x09,0x10,0x10,0x08,0xE0,0x07,0x00,0x00},	// 0xE5
    {0x00,0x00,0xE0,0xFF,0x00,0x08,0x00,0x10,0x00,0x10,0x00,0x10,0x00,0x08,0xE0,0x1F,0x00,0x00,0x00,0x00},	// 0xE6
    {0x00,0x00,0xFE,0xFF,0x40,0x08,0x20,0x10,0x20,0x10,0x20,0x10,0x60,0x08,0x80,0x07,0x00,0x00,0x00,0x00},	// 0xE7
    {0x00,0x00,0xF8,0x1F,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x04,0x20,0x02,0xC0,0x01,0x00,0x00,0x00,0x00},	// 0xE8
    {0x00,0x00,0xF8,0x07,0x00,0x18,0x00,0x10,0x02,0x10,0x01,0x10,0x00,0x08,0xF8,0x07,0x00,0x00,0x00,0x00},	// 0xE9
    {0x00,0x00,0xF8,0x07,0x00,0x18,0x02,0x10,0x01,0x10,0x01,0x10,0x02,0x08,0xF8,0x07,0x00,0x00,0x00,0x00},	// 0xEA
    {0x00,0x00,0xF8,0x07,0x00,0x18,0x01,0x10,0x02,0x10,0x00,0x10,0x00,0x08,0xF8,0x07,0x00,0x00,0x00,0x00},	// 0xEB
    {0x20,0x80,0xC0,0x80,0x00,0x83,0x00,0x46,0x04,0x38,0x02,0x18,0x00,0x06,0x00,0x01,0xC0,0x00,0x20,0x00},	// 0xEC
    {0x08,0x00,0x10,0x00,0x60,0x00,0x80,0x00,0x02,0x1F,0x81,0x00,0x40,0x00,0x20,0x00,0x10,0x00,0x08,0x00},	// 0xED
    {0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00},	// 0xEE
    {0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xEF
    {0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00},	// 0xF0
    {0x00,0x00,0x80,0x10,0x80,0x10,0x80,0x10,0x80,0x10,0xE0,0x13,0x80,0x10,0x80,0x10,0x80,0x10,0x00,0x00},	// 0xF1
    {0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0xA0,0x00,0xA0},	// 0xF2
    {0x42,0x10,0x4A,0x08,0x5A,0x04,0x36,0x03,0x80,0x00,0x40,0x06,0x30,0x05,0x88,0x04,0x84,0x1F,0x02,0x04},	// 0xF3
    {0x00,0x00,0x1C,0x00,0x3E,0x00,0x7E,0x00,0xFE,0x7F,0x02,0x00,0x02,0x00,0xFE,0x7F,0x00,0x00,0x00,0x00},	// 0xF4
    {0x00,0x00,0x00,0x00,0xDC,0x61,0x32,0x43,0x22,0x42,0x62,0x46,0x42,0x4C,0x82,0x3B,0x00,0x00,0x00,0x00},	// 0xF5
    {0x00,0x00,0x00,0x02,0x00,0x02,0x00,0x02,0x60,0x1A,0x60,0x1A,0x00,0x02,0x00,0x02,0x00,0x02,0x00,0x00},	// 0xF6
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x00,0xA0,0x00,0xC0,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xF7
    {0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x12,0x00,0x12,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xF8
    {0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xF9
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xFA
    {0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xFB
    {0x00,0x00,0x00,0x00,0x42,0x00,0x4A,0x00,0x4A,0x00,0x4A,0x00,0x36,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xFC
    {0x00,0x00,0x00,0x00,0x42,0x00,0x62,0x00,0x52,0x00,0x52,0x00,0x4C,0x00,0x00,0x00,0x00,0x00,0x00,0x00},	// 0xFD
    {0x00,0x00,0xE0,0x1F,0xE0,0x1F,0xE0,0x1F,0xE0,0x1F,0xE0,0x1F,0xE0,0x1F,0xE0,0x1F,0xE0,0x1F,0x00,0x00},	// 0xFE
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00} 	// 0xFF
};

#endif	// FONT_H
