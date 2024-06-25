/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:58:02 by cluby             #+#    #+#             */
/*   Updated: 2023/10/21 19:07:22 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destination;
	const char	*source;

	destination = (char *)dest;
	source = (const char *)src;
	if (destination == source || n == 0)
		return (dest);
	if (destination < source)
		while (n--)
			*destination++ = *source++;
	else
		while (n--)
			destination[n] = source[n];
	return (dest);
}
