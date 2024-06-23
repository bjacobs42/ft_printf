/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:37:23 by bjacobs           #+#    #+#             */
/*   Updated: 2022/11/03 17:04:25 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	diglen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		start;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = diglen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	start = 0;
	str[len] = '\0';
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
		start = 1;
	}
	while (len-- > start)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}
