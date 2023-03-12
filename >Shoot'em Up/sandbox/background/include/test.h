#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdlib.h>

#include "SDL.h"
#include <SDL_image.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef enum {false, true} Bool;
typedef enum {UP, RIGHT, DOWN, LEFT} Move;
typedef enum {CLASSIC, LASER} Weapons;

typedef struct s_color
{
    int r;
    int g;
    int b;
    int o;
}t_color;

typedef struct s_projectile
{
    SDL_Rect projectile;
    struct s_projectile *next;
}t_projectile;

typedef struct s_data
{
    SDL_Renderer    *render;
    SDL_Window      *window;
    SDL_Rect        player;
    Weapons         current_weapon;
    struct s_projectile    *projectile_list;
    // Lvl_weapons     Lvl;
    
} t_data;

// t_color blue (255,0, 0 ,0);


// typedef enum {LVL0, LVL1, LVL2, LVL3} Lvl_weapons;


/* Init */
int     init_SDL(uint32_t flags);
// int     init_PNG(SDL_Window *window, SDL_Renderer *render);
int     init_PNG(t_data data);
int     create_window(SDL_Window **window, const char *title);
int     create_render(SDL_Renderer **render, SDL_Window *window);
// int     create_render(t_data data);

/* error */
void    print_error(const char *where, const char *err_mes);
// void    destroy(SDL_Window *window, SDL_Renderer *render);
void    destroy(t_data data);


void    set_background(SDL_Renderer **render);
void    defilement(SDL_Renderer **render);
void    build_background(t_data data);
// void    build_background(SDL_Renderer *render);
// void    background_animation(SDL_Renderer *render, int *index);
void    background_animation(t_data data, int *index);
void    create_rect(SDL_Rect *rect, int x, int y, int w, int h);
void    draw_rect(SDL_Color color, SDL_Rect rect, SDL_Renderer *render);


void set_player(t_data data);
void update_pos_player(SDL_Rect *player, Move direction);

t_data shooting_sys(t_data data);
#endif