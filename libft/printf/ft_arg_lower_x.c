/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_lower_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:09:04 by cluby             #+#    #+#             */
/*   Updated: 2023/12/21 19:23:13 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lower_hex(unsigned int num)
{
	if (num >= 16)
	{
		ft_lower_hex(num / 16);
		ft_lower_hex(num % 16);
	}
	else
	{
		if (num < 10)
			ft_printchar((num + '0'));
		else
			ft_printchar((num - 10 + 'a'));
	}
}

int	ft_arg_lower_x(unsigned int num)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_lower_hex(num);
	return (ft_hex_len(num));
}
