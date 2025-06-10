#ifndef UTILS_h
#define UTILS_h

#include "utils/types.h"
#include "utils/maths.h"

// color parsing
#define U_CLR_R(clr_rgba) (u8)((clr_rgba & 0xff000000) >> 8 * 3)
#define U_CLR_G(clr_rgba) (u8)((clr_rgba & 0xff0000) >> 8 * 2)
#define U_CLR_B(clr_rgba) (u8)((clr_rgba & 0xff00) >> 8)
#define U_CLR_A(clr_rgba) (u8)((clr_rgba & 0xff))

#define U_CLR_DEV(clr_rgba) U_CLR_R(clr_rgba), U_CLR_G(clr_rgba), U_CLR_B(clr_rgba), U_CLR_A(clr_rgba)

// predefined colors
#define CLR_RED 0xff0000ff
#define CLR_BLUE 0x00ff00ff
#define CLR_GREEN 0x0000ffff
#define CLR_WHITE 0xffffffff
#define CLR_BLACK 0x000000ff

#define CLR_OCEAN_BLUE 0x001a33ff

#endif