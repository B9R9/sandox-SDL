#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>

#include "SDL.h"
#include <SDL_image.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


typedef enum {false, true} Bool;

/* Init */
int     init_SDL(uint32_t flags);
int     init_PNG(SDL_Window *window, SDL_Renderer *render);
int     create_window(SDL_Window **window, const char *title);
int     create_render(SDL_Renderer **render, SDL_Window *window);

/* error */
void    print_error(const char *where, const char *err_mes);
void    destroy(SDL_Window *window, SDL_Renderer *render);


void    set_background(SDL_Renderer **render);
void    defilement(SDL_Renderer **render);
void    build_background(SDL_Renderer *render);
void    test(SDL_Renderer *render, int *index);
#endif