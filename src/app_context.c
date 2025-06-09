#include "app_context.h"

i8 A_init_ctx(app_ctx* ctx, u16 wwidth, u16 wheight)
{
	if (SDL_Init(SDL_INIT_VIDEO) != true)
	{
		mdl_LOG_ERROR("\n", "SDL3 initialization : %s", SDL_GetError());
		return -1;
	}

	bool result = SDL_CreateWindowAndRenderer("realm", wwidth, wheight, 0, &ctx->window, &ctx->renderer);
	if (result != true)
	{
		mdl_LOG_ERROR("\n", "window and renderer creation : %s", SDL_GetError());
		return -1;
	}

        mdl_LOG_SUCCESS("\n", "app context successfully init.");

        ctx->running = TRUE;
	ctx->wwidth = wwidth;
	ctx->wheight = wheight;

	return 0;
}

void A_begin_update_ctx(app_ctx* ctx, u32 clr_rgba)
{
	SDL_SetRenderDrawColor(ctx->renderer, U_CLR_DEV(clr_rgba));
        SDL_RenderClear(ctx->renderer);

        while (SDL_PollEvent(&ctx->event))
        {
                switch (ctx->event.type)
                {
                case SDL_EVENT_QUIT:
                        ctx->running = FALSE;
                        break;
                
                default:
                        break;
                }
        }
}

void A_render_rect(app_ctx* ctx, v2f pos, v2f dim, u32 clr_rgba)
{
        SDL_FRect rect = {
                .x = pos.x,
                .y = pos.y,
                .w = dim.x,
                .h = dim.y
        };

        SDL_SetRenderDrawColor(ctx->renderer, U_CLR_DEV(clr_rgba));
        SDL_RenderRect(ctx->renderer, &rect);
}

void A_end_update_ctx(app_ctx* ctx)
{
        SDL_RenderPresent(ctx->renderer);
}

void A_destroy_ctx(app_ctx* ctx)
{
        SDL_DestroyRenderer(ctx->renderer);
        SDL_DestroyWindow(ctx->window);
        SDL_Quit();
}