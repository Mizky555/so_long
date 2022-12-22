/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_ff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:28:11 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/23 03:32:17 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ff(t_game *s, char **map, int h, int l)
{
	if (ft_strchr("0CEP", map[h][l]) != NULL)
		ff_count(s, map[h][l]);
	else if (map[h][l] == '1')
		return ;
	map[h][l] = '1';
	ff(s, map, h - 1, l);
	ff(s, map, h + 1, l);
	ff(s, map, h, l - 1);
	ff(s, map, h, l + 1);
}

void	ff_count(t_game *s, char map)
{
	if (map == 'C')
		s->player_eat_c++;
	else if (map == 'E')
		s->player_eat_e++;
}

void	ff_check(t_game *s)
{
	if (s->player_eat_c != s->count_c || s->player_eat_e != 1)
	{
		print_error("Path error ff_check \n");
		free_map_play(s);
		free_map_real(s);
		exit(1);
	}
	free_map_real(s);
}

int	sl_strlen(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\n')
			len++;
		i++;
	}
	return (len);
}
