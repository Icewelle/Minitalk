/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:32:05 by cluby             #+#    #+#             */
/*   Updated: 2024/05/28 20:15:44 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/includes/libft.h"

 void send_signal(int pid, unsigned char character)
{
	int    i;
	unsigned char temp_char;

	i = 8;
	temp_char = character;
	while (i > 0)
	{
		i--;
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(42);
	}
}
int	main(int argc, char *argv[])
{
	int		i;
	__pid_t	pid;
	char	*str;

	if (argc != 3)
		return (write(2, "Wrong number of arguments\n", 26), 1);
	i = 0;
	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (str[i])
	{
		send_signal(pid, str[i]);
		i++;
	}
	send_signal(pid, END_TRANSMISSION);
	return (0);
}
