/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:43:49 by cluby             #+#    #+#             */
/*   Updated: 2023/10/27 18:58:51 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*str;

	slen = ft_strlen(s);
	if (start >= slen || len == 0)
	{
		str = (char *)ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
	}
	else
	{
		if (len <= slen - start)
			str = (char *)ft_calloc((len + 1), sizeof(char));
		else
			str = (char *)ft_calloc((slen - start + 1), sizeof(char));
		if (!str)
			return (NULL);
		if (len == (size_t) - 1)
			ft_strlcpy(str, s + start, len);
		else
			ft_strlcpy(str, s + start, len + 1);
	}
	return (str);
}
