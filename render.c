/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:27:21 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/19 22:34:55 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/fcntl.h>

int key_hook(int keycode, t_game *s)
{
    int newplayer_l;
    int newplayer_h;

    newplayer_l = s->player_l;
    newplayer_h = s->player_h;
    if (keycode == 126 || keycode == 13)//^^Up^^
        player_walk(check_part(s, newplayer_h - 1,newplayer_l), newplayer_h - 1, newplayer_l, s);
    else if (keycode == 125 || keycode == 1)//__down__
        player_walk(check_part(s, newplayer_h + 1,newplayer_l), newplayer_h + 1, newplayer_l, s);
    else if (keycode == 123 || keycode == 0)//<<left<<
        player_walk(check_part(s, newplayer_h,newplayer_l - 1), newplayer_h, newplayer_l - 1, s);
    else if (keycode == 124 || keycode == 2)//>>right>>
        player_walk(check_part(s, newplayer_h,newplayer_l + 1), newplayer_h, newplayer_l + 1, s);
    return (0);
}

int check_part(t_game *s,int h, int l)
{
    if (s->map_play[h][l] == '0' || s->map_play[h][l] == 'C')
    {
        if (s->map_play[h][l] == 'C')
            s->player_eat_c++;
        return (1);
    }
    // if (ft_strchr("0C",s->map_real[h][l]) != NULL)
    // {
    //     if (s->map_real[h][l] == 'C')
    //         s->player_eat_c++;
    //     return (1);
    // }
    else if (s->map_play[h][l] == 'E')
    {
        if (s->player_eat_c == s->count_c)
            exit(0);
        return (1);
    }
    return (0);
}

void    player_walk(int mode, int h, int l, t_game *s)
{
    if (mode == 1)
    {
        if(s->map_play[s->player_h][s->player_l] == 'E')
        {
            mlx_put_image_to_window(s->mlx,s->window,s->floor,s->player_l * 64,s->player_h * 64);
            mlx_put_image_to_window(s->mlx,s->window,s->exit,s->player_l * 64,s->player_h * 64);
        }
        else
            mlx_put_image_to_window(s->mlx,s->window,s->floor,s->player_l * 64,s->player_h * 64);
        s->player_h = h;
        s->player_l = l;
        mlx_put_image_to_window(s->mlx,s->window,s->floor,s->player_l * 64,s->player_h * 64);
        mlx_put_image_to_window(s->mlx,s->window,s->player,s->player_l * 64,s->player_h * 64);
    }
    // if (mode == 2)
    // {
    //     if(s->map_play[s->player_h][s->player_l] == 'E')
    //     {
    //         mlx_put_image_to_window(s->mlx,s->window,s->floor,s->player_l * 64,s->player_h * 64);
    //         mlx_put_image_to_window(s->mlx,s->window,s->exit,s->player_l * 64,s->player_h * 64);
    //     }
    //     else
    //     s->player_h = h;
    //     s->player_l = l;
    //     mlx_put_image_to_window(s->mlx,s->window,s->player,s->player_l * 64,s->player_h * 64);
    // }

}

void    render(t_game *s)
{
    // void    *mlx;
    // void    *window;
    // s->init = mlx_init();
    s->mlx = mlx_init();
    // s->window = mlx_new_window(s->init,s->lenght * 64,s->height * 64,"so_long");
    s->window = mlx_new_window(s->mlx, (s->lenght * 64)+1, (s->height * 64)+1,"so_long");
    s->floor = mlx_xpm_file_to_image(s->mlx,"./pic64/space64.xpm",&s->lenght,&s->height);
    s->wall = mlx_xpm_file_to_image(s->mlx,"./pic64/wall64.xpm",&s->lenght,&s->height);
    s->collectible = mlx_xpm_file_to_image(s->mlx,"./pic64/colectable64.xpm",&s->lenght,&s->height);
    s->exit = mlx_xpm_file_to_image(s->mlx,"./pic64/exit64.xpm",&s->lenght,&s->height);
    s->player = mlx_xpm_file_to_image(s->mlx,"./pic64/toilet64.xpm",&s->lenght,&s->height);
    render_floor(s);
    render_wall(s);
    // int h=0;
    // while(h < s->height){
    //     printf("%s",s->map_play[h]);
    //     h++;
    // }
    mlx_key_hook(s->window, key_hook, s);
    // mlx_key_hook(s->window, key_hook, s);
    mlx_loop(s->mlx);
}





void    render_wall(t_game *s)
{
    int h;
    int l;

    h = 0;
    while (s->map_play[h] != NULL )
    {
        l = 0;
        while (s->map_play[h][l] != '\0' && s->map_play[h][l] != '\n')
        {
            if (s->map_play[h][l] == '1')
                mlx_put_image_to_window(s->mlx,s->window,s->wall,l * 64,h * 64);
            else if (s->map_play[h][l] == 'C')
                mlx_put_image_to_window(s->mlx,s->window,s->collectible,l * 64,h * 64);
            else if (s->map_play[h][l] == 'E')
                mlx_put_image_to_window(s->mlx,s->window,s->exit,l * 64,h * 64);
            else if (s->map_play[h][l] == 'P')
                mlx_put_image_to_window(s->mlx,s->window,s->player,l * 64,h * 64);
            l++;
        }
        h++;
    }
}

void    render_floor(t_game *s)
{
    int h;
    int l;

    h = 0;
    while (s->map_play[h] != NULL )
    {
        l = 0;
        while (s->map_play[h][l] != '\0' && s->map_play[h][l] != '\n')
        {
            mlx_put_image_to_window(s->mlx,s->window,s->floor,l * 64,h * 64);
            l++;
        }
        h++;
    }
}


