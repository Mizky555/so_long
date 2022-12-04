/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus->c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 04:08:00 by tsirirak          #+#    #+#             */
/*   Updated: 2022/10/03 04:30:29 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset_gn(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)b)[i] = c;
		i++;
	}
	return (b);
}

int	ft_strlen_gn(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_strchr_l(char *s, int i)
{
	char	*str;

	str = NULL;
	if (s && s[i])
	{
		while (i < ft_strlen_gn(s))
		{
			if (s[i] == '\n' && (i + 1) < ft_strlen_gn(s))
			{
				str = ft_join(str, &s[i + 1], ft_strlen_gn(&s[i + 1]));
				if (!str[0])
				{
					free(str);
					str = NULL;
				}
				if (s)
					free(s);
				return (str);
			}
			i++;
		}
	}
	if (s)
		free(s);
	return (NULL);
}

int	len_nl(char *buf, int len_buf, int mode)
{
	int	i;

	i = 0;
	if (buf)
	{
		while (i < len_buf)
		{
			if (buf[i] == '\n')
				return (i + 1);
			i++;
		}
		if (mode == 1)
			return (len_buf);
		else if (mode == 2)
			return (0);
	}
	return (0);
}
