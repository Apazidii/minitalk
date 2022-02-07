#include "minitalk.h"

void error_exit(char *message)
{
    ft_putendl_fd(message, 1);
    exit(0);
}

void send_char(int pid, char c)
{
    int b;

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

void send_message(int pid, char *message)
{
    while (*message)
    {
        send_char(pid, *message);
        message++;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
        ft_putendl_fd("non arg",1);
    else
        send_message(ft_atoi(argv[1]), argv[2]);
}

