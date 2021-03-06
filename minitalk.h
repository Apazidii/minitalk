/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgalactu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 03:32:38 by dgalactu          #+#    #+#             */
/*   Updated: 2022/02/08 03:37:02 by dgalactu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *s);
void	ft_putnbr_fd(int n, int fd);
void	error_exit(char *message);

#endif