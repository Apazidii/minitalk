/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:52:36 by dgalactu          #+#    #+#             */
/*   Updated: 2022/02/08 03:44:02 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	add_bit(int sig, int *bit, int *res_char)
{
	if (sig == SIGUSR1)
	{
		*res_char = *res_char << 1;
		*res_char += 0;
	}
	if (sig == SIGUSR2)
	{
		*res_char = *res_char << 1;
		*res_char += 1;
	}
	(*bit)++;
	return (*res_char);
}

void	run(int sig, siginfo_t *info, void *other)
{
	static int	bit;
	static int	res_char;

	(void)other;
	res_char = add_bit(sig, &bit, &res_char);
	if (bit == 8)
	{
		if (res_char != 0)
			write(1, &res_char, 1);
		else
			if (kill(info->si_pid, SIGUSR1))
				error_exit("\n|error send SIGUSR1|\n");
		res_char = 0;
		bit = 0;
	}
}

void	manipulate_sa(struct sigaction *sa, sigset_t non_mask)
{
	sa->sa_handler = 0;
	sa->sa_flags = SA_SIGINFO;
	sa->sa_mask = non_mask;
	sa->sa_sigaction = run;
}

void	goodbye(int sig)
{
	(void) sig;
	write(1, "\nServer closed. GoodBye :)\n", 12);
	exit(0);
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			non_mask;

	sigemptyset(&non_mask);
	sigaddset(&non_mask, SIGINT);
	sigaddset(&non_mask, SIGQUIT);
	manipulate_sa(&sa, non_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr_fd(getpid(), 1);
	signal(SIGINT, goodbye);
	write(1, "\n", 1);
	while (1)
		pause();
}
