#include "test.h"

int main(void)
{
    SDL_Window      *main_w;
    SDL_Renderer    *main_r;
    SDL_Event       e;
    Bool            quit;
    
    main_w = NULL;
    main_r = NULL;
    quit = false;

    /*Initialisation et creation de la fenetre et du render*/
    if (init_SDL(SDL_INIT_VIDEO) == -1)
        exit (EXIT_FAILURE);
    if (create_window(&main_w, "test background")== -1)
        exit(EXIT_FAILURE);
    if (create_render(&main_r, main_w) == -1)
        exit(EXIT_FAILURE);
    /*A t on besoin de cette partie ???*/
    if (init_PNG(main_w, main_r) == -1)
        exit(EXIT_FAILURE);

    
    set_background(main_r);
    
    /*Boucle event*/
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            SDL_RenderPresent(main_r);
            if (e.type == SDL_QUIT)
                quit = true;
            if (e.type == SDL_KEYDOWN)
                if (e.key.keysym.sym == SDLK_ESCAPE)
                    quit = true; 
        }
    }


    destroy(main_w, main_r);
    SDL_Quit();
    return (0);
}