/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:58:05 by dgalactu          #+#    #+#             */
/*   Updated: 2022/02/08 03:44:02 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (s)
	{
		i = 0;
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}

static char	*nospace(char *c)
{
	int	i;

	i = 0;
	while (c[i] == ' ' || c[i] == '\f' || c[i] == '\n' || \
		c[i] == '\r' || c[i] == '\t' || c[i] == '\v')
	{
		i++;
	}
	return (&c[i]);
}

static int	check(long int n, char *str)
{
	int	i;
	int	b;

	b = 0;
	i = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			b++;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		i++;
		str++;
	}
	if (i > 19)
	{
		if (!b)
			return (-1);
		else
			return (0);
	}
	return (n);
}

int	ft_atoi(const char *s)
{
	char		*ss;
	int			b;
	char		*str;
	long int	n;

	ss = (char *) s;
	b = 0;
	n = 0;
	str = nospace(ss);
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			b++;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	if (b)
		n = n * -1;
	return (check(n, nospace(ss)));
}
