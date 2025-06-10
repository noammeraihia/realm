#include "render/render.h"

void R_render_rect(SDL_Renderer* renderer, v2f pos, v2f dim, u32 clr_rgba)
{
        SDL_FRect rect = {
                .x = pos.x,
                .y = pos.y,
                .w = dim.x,
                .h = dim.y
        };

        SDL_SetRenderDrawColor(renderer, U_CLR_DEV(clr_rgba));
        SDL_RenderRect(renderer, &rect);
}

void R_render_pixel(SDL_Renderer* renderer, v2f pos, u32 clr_rgba)
{
        SDL_SetRenderDrawColor(renderer, U_CLR_DEV(clr_rgba));
        SDL_RenderPoint(renderer, pos.x, pos.y);
}

void R_render_line(SDL_Renderer* renderer, v2f a, v2f b, u32 clr_rgba)
{
        SDL_SetRenderDrawColor(renderer, U_CLR_DEV(clr_rgba));
        SDL_RenderLine(renderer, a.x, a.y, b.x, b.y);
}