/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_changer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:09:21 by sminna            #+#    #+#             */
/*   Updated: 2021/11/14 20:10:26 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_error2(t_swap *swap, int i, int l)
{
	int	o;

	o = 0;
	while (o < i)
	{
		free(swap->masa[o]);
		o++;
	}
	o = 0;
	while (o < l)
	{
		free(swap->masb[o]);
		o++;
	}
	write(1, "Error\n", 6);
	free(swap);
	exit (0);
}

void	top_swap( t_swap *swap)
{
	int	i;
	int	l;

	i = 0;
	while (i < swap->c)
	{
		swap->masa[i]->top = 0;
		l = 0;
		while (l < swap->c)
		{
			if (swap->masa[i]->num > swap->masa[l]->num)
				swap->masa[i]->top++;
			if (swap->masa[i]->num == swap->masa[l]->num && i != l)
				push_error2(swap, swap->c, swap->c);
			l++;
		}
		i++;
	}
}

void	int_changer_b(t_swap *swap)
{
	int	l;

	l = 0;
	swap->masb = malloc(swap->c * sizeof (char **));
	if (!swap->masb)
	{
		free(swap->masa);
		push_error2(swap, swap->c, 0);
	}
	while (l < swap->c)
	{
		swap->masb[l] = malloc(sizeof(t_nums));
		if (!swap->masb[l])
			push_error2(swap, swap->c, l);
		swap->masb[l]->top = -1;
		l++;
	}
}

void	int_changer(char **argv, t_swap *swap)
{
	int	i;

	i = 0;
	swap->masa = malloc(swap->c * sizeof (char **));
	if (!swap->masa)
		push_error(swap);
	while (i < swap->c)
	{
		swap->masa[i] = malloc(sizeof(t_nums));
		if (!swap->masa[i])
			push_error2(swap, i, 0);
		swap->masa[i]->num = ft_atoi(argv[i + swap->i]);
		i++;
	}
	int_changer_b(swap);
	top_swap(swap);
	swap->ca = swap->c;
	swap->cb = 0;
}
