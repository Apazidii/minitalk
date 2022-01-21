#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void	run(int sig, siginfo_t *info, void *other)
{
    if (sig == SIGUSR1)
        printf("---SIG1--\n");
    else if (sig == SIGUSR2)
        printf("---SIG2--\n");
}

void	manipulate_sa(struct sigaction *sa, sigset_t non_mask)
{
    sa->sa_handler = 0;
    sa->sa_flags = SA_SIGINFO;
    sa->sa_mask = non_mask;
    sa->sa_sigaction = run;
}

int main()
{

    struct sigaction	sa;
    sigset_t			non_mask;
    sigemptyset(&non_mask);
    sigaddset(&non_mask, SIGINT);
    sigaddset(&non_mask, SIGQUIT);
    manipulate_sa(&sa, non_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    int k = getpid();
    printf("%d\n", k);
    while (1)
        pause();
}