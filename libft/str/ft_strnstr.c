/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 11:09:50 by cluby             #+#    #+#             */
/*   Updated: 2023/10/27 18:59:13 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	littlelen;

	littlelen = ft_strlen(little);
	if (!littlelen)
		return ((char *)big);
	while (*big != '\0' && len-- >= littlelen)
	{
		if (!ft_memcmp(big, little, littlelen))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
