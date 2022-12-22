/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:36:22 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/23 03:38:39 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(t_game *s)
{
	s->mlx = mlx_init();
	s->window = mlx_new_window(s->mlx, (s->lenght * 64)
			+ 1, (s->height * 64) + 1, "so_long");
	s->l = s->lenght;
	s->h = s->height;
	s->floor = mlx_xpm_file_to_image(s->mlx,
			"./pic64/space64.xpm", &s->lenght, &s->height);
	s->wall = mlx_xpm_file_to_image(s->mlx,
			"./pic64/wall64.xpm", &s->lenght, &s->height);
	s->collectible = mlx_xpm_file_to_image(s->mlx,
			"./pic64/colectable64.xpm", &s->lenght, &s->height);
	s->exit = mlx_xpm_file_to_image(s->mlx,
			"./pic64/exit64.xpm", &s->lenght, &s->height);
	s->player = mlx_xpm_file_to_image(s->mlx,
			"./pic64/toilet64.xpm", &s->lenght, &s->height);
	render_floor(s);
	render_wall(s);
	mlx_key_hook(s->window, key_hook, s);
	mlx_hook(s->window, 17, 0, ft_close, s);
	mlx_loop(s->mlx);
}

void	render_wall(t_game *s)
{
	int	h;
	int	l;

	h = 0;
	while (s->map_play[h] != NULL )
	{
		l = 0;
		while (s->map_play[h][l] != '\0' && s->map_play[h][l] != '\n')
		{
			if (s->map_play[h][l] == '1')
				mlx_put_image_to_window(s->mlx, s->window,
					s->wall, l * 64, h * 64);
			else if (s->map_play[h][l] == 'C')
				mlx_put_image_to_window(s->mlx, s->window,
					s->collectible, l * 64, h * 64);
			else if (s->map_play[h][l] == 'E')
				mlx_put_image_to_window(s->mlx, s->window,
					s->exit, l * 64, h * 64);
			else if (s->map_play[h][l] == 'P')
				mlx_put_image_to_window(s->mlx, s->window,
					s->player, l * 64, h * 64);
			l++;
		}
		h++;
	}
}

void	render_floor(t_game *s)
{
	int	h;
	int	l;

	h = 0;
	while (s->map_play[h] != NULL )
	{
		l = 0;
		while (s->map_play[h][l] != '\0' && s->map_play[h][l] != '\n')
		{
			mlx_put_image_to_window(s->mlx, s->window,
				s->floor, l * 64, h * 64);
			l++;
		}
		h++;
	}
}
