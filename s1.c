#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int pid = atoi(argv[1]);
    printf("PID: %d\n", pid);
    printf("send sig1\n");
    kill(pid, SIGUSR1);
}

