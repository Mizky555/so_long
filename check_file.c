/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:21:13 by tsirirak          #+#    #+#             */
/*   Updated: 2022/12/23 03:29:52 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char **argv)
{
	if (ft_strrchr(argv[1], '.') == NULL)
	{
		print_error("file error\n");
		exit(1);
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 5))
	{
		print_error("file error\n");
		exit(1);
	}
}
