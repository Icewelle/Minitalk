/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:31:15 by marvin            #+#    #+#             */
/*   Updated: 2024/04/23 23:40:11 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_nl(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

char	*delete_last_line(char **content)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while ((*content)[i] && (*content)[i] != '\n')
		i++;
	if (!(*content)[i])
	{
		free(*content);
		return (*content = NULL, NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(*content) - i + 1));
	if (!str)
		return (free (*content), *content = NULL, NULL);
	i++;
	j = 0;
	while ((*content)[i])
		str[j++] = (*content)[i++];
	str[j] = '\0';
	free(*content);
	*content = NULL;
	return (str);
}

char	*ft_get_line(char **content)
{
	int		i;
	char	*str;

	i = 0;
	while ((*content)[i] && (*content)[i] != '\n')
		i++;
	if ((*content)[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return ((*content) = NULL, NULL);
	str[i] = '\0';
	while (i--)
		str[i] = (*content)[i];
	return (str);
}

char	*ft_test(int fd, char **content)
{
	char	*buffer;
	int		bytesread;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytesread = 1;
	ft_bzero(buffer, BUFFER_SIZE + 1);
	while (bytesread != 0 && !find_nl(buffer))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread == -1)
		{
			free(buffer);
			return (free(*content), *content = NULL, NULL);
		}
		else if (bytesread == 0 && !find_nl(buffer) && !ft_strlen(*content))
			return (free(buffer), free(*content), *content = NULL, NULL);
		buffer[bytesread] = '\0';
		*content = ft_strjoin(*content, buffer);
		if (*content == NULL)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (*content);
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	content = ft_test(fd, &content);
	if (content == NULL)
		return (free(content), content = NULL, NULL);
	tmp = ft_get_line(&content);
	content = delete_last_line(&content);
	return (tmp);
}
