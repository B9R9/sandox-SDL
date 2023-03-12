#include "test.h"

// SDL_Texture *load_texture(const char *path, SDL_Renderer *render)
SDL_Texture *load_texture(const char *path, t_data data)
{
    SDL_Surface *surface;
    SDL_Texture *texture;

    surface = NULL;
    surface = IMG_Load(path);
    if (surface == NULL)
    {
        print_error("In load_surface", SDL_GetError());
        SDL_FreeSurface(surface);
        destroy(data);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    texture =  SDL_CreateTextureFromSurface(data.render, surface);
    SDL_FreeSurface(surface);
    if (texture == NULL)
    {
        print_error("In load_texture", SDL_GetError());
        destroy(data);
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
    return (texture);
}

int reset_index(int value, SDL_Texture *texture)
{
    int max;

    SDL_QueryTexture(texture, NULL, NULL, &max, NULL);

    if (value >= max - 5)
        return (true);
    return (false);
}

// void    build_background(SDL_Renderer *render)
void    build_background(t_data data)
{
    SDL_Texture     *background_t;
    SDL_Rect        src;

    background_t = load_texture("/Users/flagada/Desktop/B9R9-SDL/>Shoot'em Up/sandbox/background/img/Space Background.png", data);
   
    create_rect(&src, -1, 75, 5, SCREEN_HEIGHT - 75 - 50);
    
    while (src.x < SCREEN_WIDTH)
    {
        SDL_RenderCopy(data.render, background_t, &src, &src);     
        src.x += 5;
    }
}

// void background_animation(SDL_Renderer *render, int *index)
void background_animation(t_data data, int *index)
{
    SDL_Texture     *background_t;
    SDL_Rect        src;
    SDL_Rect        dst;

    background_t = load_texture("/Users/flagada/Desktop/B9R9-SDL/>Shoot'em Up/sandbox/background/img/Space Background.png", data);
    if (reset_index(*index, background_t))
        *index = -1;
    create_rect(&src, *index, 75, 5, SCREEN_HEIGHT - 75 - 50);
    create_rect(&dst, -1, 75, 5, SCREEN_HEIGHT - 75 - 50);
    while (dst.x < SCREEN_WIDTH)
    {
        SDL_RenderCopy(data.render, background_t, &src, &dst);  
        src.x += 5;
        if (reset_index(src.x,background_t))
            src.x = -1;
        dst.x += 5;
    }
}
