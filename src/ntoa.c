/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ntoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:54:45 by bjacobs           #+#    #+#             */
/*   Updated: 2022/11/09 15:18:10 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	baselen(unsigned long long n, int base)
{
	size_t	len;

	len = 1;
	while (n > (unsigned long long)(base - 1))
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ntoa(char *s, unsigned long long n, int base, size_t len)
{
	unsigned long long	rem;

	s[len] = '\0';
	while (len--)
	{
		rem = n % base;
		if (rem > 9)
			s[len] = rem + 'a' - 10;
		else
			s[len] = rem + '0';
		n /= base;
	}
	return (s);
}
