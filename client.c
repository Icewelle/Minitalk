/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cluby <cluby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:32:05 by cluby             #+#    #+#             */
/*   Updated: 2024/06/25 12:46:49 by cluby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>

/* void	send_len(char *message, int server_pid)
{
	size_t	len;
	int		i;

	len = strlen(message);
	i = sizeof(size_t) * 8;
    while (i > 0)
    {
        i--;
        if ((len >> i) & 1)
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
        usleep(100);
    }
} */

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

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
		usleep(1000);
	}
}

void	handle_read_receipt(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("1\n");
	else if (signal == SIGUSR2)
		ft_printf("0\n");
}

int	main(int argc, char *argv[])
{
	int					server_pid;
	char				*message;
	int					i;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("Usage : %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	server_pid = ft_atoi(argv[1]);
	sa.sa_handler = &handle_read_receipt;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	send_len(argv[2], server_pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	message = argv[2];
	i = 0;
	while (message[i])
		send_signal(server_pid, message[i++]);
	send_signal(server_pid, '\0');
	return (0);
}
