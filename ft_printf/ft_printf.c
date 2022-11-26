/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 01:42:28 by tsirirak          #+#    #+#             */
/*   Updated: 2022/06/18 18:11:13 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "ft_printf.h"

int	ft_printf_2(const char *fmt, va_list args, int len)
{
	if (*(fmt + 1) == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (*(fmt + 1) == 's')
		len += ft_putstr(va_arg(args, char *));
	else if (*(fmt + 1) == 'd' || *(fmt +1) == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (*(fmt + 1) == 'u')
		len += ft_putnbr_un(va_arg(args, unsigned int));
	else if (*(fmt + 1) == 'X')
		len += ft_putnbr_16(va_arg(args, unsigned int));
	else if (*(fmt + 1) == 'x')
		len += ft_putnbr_16mini(va_arg(args, unsigned int));
	else if (*(fmt + 1) == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_putnbr_p(va_arg(args, unsigned long));
	}
	else if (*(fmt + 1) == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start (args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			len = ft_printf_2(fmt, args, len);
			fmt++;
		}
		else
			len += ft_putchar(*fmt);
		fmt++;
	}
	return (len);
}
