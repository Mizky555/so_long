/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:27:21 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/24 18:29:13 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/fcntl.h>

int	key_hook(int keycode, t_game	*s)
{
	int	newplayer_l;
	int	newplayer_h;

	newplayer_l = s->player_l;
	newplayer_h = s->player_h;
	if (keycode == 126 || keycode == 13)
		player_walk(check_part(s, newplayer_h - 1, newplayer_l),
			newplayer_h - 1, newplayer_l, s);
	else if (keycode == 125 || keycode == 1)
		player_walk(check_part(s, newplayer_h + 1, newplayer_l),
			newplayer_h + 1, newplayer_l, s);
	else if (keycode == 123 || keycode == 0)
		player_walk(check_part(s, newplayer_h, newplayer_l - 1),
			newplayer_h, newplayer_l - 1, s);
	else if (keycode == 124 || keycode == 2)
		player_walk(check_part(s, newplayer_h, newplayer_l + 1),
			newplayer_h, newplayer_l + 1, s);
	else if (keycode == 53)
		ft_close(s);
	return (0);
}

void	print_step(int count)
{
	write(1, "Step : ", 7);
	ft_putnbr_fd(count, 1);
	write(1, "\n", 1);
}

int	check_part(t_game *s, int h, int l)
{
	if (s->map_play[h][l] == 'C' || s->map_play[h][l] == '0'
			|| s->map_play[h][l] == 'P')
	{
		s->count_walk++;
		if (s->map_play[h][l] == 'C' )
		{
			s->player_eat_c++;
			s->map_play[h][l] = '0';
		}
		else if (s->map_play[h][l] == 'P')
			s->map_play[h][l] = '0';
		print_step(s->count_walk);
		return (1);
	}
	else if (s->map_play[h][l] == 'E')
	{
		s->count_walk++;
		if (s->player_eat_c == s->count_c)
		{
			print_step(s->count_walk);
			exit(0);
		}
		return (1);
	}
	print_step(s->count_walk);
	return (0);
}

void	player_walk(int mode, int h, int l, t_game *s)
{
	if (mode == 1)
	{
		if (s->map_play[s->player_h][s->player_l] == 'E')
		{
			mlx_put_image_to_window(s->mlx, s->window, s->floor, s->player_l
				* 64, s->player_h * 64);
			mlx_put_image_to_window(s->mlx, s->window, s->exit, s->player_l
				* 64, s->player_h * 64);
		}
		else
			mlx_put_image_to_window(s->mlx, s->window, s->floor, s->player_l
				* 64, s->player_h * 64);
		s->player_h = h;
		s->player_l = l;
		mlx_put_image_to_window(s->mlx, s->window, s->floor, s->player_l
			* 64, s->player_h * 64);
		mlx_put_image_to_window(s->mlx, s->window, s->player, s->player_l
			* 64, s->player_h * 64);
	}
}

int	ft_close(t_game *s)
{
	mlx_destroy_image(s->mlx, s->collectible);
	mlx_destroy_image(s->mlx, s->exit);
	mlx_destroy_image(s->mlx, s->floor);
	mlx_destroy_image(s->mlx, s->player);
	mlx_destroy_image(s->mlx, s->wall);
	mlx_destroy_window(s->mlx, s->window);
	ft_putstr_fd("exiting... :D\n", 1);
	free_map_play(s);
	exit(0);
}
