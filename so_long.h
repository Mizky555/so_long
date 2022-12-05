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
	char	*str_map;
	int	height;
	int	lenght;
}	t_game;

int map_xy(char **argv, t_game *s);
void    print_error(char *str);
void    check_file(char **argv);
int	sl_strlen(char *s);
void map_wall(t_game *s);
void    map_checkwall(char **str, int    height, int  lenght, int mode);


#endif