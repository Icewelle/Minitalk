/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:05:55 by cluby             #+#    #+#             */
/*   Updated: 2023/10/21 19:05:27 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str;
	char	*destination;

	str = (char *)src;
	destination = (char *)dest;
	if (destination == str || n == 0)
		return (dest);
	while (n--)
	{
		*destination++ = *str++;
	}
	return (dest);
}
