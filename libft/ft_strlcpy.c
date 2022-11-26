/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:10:39 by tsirirak          #+#    #+#             */
/*   Updated: 2022/11/26 23:50:21 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (size <= 0)
		return (srcsize);
	else if (srcsize + 1 < size)
		ft_memcpy(dst, src, srcsize + 1);
	else
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srcsize);
}
