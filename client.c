/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:32:10 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/08 12:44:23 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>

int	retur(unsigned long j, int sin)
{
	if (j > 2147483647 && sin == 1)
		return (-1);
	if (j > 2147483648 && sin == -1)
		return (0);
	return (j * sin);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sin;
	unsigned long	j;

	i = 0;
	j = 0;
	sin = 1;
	while ((str[i] != '\0' && (str[i] >= 9 && str[i] <= 13)) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sin = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10 + (str[i] - '0');
		i++;
	}
	return (retur(j, sin));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	error(void)
{
	write(1, "ERROR\n", ft_strlen("ERROR\n"));
	exit(EXIT_FAILURE);
}

int	main(int argc, char const *argv[])
{
	int	j;
	int	i;
	int	ret;
	int	pid;

	(void)argc;
	pid = ft_atoi(argv[1]);
	if (pid == 0 || pid == 1 || pid == -1)
		error();
	j = -1;
	while (argv[2][++j])
	{
		i = -1;
		while (++i < 8 && (usleep(150) || 1))
		{
			if ((argv[2][j] >> i) & 1)
				ret = kill(ft_atoi(argv[1]), SIGUSR1);
			else
				ret = kill(ft_atoi(argv[1]), SIGUSR2);
			if (ret == -1)
				error();
		}
	}
	return (0);
}
