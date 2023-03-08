#include "test.h"


void    print_error(const char *where, const char *err_mes)
{
    printf("Error: %s > %s", where, err_mes);
}

void    destroy(SDL_Window *window, SDL_Renderer *render)
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
}