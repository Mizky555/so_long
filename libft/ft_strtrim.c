/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:03:23 by tsirirak          #+#    #+#             */
/*   Updated: 2022/11/26 23:48:33 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	start(char *s1, char *set)
{
	size_t	i_s1_start;
	size_t	i_set;

	i_s1_start = 0;
	i_set = 0;
	while (i_set < ft_strlen(set))
	{
		if (s1[i_s1_start] == set[i_set])
		{
			i_s1_start++;
			i_set = 0;
		}
		else
			i_set++;
	}
	return (i_s1_start);
}

size_t	end(char *s1, char *set)
{
	size_t	i_set;
	size_t	i_s1_end;

	i_set = 0;
	i_s1_end = ft_strlen(s1) - 1;
	while (i_set < ft_strlen(set) && (i_set < ft_strlen(set)))
	{
		if (s1[i_s1_end] == set[i_set])
		{
			if (i_s1_end == 0)
				i_set = ft_strlen(set);
			else
			{
				i_s1_end--;
				i_set = 0;
			}
		}
		else
			i_set++;
	}
	return (i_s1_end);
}

char	*ft_strtrim(char *s1, char *set)
{
	size_t	i_s1_start;
	size_t	i_s1_end;
	size_t	i_set;
	size_t	i;
	char	*str;

	if ((s1 == NULL) || (set == NULL))
		return (NULL);
	i_s1_start = start(s1, set);
	if (i_s1_start == ft_strlen(s1))
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}	
	i_s1_end = end(s1, set);
	i = i_s1_start;
	i_set = 0;
	str = (char *)malloc(sizeof(char) * ((i_s1_end - i_s1_start) + 2));
	if (str == NULL)
		return (NULL);
	while (i_set <= (i_s1_end - i))
		str[i_set++] = s1[i_s1_start++];
	str[i_set] = '\0';
	return (str);
}
