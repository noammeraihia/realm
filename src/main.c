#include <stdio.h>
#include <stdlib.h>

#include "realm_engine.h"

#define FORCE 0.001f

int main(int argc, char* argv[])
{
        app_ctx ctx = { 0 };
        A_init_ctx(&ctx, 640, 480);

        v2f pos = U_VEC(2f, 40.f, 10.f);
        f32 mass = 1.f;
        f32 inv_mass = 1 / mass;

        v2f force = U_VEC(2f, 0.f, 0.f);
        v2f acceleration = U_VEC(2f, 0.f, 0.f);
        v2f velocity = U_VEC(2f, 0.f, 0.f);

        while (ctx.running)
        {
                A_begin_update_ctx(&ctx, CLR_OCEAN_BLUE);

                //force = U_ADD_VEC2(f, force, U_VEC(2f, 0.f, 0.01f));

                if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_DOWN]) 
                {
                        force = U_ADD_VEC2(f, force, U_VEC(2f, 0.f, FORCE));
                }
                else if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_UP]) 
                {
                        force = U_ADD_VEC2(f, force, U_VEC(2f, 0.f, -FORCE));
                }

                if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_RIGHT]) 
                {
                        force = U_ADD_VEC2(f, force, U_VEC(2f, FORCE, 0.f));
                }
                else if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LEFT]) 
                {
                        force = U_ADD_VEC2(f, force, U_VEC(2f, -FORCE, 0.f));
                }

                acceleration = U_SDOT_VEC2(f, force, inv_mass);
                velocity = U_ADD_VEC2(f, velocity, acceleration);
                pos = U_ADD_VEC2(f, pos, velocity);

                force = U_VEC(2f, 0.f, 0.f); 

                R_render_rect(ctx.renderer, pos, U_VEC(2f, 30.f, 30.f), CLR_WHITE);

                A_end_update_ctx(&ctx);
        }
        
        A_destroy_ctx(&ctx);

        return 0;
}