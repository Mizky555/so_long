/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:08:31 by tsirirak          #+#    #+#             */
/*   Updated: 2022/06/18 18:13:20 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_p(unsigned long n)
{
	unsigned long	i;
	char			iii;
	int				len;

	i = n;
	len = 0;
	if (i > 15)
		len += ft_putnbr_p(i / 16);
	if (i % 16 >= 10)
		iii = (i % 16) + 'a' - 10;
	else
		iii = (i % 16) + '0';
	len += write(1, &iii, 1);
	return (len);
}
