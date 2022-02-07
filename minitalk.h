#ifndef MINITALK_H
#define MINITALK_H

#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd);
int     ft_atoi(const char *s);
void	ft_putnbr_fd(int n, int fd);

#endif