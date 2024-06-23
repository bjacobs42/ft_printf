/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:37:36 by bjacobs           #+#    #+#             */
/*   Updated: 2022/10/27 16:24:36 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dp;
	unsigned char	*sp;
	size_t			i;

	i = 0;
	dp = (unsigned char *)dest;
	sp = (unsigned char *)src;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		dp[i] = sp[i];
		i++;
	}
	return (dest);
}
