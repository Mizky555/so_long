/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:38:45 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/23 02:36:24 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	s;

	s.count_c = 0;
	s.count_e = 0;
	s.count_p = 0;
	s.player_eat_c = 0;
	s.player_eat_e = 0;
	if (argc == 2)
	{
		map_check_rectangle(argv, &s);
		map_create(argv, &s);
		map_wallandpart(&s);
		ff(&s, s.map_real, s.player_h, s.player_l);
		ff_check(&s);
		s.player_eat_c = 0;
		s.count_walk = 0;
		render(&s);
		return (0);
	}
	else
		print_error("input argument error\n");
	return (0);
}

void	print_error(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	exit(0);
}
