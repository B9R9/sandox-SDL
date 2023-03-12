#include "test.h"


int main(void)
{
    t_data          data;
    SDL_Event       e;
    Bool            quit;
    
    quit = false;

    /*Initialisation et creation de la fenetre et du render*/
    if (init_SDL(SDL_INIT_VIDEO) == -1)
        exit (EXIT_FAILURE);
    if (create_window(&data.window, "test background")== -1)
        exit(EXIT_FAILURE);
    if (create_render(&data.render, data.window) == -1)
        exit(EXIT_FAILURE);
    /*A t on besoin de cette partie ???*/
    if (init_PNG(data) == -1)
        exit(EXIT_FAILURE);
    
    /*faire une function pour initialiser data*/
    data.current_weapon = CLASSIC;
    data.projectile_list = NULL;

    // build_background(data);
    create_rect(&data.player, 10, SCREEN_HEIGHT / 2, 50, 25);
    int i = 5;

    /*Boucle event*/
    while (!quit)
    {
        background_animation(data, &i);
        SDL_PollEvent(&e);
        // while (SDL_PollEvent(&e))
        // {
            // SDL_RenderPresent(data.render);
            if (e.type == SDL_QUIT)
                quit = true;
            if (e.type == SDL_KEYDOWN)
                if (e.key.keysym.sym == SDLK_ESCAPE)
                    quit = true;
                if (e.key.keysym.sym == SDLK_UP)
                    update_pos_player(&data.player, UP);
                if (e.key.keysym.sym == SDLK_DOWN)
                    update_pos_player(&data.player, DOWN);
                if (e.key.keysym.sym == SDLK_RIGHT)
                    update_pos_player(&data.player, RIGHT);
                if (e.key.keysym.sym == SDLK_LEFT)
                    update_pos_player(&data.player, LEFT);
        //     break;
        // }
        set_player(data);
        data = shooting_sys(data);
        SDL_RenderPresent(data.render);
        SDL_Delay(10);
        i += 5;
    }
    destroy(data);
    SDL_Quit();
    return (0);
}