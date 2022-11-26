/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:28:08 by tsirirak          #+#    #+#             */
/*   Updated: 2022/06/18 18:12:13 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_16(unsigned int n)
{
	unsigned int	i;
	char			iii;
	int				len;

	i = n;
	len = 0;
	if (i > 15)
	{
		len += ft_putnbr_16(i / 16);
	}
	if ((i % 16 >= 10) && (i % 16 <= 15))
	{
		iii = (i % 16) + '7';
	}
	else if ((i % 16 >= 0) && (i % 16 <= 9))
	{
		iii = (i % 16) + '0';
	}
	len += write(1, &iii, 1);
	return (len);
}
