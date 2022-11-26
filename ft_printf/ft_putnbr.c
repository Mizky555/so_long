/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:24:53 by tsirirak          #+#    #+#             */
/*   Updated: 2022/06/18 18:11:53 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	i;
	char	iii;
	int		len;

	len = 0;
	i = (long)n;
	if (i < 0)
	{
		len += write(1, "-", 1);
		i *= -1;
	}
	if (i >= 10)
		len += ft_putnbr(i / 10);
	iii = (i % 10) + '0';
	len += write(1, &iii, 1);
	return (len);
}
