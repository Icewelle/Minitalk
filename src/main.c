/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 21:28:08 by cluby             #+#    #+#             */
/*   Updated: 2024/07/03 15:38:38 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int i, int (*fd)[2])
{
	if (i > 0)
	{
		close(fd[i - 1][0]);
		close(fd[i - 1][1]);
	}
}

void	free_split(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	main(int argc, char **argv, char **envp)
{
	int	(*fd)[2];
	int	status;

	if (argc != 5)
	{
		ft_printf("4 arguments are required.");
		return (1);
	}
	argv++;
	fd = malloc((argc - 2) * sizeof(int [2]));
	if (!fd)
		raise_error("malloc error", "(*fd)[2] NULL", 1);
	status = manage_forks(argc, argv, envp, fd);
	free(fd);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
