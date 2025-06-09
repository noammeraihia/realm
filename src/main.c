#include <stdio.h>
#include <stdlib.h>

#include "app_context.h"

#define FORCE 0.001f

int main(int argc, char* argv[])
{
        app_ctx ctx = { 0 };
        A_init_ctx(&ctx, 640, 480);

        v2f pos = M_VEC(2f, 40.f, 10.f);
        f32 mass = 1.f;
        f32 inv_mass = 1 / mass;

        v2f force = M_VEC(2f, 0.f, 0.f);
        v2f acceleration = M_VEC(2f, 0.f, 0.f);
        v2f velocity = M_VEC(2f, 0.f, 0.f);

        while (ctx.running)
        {
                A_begin_update_ctx(&ctx, CLR_OCEAN_BLUE);

                //force = M_ADD_VEC2(f, force, M_VEC(2f, 0.f, 0.01f));

                if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_DOWN]) 
                {
                        force = M_ADD_VEC2(f, force, M_VEC(2f, 0.f, FORCE));
                }
                else if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_UP]) 
                {
                        force = M_ADD_VEC2(f, force, M_VEC(2f, 0.f, -FORCE));
                }

                if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_RIGHT]) 
                {
                        force = M_ADD_VEC2(f, force, M_VEC(2f, FORCE, 0.f));
                }
                else if (SDL_GetKeyboardState(NULL)[SDL_SCANCODE_LEFT]) 
                {
                        force = M_ADD_VEC2(f, force, M_VEC(2f, -FORCE, 0.f));
                }

                acceleration = M_SDOT_VEC2(f, force, inv_mass);
                velocity = M_ADD_VEC2(f, velocity, acceleration);
                pos = M_ADD_VEC2(f, pos, velocity);

                force = M_VEC(2f, 0.f, 0.f); 

                A_render_rect(&ctx, pos, M_VEC(2f, 30.f, 30.f), CLR_WHITE);

                A_end_update_ctx(&ctx);
        }
        
        A_destroy_ctx(&ctx);

        return 0;
}