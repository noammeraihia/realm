#ifndef MATHS_h
#define MATHS_h

#include "utils.h"

typedef struct s_v2f 
{
        f32 x, y;

} v2f;

typedef struct s_v2i
{
        i32 x, y;

} v2i;

typedef struct s_v3f 
{
        f32 x, y, z;

} v3f;

typedef struct s_v3i
{
        i32 x, y, z;

} v3i;

#define M_VEC(t, ...) (v##t){ __VA_ARGS__ }

#define M_ADD_VEC2(t, va, vb) (v2##t){ va.x + vb.x, va.y + vb.y }
#define M_SUB_VEC2(t, va, vb) (v2##t){ va.x - vb.x, va.y - vb.y }
#define M_DOT_VEC2(t, va, vb) (v2##t){ va.x * vb.x, va.y * vb.y }
#define M_DIV_VEC2(t, va, vb) (v2##t){ va.x / vb.x, va.y / vb.y }

#define M_SADD_VEC2(t, v, s) (v2##t){ v.x + s, v.y + s }
#define M_SSUB_VEC2(t, v, s) (v2##t){ v.x - s, v.y - s }
#define M_SDOT_VEC2(t, v, s) (v2##t){ v.x * s, v.y * s }
#define M_SDIV_VEC2(t, v, s) (v2##t){ v.x / s, v.y / s }

#define M_VEC2_CONVERT(t, v) (v2##t){ (##t)v.x, (##t)v.y }

#define M_ADD_VEC3(t, va, vb) (v##t){ va.x + vb.x, va.y + vb.y, va.z + vb.z }
#define M_SUB_VEC3(t, va, vb) (v##t){ va.x - vb.x, va.y - vb.y, va.z - vb.z }
#define M_DOT_VEC3(t, va, vb) (v##t){ va.x * vb.x, va.y * vb.y, va.z * vb.z }
#define M_DIV_VEC3(t, va, vb) (v##t){ va.x / vb.x, va.y / vb.y, va.z / vb.z }

#define M_SADD_VEC3(t, v, s) (v##t){ v.x + s, v.y + s, v.z + s }
#define M_SSUB_VEC3(t, v, s) (v##t){ v.x - s, v.y - s, v.z - s }
#define M_SDOT_VEC3(t, v, s) (v##t){ v.x * s, v.y * s, v.z * s }
#define M_SDIV_VEC3(t, v, s) (v##t){ v.x / s, v.y / s, v.z / s }

#define M_VEC3_CONVERT(t, v) (v2##t){ (##t)v.x, (##t)v.y, (##t)v.z}

#endif