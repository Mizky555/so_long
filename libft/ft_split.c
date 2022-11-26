/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:53:51 by tsirirak          #+#    #+#             */
/*   Updated: 2022/11/26 23:49:25 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_leen(char *s, char c, int check)
{
	int	len_i;
	int	j;

	len_i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			len_i++;
			j = 0;
			while (*s != c && *s != '\0')
			{
				j++;
				s++;
			}
		}
		if (check == 2)
			return (j);
	}
	return (len_i);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		j;
	int		i_str;
	int		len_i;
	int		count;

	len_i = ft_leen(s, c, 1);
	str = malloc(sizeof(char *) * (len_i + 1));
	if (str == NULL)
		return (NULL);
	i_str = 0;
	while (i_str < len_i)
	{
		j = ft_leen(s, c, 2);
		str[i_str] = ft_calloc(sizeof(char), (j + 1));
		while (*s == c && *s)
			s++;
		count = 0;
		while (j > count)
			str[i_str][count++] = *s++;
		i_str++;
	}
	str[i_str] = NULL;
	return (str);
}
