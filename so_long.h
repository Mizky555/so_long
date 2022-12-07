/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:38:54 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/05 19:58:48 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./libft/get_next_line_bonus.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_game
{
	char	*map_check;
	char	**map_real;
	int	height;
	int	lenght;
    int count_c;
    int count_e;
    int count_p;
	int	player_h;
	int	player_l;
}	t_game;

int map_check_rectangle(char **argv, t_game *s);
void    print_error(char *str);
void    check_file(char **argv);
int	sl_strlen(char *s);
void map_create(char **argv, t_game *s);
void map_wallandpart(t_game *s);
void    map_count_part(char part, t_game *s);
void    map_count_part_check(t_game *s);

#endif