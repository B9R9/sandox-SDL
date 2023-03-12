#include "test.h"


// int set_color(int r, int g, int b, int a, SDL_Renderer *render)
// {
//     if (SDL_RenderClear(render) != 0)
//     {

//         return (false);
//     }
//     SDL_SetRenderDrawColor(render, r , g, b, a);
//     return (true);
// }
// create_rect(&src, -1, 75, 5, SCREEN_HEIGHT - 75 - 50)
Bool reach_limits(int position, Move direction)
{
    switch (direction)
    {
        case UP:
            if (position >= 80)
                return (true);
            break;
        case DOWN:
            if (position <= SCREEN_HEIGHT - 80)
                return (true);
            break;
        case RIGHT:
            if (position <= SCREEN_WIDTH - 50)
                return (true);
            break;
        case LEFT:
            if (position >= 20)
                return (true);
            break;
    }
    return (false);
}

void set_player(t_data data)
{
    SDL_SetRenderDrawColor(data.render, 255, 0 , 0, 255);
    SDL_RenderDrawRect(data.render, &data.player);
}

void update_pos_player(SDL_Rect *player, Move direction)
{
    switch (direction)
    {
        case UP:
            if (reach_limits(player->y - 10, UP))
                player->y -=10;
            break;
        case DOWN:
            if (reach_limits(player->y + 10, DOWN))
                player->y += 10;
            break;
        case RIGHT:
            if (reach_limits(player->x + 10, RIGHT))
                player->x += 10;
            break;
        case LEFT:
            if (reach_limits(player->x - 10, LEFT))
                player->x -= 10;
            break;
    }
}