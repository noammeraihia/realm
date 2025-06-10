#ifndef RENDER_h
#define RENDER_h

#include <SDL3/SDL.h>
#include <mdl.h>

#include "utils/utils.h"

void R_render_rect(SDL_Renderer* renderer, v2f pos, v2f dim, u32 clr_rgba);
void R_render_pixel(SDL_Renderer* renderer, v2f pos, u32 clr_rgba);
void R_render_line(SDL_Renderer* renderer, v2f a, v2f b, u32 clr_rgba);

#endif
