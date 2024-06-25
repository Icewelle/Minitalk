/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_upper_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:01:03 by cluby             #+#    #+#             */
/*   Updated: 2023/12/21 19:23:18 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_upper_hex(unsigned int num)
{
	if (num >= 16)
	{
		ft_upper_hex(num / 16);
		ft_upper_hex(num % 16);
	}
	else
	{
		if (num < 10)
			ft_printchar((num + '0'));
		else
			ft_printchar((num - 10 + 'A'));
	}
}

int	ft_arg_upper_x(unsigned int num)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_upper_hex(num);
	return (ft_hex_len(num));
}
