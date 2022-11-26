/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsirirak <mavin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:21:31 by tsirirak          #+#    #+#             */
/*   Updated: 2022/11/26 21:20:06 by tsirirak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *fmt, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putnbr_16(unsigned int n);
int		ft_putnbr_16mini(unsigned int n);
int		ft_putnbr_p(unsigned long n);
int		ft_putnbr_un(unsigned int n);
int		ft_putstr(char *s);
size_t	ft_strlen(char *s);

#endif
