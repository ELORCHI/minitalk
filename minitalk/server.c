

#include <unistd.h>
#include <signal.h>

#include <stdio.h>

void function(int sig)
{
    printf("HOLA\n");
}


int main(int argc, char const *argv[])
{
    pid_t pid = getpid();

    printf("PDI: %d\n", pid);


    signal(9, function);
    // signal(SIGUSR2, function);

    while (0x1)
        pause();

    return 0;
}
