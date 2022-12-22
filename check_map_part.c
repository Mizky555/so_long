/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:27:44 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/23 03:32:06 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_count_part(char part, t_game *s)
{
	if (part == '0' || part == '1')
		return ;
	else if (part == 'C')
		s->count_c++;
	else if (part == 'E')
		s->count_e++;
	else if (part == 'P')
		s->count_p++;
	else
	{
		print_error("Error map character");
		free_map_play(s);
		free_map_real(s);
		exit(1);
	}
}

void	map_count_part_check(t_game *s)
{
	if (s->count_c < 1 || s->count_e > 1 || s->count_p > 1)
	{
		print_error("Error map count part check");
		exit(1);
	}
}

void	check_player(int h, int l, t_game *s)
{
	if (s->map_real[h][l] == 'P')
	{
		s->player_h = h;
		s->player_l = l;
	}
}

void	free_map_real(t_game *s)
{
	int	i;

	i = 0;
	while (i < s->h)
	{
		free(s->map_real[i]);
		i++;
	}
	free(s->map_real);
}

void	free_map_play(t_game *s)
{
	int	i;

	i = 0;
	while (i < s->h)
	{
		free(s->map_play[i]);
		i++;
	}
	free(s->map_play);
}
