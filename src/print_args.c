/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:55:07 by bjacobs           #+#    #+#             */
/*   Updated: 2022/11/18 18:29:20 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(char c)
{
	int	size;

	size = sizeof(char);
	if (write(1, &c, size) < 0)
		return (-1);
	return (size);
}

int	print_s(char *s)
{
	int	size;

	if (!s)
	{
		s = ft_strdup("(null)");
		if (!s)
			return (-1);
		size = print_s(s);
		return (free(s), size);
	}
	size = ft_strlen(s);
	if (write(1, s, size) < 0)
		return (-1);
	return (size);
}

int	print_u(unsigned int n)
{
	char	*s;
	int		characters;
	size_t	len;

	len = baselen(n, 10);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (-1);
	ntoa(s, n, 10, len);
	characters = print_s(s);
	free(s);
	return (characters);
}

int	print_d(int n)
{
	char	*s;
	int		characters;

	s = ft_itoa(n);
	if (!s)
		return (-1);
	characters = print_s(s);
	free(s);
	return (characters);
}

int	print_x(unsigned int n, char c)
{
	int		characters;
	size_t	len;
	char	*s;

	len = baselen(n, 16);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (-1);
	ntoa(s, n, 16, len);
	if (c == 'X')
		ft_stou(s);
	characters = print_s(s);
	free(s);
	return (characters);
}
