/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjacobs <bjacobs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:00:36 by bjacobs           #+#    #+#             */
/*   Updated: 2022/11/17 21:07:00 by bjacobs       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

size_t	baselen(unsigned long long n, int base);

char	*ntoa(char *s, unsigned long long n, int base, size_t len);

int		print_c(char c);
int		print_s(char *c);
int		print_d(int n);
int		print_u(unsigned int n);
int		print_x(unsigned int n, char c);
int		print_p(unsigned long long n);
int		ft_printf(const char *fmt, ...);
#endif
