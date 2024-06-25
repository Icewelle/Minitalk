/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:45:56 by marvin            #+#    #+#             */
/*   Updated: 2024/04/23 23:33:57 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int	ft_printf(const char *str, ...);
int	ft_arg_c(char c);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_arg_d(int decimal);
int	ft_arg_i(int decimal);
int	ft_arg_s(char *str);
int	ft_arg_p(unsigned long long ptr);
int	ft_arg_u(unsigned int nbr);
int	ft_hex_len(unsigned	int num);
int	ft_arg_upper_x(unsigned int num);
int	ft_arg_lower_x(unsigned int num);

#endif