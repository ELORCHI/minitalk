/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:32:10 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/07 15:38:54 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	int j;
	int i;
	bool ret;

	//check if PID is valid

	j = -1;
	while (argv[2][++j])
	{
		i = -1;
		while (++i < 8 && (usleep(150) || 1))
		{

			if ((argv[2][j] >> i) & 1)
				ret = kill(atoi(argv[1]), SIGUSR1);
			else
				ret = kill(atoi(argv[1]), SIGUSR2);
			if (ret == -1)
				;//ERROOOOOR
		}

	}
	return (0);
}
