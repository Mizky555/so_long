/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:43:45 by tsirirak          #+#    #+#             */
/*   Updated: 2022/11/26 23:56:25 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*s2;

	s2 = malloc(ft_strlen(s1) + 1);
	if (s2 == 0)
		return (0);
	return (ft_memcpy(s2, s1, ft_strlen(s1) + 1));
}
