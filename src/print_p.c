/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:12:07 by bjacobs           #+#    #+#             */
/*   Updated: 2022/11/09 16:28:45 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(unsigned long long n)
{
	int		characters;
	size_t	len;
	char	*s;

	len = baselen(n, 16);
	s = (char *)malloc(sizeof(char) * len + 3);
	if (!s)
		return (-1);
	ft_memcpy(s, "0x", 2);
	ntoa(s + 2, n, 16, len);
	characters = print_s(s);
	free(s);
	return (characters);
}
