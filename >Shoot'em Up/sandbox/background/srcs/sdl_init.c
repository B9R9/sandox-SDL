#include "test.h"

int    init_SDL(uint32_t flags)
{
    if (SDL_Init(flags) != 0)
    {
        print_error("In SDL_INIT", SDL_GetError());
        SDL_Quit();
        return (-1);
    }
    return (1);
}

int create_window(SDL_Window **window, const char *title)
{
    *window = SDL_CreateWindow(title,\
SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (*window == NULL)
    {
        print_error("In create window", SDL_GetError());
        SDL_Quit();
        return (-1);
    }
    return (1);
}

int create_render(SDL_Renderer **render, SDL_Window *window)
{
    *render = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (*render == NULL)
    {
        print_error("In create render", SDL_GetError());
        destroy(window, *render);
        SDL_Quit();
        return (-1);
    }
    return (1);
}

int init_PNG(SDL_Window *window, SDL_Renderer *render)
{
    int imaflags = IMG_INIT_PNG;

    if (!(IMG_INIT(imaflags) & imaflags))
    {
        print_error("In init PNG", SDL_GetError());
        destroy(window, render);
        SDL_Quit();
        return (-1);
    }
    return (1);
}