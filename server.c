/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:16:20 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/07 14:16:04 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void 	store_bits(int bit)
{
	static unsigned char	decimal;
	static char	i;

	decimal += (bit == SIGUSR1) << i;
	i++; 
	if (i > 7)
	{
		i = 0;
		write(1, &decimal, 1);
		decimal = 0;
		return ;
	}
}


int main(int argc, char const *argv[])
{
	pid_t pid;

	pid = getpid();
	printf("PDI: %d\n", pid);
	signal(SIGUSR1, store_bits);
	signal(SIGUSR2, store_bits);
	while (1)
		pause();
	return 0;
}
