/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_16mini.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:02:10 by tsirirak          #+#    #+#             */
/*   Updated: 2022/06/18 18:12:50 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_16mini(unsigned int n)
{
	unsigned int	i;
	char			iii;
	int				len;

	i = n;
	len = 0;
	if (i > 15)
		len += ft_putnbr_16mini(i / 16);
	if (i % 16 >= 10)
		iii = (i % 16) + 'a' - 10;
	else
		iii = (i % 16) + '0';
	len += write(1, &iii, 1);
	return (len);
}
