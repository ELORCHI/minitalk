/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 15:16:20 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/08 12:42:39 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int		help;
	long	longn;

	longn = (long)n;
	if (longn < 0)
	{
		ft_putchar('-');
		longn = -1 * longn;
	}
	if (longn <= 9)
		ft_putchar(longn + 48);
	else
	{
		help = longn % 10;
		ft_putnbr(longn / 10);
		ft_putchar(help + 48);
	}
}

void 	store_bits(int bit)
{
	static unsigned char	decimal;
	static char				i;

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

int	main()
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr(pid);
	signal(SIGUSR1, store_bits);
	signal(SIGUSR2, store_bits);
	while (1)
		pause();
	return (0);
}
