#ifndef APP_CONTEXT
#define APP_CONTEXT

#include <stdio.h>
#include <stdlib.h>

#include <SDL3/SDL.h>
#include <mdl.h>

#include "utils.h"

typedef struct s_app_ctx
{
	b8 running;

	SDL_Window* window;
	SDL_Renderer* renderer;
	u16 wwidth, wheight;

	SDL_Event event;

} app_ctx;

i8 A_init_ctx(app_ctx* ctx, u16 wwidth, u16 wheight);
void A_begin_update_ctx(app_ctx* ctx, u32 clr_rgba);
void A_render_rect(app_ctx* ctx, v2f pos, v2f dim, u32 clr_rgba);
void A_end_update_ctx(app_ctx* ctx);
void A_destroy_ctx(app_ctx* ctx);

#endif
