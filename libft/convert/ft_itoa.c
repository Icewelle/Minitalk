/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:52:58 by cluby             #+#    #+#             */
/*   Updated: 2023/10/29 19:23:26 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(long nbr)
{	
	size_t	i;

	i = 0;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static	void	ft_itoapos(char *str, long nbr, int size)
{
	while (size)
	{
		str[size-- - 1] = (nbr % 10) + 48;
		nbr /= 10;
	}
}

static	void	ft_itoaneg(char *str, long nbr, int size)
{
	nbr = -nbr;
	while (size)
	{
		str[size-- - 1] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[0] = '-';
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	size_t	size;

	nbr = n;
	size = ft_count(nbr);
	if (nbr <= 0)
		size++;
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nbr >= 0)
		ft_itoapos(str, nbr, size);
	else
		ft_itoaneg(str, nbr, size);
	str[size] = '\0';
	return (str);
}
