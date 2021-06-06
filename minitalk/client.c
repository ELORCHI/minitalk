/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:32:10 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/06 16:30:16 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int *pinary_to_decimal(char c)
{
	int		*bin;
	int		decimal;
	int		i;
	int		j = 0;

	i = 7;
	bin = (int *)malloc(sizeof(int) * 8);
	while (j < 8)
	{
		bin[j] = 0;
		j++;
	}
	decimal = c - '0';
	while (decimal != 0)
	{
		bin[i] = decimal % 2;
		decimal /= 2;
		i--;
	}
	i = 0;
	while (i < 8)
	{
		printf("%d", bin[i]);
		i++;
	}
	return (bin);
}

char decimal_to_binary(int *bin)
{
	char c;
	return (c);
}

int main(int argc, char const *argv[])
{
	int j;
	int	i;
	int *bin;
	char c;

	i = 0;
	while (argv[2][j] != '\0')
	{
		bin = pinary_to_decimal((char )argv[2][j]);
		while (i < 8)
		{
			if (bin[i] == 0)
				kill(argv[1], SIGUSR1);
			else
				kill(argv[1], SIGUSR2);
		}
		j++;
		free(bin);
	}
	return (0);
}
