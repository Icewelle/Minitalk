/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:43:06 by marvin            #+#    #+#             */
/*   Updated: 2024/04/23 23:16:20 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	arg_sort(const char *str, va_list args)
{
	int	len;

	len = 0;
	if (*str == 'c')
		len += ft_arg_c(va_arg(args, int));
	else if (*str == 'd')
		len += ft_arg_d(va_arg(args, int));
	else if (*str == 'i')
		len += ft_arg_i(va_arg(args, int));
	else if (*str == 's')
		len += ft_arg_s(va_arg(args, char *));
	else if (*str == 'p')
		len += ft_arg_p(va_arg(args, unsigned long long));
	else if (*str == '%')
		len += ft_printchar('%');
	else if (*str == 'u')
		len += ft_arg_u(va_arg(args, unsigned int));
	else if (*str == 'x')
		len += ft_arg_lower_x(va_arg(args, unsigned int));
	else if (*str == 'X')
		len += ft_arg_upper_x(va_arg(args, unsigned int));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		varlen;

	varlen = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			varlen += arg_sort(str + 1, args);
			str++;
		}
		else
			varlen += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (varlen);
}
