/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 17:10:45 by tsirirak          #+#    #+#             */
/*   Updated: 2022/06/18 18:13:38 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_un(unsigned int n)
{
	unsigned int	i;
	char			iii;
	int				len;

	i = n;
	len = 0;
	if (i >= 10)
		len += ft_putnbr(i / 10);
	iii = (i % 10) + '0';
	len += write(1, &iii, 1);
	return (len);
}
