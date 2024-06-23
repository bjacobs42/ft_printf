/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:51:33 by bjacobs           #+#    #+#             */
/*   Updated: 2022/11/23 17:06:21 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stdio.h>

static int	print_arg(char c, va_list ap)
{
	if (c == 'c')
		return (print_c((char)va_arg(ap, int)));
	else if (c == 's')
		return (print_s(va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (print_d(va_arg(ap, int)));
	else if (c == 'x' || c == 'X')
		return (print_x(va_arg(ap, unsigned int), c));
	else if (c == 'u')
		return (print_u(va_arg(ap, unsigned int)));
	else if (c == 'p')
		return (print_p(va_arg(ap, uintptr_t)));
	else if ('%')
		return (print_c(c));
	return (0);
}

static int	print_fmt_s(const char *fmt)
{
	int	i;

	i = 0;
	while (fmt[i] != '%' && fmt[i])
		i++;
	if (write(1, fmt, sizeof(char) * i) < 0)
		return (-1);
	return (i);
}

static int	iterate_fmt(const char *fmt, va_list ap, int *characters)
{
	int	i;
	int	check;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%')
		{
			check = print_fmt_s(&fmt[i]);
			*characters += check;
			i += check;
		}
		else if (fmt[++i])
		{
			check = print_arg(fmt[i], ap);
			*characters += check;
			i++;
		}
		if (check < 0)
			return (check);
	}
	return (1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		characters;
	int		check;

	va_start(ap, fmt);
	characters = 0;
	check = iterate_fmt(fmt, ap, &characters);
	va_end(ap);
	if (check < 0)
		return (check);
	return (characters);
}
