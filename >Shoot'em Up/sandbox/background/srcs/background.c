#include "test.h"


void draw_rect(SDL_Color color, SDL_Rect rect, SDL_Renderer *render)
{
    if (SDL_RenderClear(render) != 0)
		exit (1);
    SDL_SetRenderDrawColor(render, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(render, &rect);
}

void    build_background(SDL_Renderer *render)
{
    SDL_Surface     *background_s;
    SDL_Texture     *background_t;
    SDL_Rect        src;
    SDL_Rect        dst;

    background_s = IMG_Load("/Users/flagada/Desktop/B9R9-SDL/>Shoot'em Up/sandbox/background/img/Space Background.png");
    if (background_s == NULL)
    {
        print_error("In Background", SDL_GetError());
        SDL_FreeSurface(background_s);
        exit(EXIT_FAILURE);
    }
    background_t = SDL_CreateTextureFromSurface(render, background_s);
    SDL_FreeSurface(background_s);

    src.x = -1;
    src.y = 75;
    src.w = 5;
    src.h = SCREEN_HEIGHT - src.y - 50;
    
    dst.x = -1;
    dst.y = 75;
    dst.w = 5;
    dst.h = SCREEN_HEIGHT - src.y - 50;

    while (src.x < SCREEN_WIDTH)
    {
        SDL_RenderCopy(render, background_t, &src, &dst);     
        src.x += 5;
        dst.x += 5;
    }
}

void test(SDL_Renderer *render, int *index)
{
    SDL_Surface     *background_s;
    SDL_Texture     *background_t;
    SDL_Rect        src;
    SDL_Rect        dst;

    background_s = IMG_Load("/Users/flagada/Desktop/B9R9-SDL/>Shoot'em Up/sandbox/background/img/Space Background.png");
    if (background_s == NULL)
    {
        print_error("In Background", SDL_GetError());
        SDL_FreeSurface(background_s);
        exit(EXIT_FAILURE);
    }
    background_t = SDL_CreateTextureFromSurface(render, background_s);
    SDL_FreeSurface(background_s);

    int a;
    int b;
    SDL_QueryTexture(background_t, NULL, NULL, &a, &b);
    if (*index >= a - 5)
        *index = -1;
    src.x = *index;
    src.y = 75;
    src.w = 5;
    src.h = SCREEN_HEIGHT - src.y - 50;
    
    dst.x = -1;
    dst.y = 75;
    dst.w = 5;
    dst.h = SCREEN_HEIGHT - src.y - 50;

    while (dst.x < SCREEN_WIDTH)
    {
        SDL_RenderCopy(render, background_t, &src, &dst);  
        src.x += 5;
        if (src.x >= a - 5)
            src.x = -1;
        dst.x += 5;
    }

}



/*
decoupe le background.
la partie 1 est sauvegarder
on copie la partie 2 a la place de la partie 1
on place la partie 1 quand on arrive au bout de la boucle
*/
