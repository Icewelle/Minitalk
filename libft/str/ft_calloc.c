/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:50:19 by cluby             #+#    #+#             */
/*   Updated: 2023/12/01 14:34:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	check;

	check = -1;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 0;
		size = 0;
	}
	if (nmemb > check / size)
		return (NULL);
	ptr = (char *)malloc (nmemb * size);
	if (ptr)
		ft_bzero (ptr, nmemb * size);
	return (ptr);
}
