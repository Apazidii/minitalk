/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 03:28:28 by dgalactu          #+#    #+#             */
/*   Updated: 2022/02/08 03:44:02 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_exit(char *message)
{
	ft_putendl_fd(message, 1);
	exit(0);
}

static void	func(long int n, int fd)
{
	char	c;

	if (n >= 10)
		func(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;

	num = n;
	if (num < 0)
	{
		num = num * -1;
		write(fd, "-", 1);
	}
	func(num, fd);
}
