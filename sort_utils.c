/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:55:05 by sminna            #+#    #+#             */
/*   Updated: 2021/11/14 19:57:46 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_check(t_swap *swap)
{
	int	i;

	i = 0;
	while (i < swap->c - 1)
	{
		if (swap->masa[i]->top > swap->masa[i + 1]->top)
			return (1);
		i++;
	}
	return (0);
}

void	step_zeroer(t_swap *swap)
{
	int	i;

	i = 0;
	while (i < swap->ca)
	{
		swap->masa[i]->stepb = 0;
		swap->masa[i]->stepa = 0;
		swap->masa[i]->step = 0;
		i++;
	}
}

void	roll_b(t_swap *swap)
{
	int	i;

	i = 0;
	if (swap->max < swap->cb / 2 + 1)
	{
		while (i < swap->max)
		{
			sort_rb(swap, 1);
			i++;
		}
	}
	else if (swap->max >= swap->cb / 2)
	{
		while (i < swap->cb - swap->max)
		{
			sort_rrb(swap, 1);
			i++;
		}
	}
}

void	find_max(t_swap *swap)
{
	int	i;
	int	max;

	i = 0;
	max = -1;
	while (i < swap->cb)
	{
		if (swap->masb[i]->top > max)
		{
			max = swap->masb[i]->top;
			swap->max = i;
		}
		i++;
	}
}

void	put_in_a(t_swap *swap)
{
	int	i;
	int	b;

	i = 0;
	b = swap->cb;
	while (i < b)
	{
		sort_pa(swap, 1);
		i++;
	}
}
