/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:10:40 by sminna            #+#    #+#             */
/*   Updated: 2021/11/14 20:13:00 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_error(t_swap *swap)
{
	write(1, "Error\n", 6);
	free(swap);
	exit (0);
}

void	big_cheker3(char argv, char num, t_swap *swap)
{
	if (num < argv)
		push_error(swap);
}

void	big_cheker2(char *argv, t_swap *swap, int min)
{
	if (argv[0 + min] != '2')
		return (big_cheker3(argv[0 + min], '2', swap));
	if (argv[1 + min] != '1')
		return (big_cheker3(argv[1 + min], '1', swap));
	if (argv[2 + min] != '4')
		return (big_cheker3(argv[2 + min], '4', swap));
	if (argv[3 + min] != '7')
		return (big_cheker3(argv[3 + min], '7', swap));
	if (argv[4 + min] != '4')
		return (big_cheker3(argv[4 + min], '4', swap));
	if (argv[5 + min] != '8')
		return (big_cheker3(argv[5 + min], '8', swap));
	if (argv[6 + min] != '3')
		return (big_cheker3(argv[6 + min], '3', swap));
	if (argv[7 + min] != '6')
		return (big_cheker3(argv[7 + min], '6', swap));
	if (argv[8 + min] != '4')
		return (big_cheker3(argv[8 + min], '4', swap));
	if (argv[9 + min] != '8' && min == 0)
		return (big_cheker3(argv[9 + min], '8', swap));
	if (argv[9 + min] != '9' && min == 1)
		return (big_cheker3(argv[9 + min], '9', swap));
	push_error(swap);
}

void	big_cheker(char **argv, t_swap *swap)
{
	int	i;
	int	l;
	int	min;

	i = swap->i;
	while (i < swap->c + swap->i)
	{
		l = 0;
		min = 0;
		if (argv[i][l] == '-')
			min = 1;
		while (argv[i][l])
		{
			l++;
			if (l - min > 10)
				push_error(swap);
		}
		if (l - min == 10)
			big_cheker2(argv[i], swap, min);
		i++;
	}
}

void	arg_checker(char **argv, t_swap *swap)
{
	int	i;
	int	l;

	i = swap->i;
	if (swap->c < 1)
		push_error(swap);
	while (i < swap->c + swap->i)
	{
		l = 0;
		if (argv[i][l] == '-')
			l++;
		while (argv[i][l])
		{
			if (argv[i][l] < '0' || argv[i][l] > '9')
				push_error(swap);
			l++;
		}
		i++;
	}
	big_cheker(argv, swap);
}
