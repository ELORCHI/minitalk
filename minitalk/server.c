/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:16:20 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/06 15:16:22 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <unistd.h>
#include <signal.h>

#include <stdio.h>

void function(int sig)
{
    printf("HOLA\n");
}


int main(int argc, char const *argv[])
{
    pid_t pid;

	pid = getpid();
    printf("PDI: %d\n", pid);
    signal(SIGUSR1, function);
    signal(SIGUSR2, function);
    while (1)
        pause();
    return 0;
}
