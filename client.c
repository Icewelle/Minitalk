/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icetea <icetea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:32:05 by icetea            #+#    #+#             */
/*   Updated: 2024/05/27 23:58:13 by icetea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (write(2, "Wrong number of arguments\n", 26), 1);
	(void)argv;
	printf("Client\n");
	return (0);
}
