/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:41:09 by dgalactu          #+#    #+#             */
/*   Updated: 2022/02/08 03:42:21 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive(int sig)
{
	(void)sig;
	ft_putendl_fd("Message received", 1);
	exit(0);
}

void	send_char(int pid, char c)
{
	int	b;

	b = 8;
	while (b--)
	{
		if (c & (1 << b))
			if (kill(pid, SIGUSR2))
				error_exit("\n|error send SIGUSR2|\n");
		if (!(c & (1 << b)))
			if (kill(pid, SIGUSR1))
				error_exit("\n|error send SIGUSR1|\n");
		if (usleep(666))
			error_exit("\n|error wait|\n");
	}
}

void	send_message(int pid, char *message)
{
	while (*message)
	{
		send_char(pid, *message);
		message++;
	}
	send_char(pid, 0);
}

int	main(int argc, char *argv[])
{
	signal(SIGUSR1, receive);
	if (argc != 3)
		ft_putendl_fd("./client pid \"message\"", 1);
	else
		send_message(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
