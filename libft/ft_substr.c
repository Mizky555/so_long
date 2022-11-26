/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 01:19:29 by tsirirak          #+#    #+#             */
/*   Updated: 2022/11/26 23:45:02 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = start;
	j = 0;
	if (len == 0 || (start + 1 > ft_strlen(s)))
		len = 0;
	if (start + len > ft_strlen(s) && start + 1 <= ft_strlen(s))
		len = ft_strlen(s) - start;
	if (len > ft_strlen(s))
		str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (j < len && i <= ft_strlen(s))
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
