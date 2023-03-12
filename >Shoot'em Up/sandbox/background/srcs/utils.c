#include "test.h"


void    print_error(const char *where, const char *err_mes)
{
    printf("Error: %s > %s", where, err_mes);
}

// void    destroy(SDL_Window *window, SDL_Renderer *render)
void    destroy(t_data data)
{
    SDL_DestroyRenderer(data.render);
    SDL_DestroyWindow(data.window);
}

void draw_rect(SDL_Color color, SDL_Rect rect, SDL_Renderer *render)
{
    if (SDL_RenderClear(render) != 0)
		exit (1);
    SDL_SetRenderDrawColor(render, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(render, &rect);
}

void create_rect(SDL_Rect *rect, int x, int y, int w, int h)
{
    (*rect).x = x;
    (*rect).y = y;
    (*rect).w = w;
    (*rect).h = h;
}