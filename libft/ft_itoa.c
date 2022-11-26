/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:03:56 by tsirirak          #+#    #+#             */
/*   Updated: 2022/04/22 23:34:49 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_len(long n)
{
	long	len;

	len = 0;
	if (n < 0)
		n *= -1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	len;
	long	n2;
	char	*yan;

	n2 = (long)n;
	len = ft_len((long)n);
	if (n2 <= 0)
		len++;
	yan = (char *)ft_calloc(sizeof(char), (len + 1));
	if (!yan)
		return (NULL);
	if (n2 == 0)
		yan[0] = '0';
	else if (n2 < 0)
	{
		yan[0] = '-';
		n2 *= -1;
	}
	while (n2)
	{
		yan[--len] = (n2 % 10) + '0';
		n2 = n2 / 10;
	}
	return (yan);
}
