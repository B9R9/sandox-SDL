#include "test.h"

int define_cadence(uint32_t cadence)
{
    static uint32_t prev_time;
    static uint32_t diff;
    uint32_t time;

    time = SDL_GetTicks();
    diff += time - prev_time;
    prev_time = time;
    if (diff >= cadence || prev_time == 0)
    {
        diff = 0;
        return (true);
    }
    return (false);
}

t_projectile *create_projectile(SDL_Rect player_pos)
{
    t_projectile *new;

    new = (t_projectile *)malloc(sizeof(t_projectile));
    if (!new)
        return (new);
    new->projectile.x = player_pos.x + player_pos.w;
    new->projectile.y = (player_pos.h / 3) + player_pos.y;
    new->projectile.w = 10;
    new->projectile.h = 10;
    new->next = NULL;
    return (new); 
}

t_projectile *add_projectile_to_list(t_projectile *node, t_projectile *list)
{
    if (list == NULL)
        return (node);
    node->next =  list;
    return (node);
}

t_projectile *update_position_projectile(t_projectile *list)
{
    t_projectile *head;
    int i;

    i = 0;
    head = list;
    while(list != NULL)
    {
        list->projectile.x += 5;
        /*ADD safety quand le projectile va hors screen on enleve de la liste*/
        list = list->next;
    }
    return(head);
}

void    update_render(t_data data)
{
    t_projectile *temp;

    temp = data.projectile_list;
    while (temp != NULL)
    {
        SDL_SetRenderDrawColor(data.render, 0, 255, 0, 255);
        SDL_RenderDrawRect(data.render, &temp->projectile);
        temp = temp->next;
    }
}


t_data shooting_sys(t_data data)
{
    t_projectile *new;

    new = NULL;
    if (data.projectile_list)
           data.projectile_list = update_position_projectile(data.projectile_list);
    if (define_cadence(3000))
    {
        new = create_projectile(data.player);
        data.projectile_list = add_projectile_to_list(new, data.projectile_list);
    }
    update_render(data);
    return(data);

    /* printf("CU_Weapons %d\n", data.current_weapon);
        create_projectile();
    update_projectile_position();
    add_to_projectle_list();
    
     Δ le projectile cree ne doit pas etre update de suite.
     etape on update la position de projectile deja lance
     on met a jour le render
     on check la cadence 
        si oui on cree un nouveaux projectile
        on met a jour le render 
        on ajoute le projectile a la liste 
     on cree le projectile
     on met a jour le render
   */
}