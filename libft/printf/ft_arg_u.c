/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:21:23 by cluby             #+#    #+#             */
/*   Updated: 2023/12/21 19:23:29 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_u(unsigned int nbr)
{
	unsigned int	len;
	char			*num;

	len = 0;
	num = ft_uitoa(nbr);
	len = ft_printstr(num);
	free(num);
	return (len);
}
