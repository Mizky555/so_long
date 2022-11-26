/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 04:11:28 by tsirirak          #+#    #+#             */
/*   Updated: 2022/04/06 20:03:53 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > i)
	{
		j = 0;
		while ((i + j) < len && haystack[i + j] == needle[j] && needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)&(haystack[i]));
		i++;
	}
	return (0);
}
