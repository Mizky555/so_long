/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:06:40 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/23 03:29:18 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_create(char **argv, t_game *s)
{
	int	fd;
	int	h;

	h = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("file error\n");
	s->map_real = malloc(sizeof(char *) * s->height + 1);
	while (h < s->height)
	{
		s->map_real[h] = get_next_line(fd);
		h++;
	}
	s->map_real[h] = NULL;
	close(fd);
	h = 0;
	fd = open(argv[1], O_RDONLY);
	s->map_play = malloc(sizeof(char *) * s->height + 1);
	while (h < s->height)
	{
		s->map_play[h] = get_next_line(fd);
		h++;
	}
	s->map_play[h] = NULL;
	close(fd);
}

int	map_check_rectangle(char **argv, t_game *s)
{
	int	fd;

	s->height = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("File error\n");
	s->map_check = get_next_line(fd);
	s->lenght = sl_strlen(s->map_check);
	while (s->map_check)
	{
		free(s->map_check);
		s->map_check = get_next_line(fd);
		if (s->map_check && sl_strlen(s->map_check) != s->lenght)
		{
			print_error("Error map_xy -> lenght\n");
			free(s->map_check);
			free_map_play(s);
			free_map_real(s);
			exit(1);
		}
		s->height++;
	}
	free(s->map_check);
	close(fd);
	return (0);
}

void	wall_error(t_game *s)
{
	print_error("Error map_wall if");
	free_map_play(s);
	free_map_real(s);
	exit(1);
}

void	map_wallandpart(t_game *s)
{
	int	h;
	int	l;

	h = -1;
	while (++h < s->height)
	{
		l = -1;
		while (++l < s->lenght)
		{
			map_count_part(s->map_real[h][l], s);
			check_player(h, l, s);
			if (h == 0 || h == s->height - 1)
			{
				if (s->map_real[h][l] != '1')
					wall_error(s);
			}
			else
				if (s->map_real[h][0] != '1'
					|| s->map_real[h][s->lenght - 1] != '1')
					wall_error(s);
		}
	}
	map_count_part_check(s);
}
