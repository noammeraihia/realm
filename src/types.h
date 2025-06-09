#ifndef TYPES_h
#define TYPES_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int32_t i;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint32_t u;
typedef uint64_t u64;

typedef float f32;
typedef float f;
typedef double f64;

typedef enum {
	FALSE=(u8)0,
        TRUE=(u8)1	
} b8;

#endif
