/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:37:40 by sminna            #+#    #+#             */
/*   Updated: 2021/11/14 19:54:20 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	step_counter_up(t_swap *swap, int i, int l)
{
	while (i < swap->ca / 2 + 1)
	{
		swap->masa[i]->stepa = i;
		l = 0;
		while (l < swap->cb / 2)
		{
			if ((swap->masa[i]->top < swap->masb[l]->top && swap->masa[i]->top \
			> swap->masb[l + 1]->top) || (swap->masb[l]->top < \
			swap->masb[l + 1]->top && (swap->masa[i]->top < swap->masb[l]->top \
			|| swap->masa[i]->top > swap->masb[l + 1]->top)))
				swap->masa[i]->stepb = l + 1;
			l++;
		}
		while (l < swap->cb - 1)
		{
			if ((swap->masa[i]->top < swap->masb[l]->top && swap->masa[i]->top \
			> swap->masb[l + 1]->top) || (swap->masb[l]->top < \
			swap->masb[l + 1]->top && (swap->masa[i]->top < swap->masb[l]->top \
			|| swap->masa[i]->top > swap->masb[l + 1]->top)))
				swap->masa[i]->stepb = -swap->cb + l + 1;
			l++;
		}
		i++;
	}
}

void	step_counter_down(t_swap *swap, int i, int l)
{
	i = swap->ca / 2 + 1;
	while (i < swap->ca)
	{
		swap->masa[i]->stepa = -swap->ca + i;
		l = 0;
		while (l < swap->cb / 2)
		{
			if ((swap->masa[i]->top < swap->masb[l]->top && swap->masa[i]->top \
			> swap->masb[l + 1]->top) || (swap->masb[l]->top < \
			swap->masb[l + 1]->top && (swap->masa[i]->top < swap->masb[l]->top \
			|| swap->masa[i]->top > swap->masb[l + 1]->top)))
				swap->masa[i]->stepb = l + 1;
			l++;
		}
		while (l < swap->cb - 1)
		{
			if ((swap->masa[i]->top < swap->masb[l]->top && swap->masa[i]->top \
			> swap->masb[l + 1]->top) || (swap->masb[l]->top < \
			swap->masb[l + 1]->top && (swap->masa[i]->top < swap->masb[l]->top \
			|| swap->masa[i]->top > swap->masb[l + 1]->top)))
				swap->masa[i]->stepb = -swap->cb + l + 1;
			l++;
		}
		i++;
	}
}

void	copy_steps(t_swap *swap)
{
	int	i;

	i = 0;
	while (i < swap->ca)
	{
		swap->masa[i]->c_stepa = swap->masa[i]->stepa;
		swap->masa[i]->c_stepb = swap->masa[i]->stepb;
		i++;
	}
}

void	step_step(t_swap *swap, int i, int a, int b)
{
	swap->masa[i]->step++;
	if (a == 1)
		swap->masa[i]->c_stepa++;
	if (b == 1)
		swap->masa[i]->c_stepb++;
	if (a == -1)
		swap->masa[i]->c_stepa--;
	if (b == -1)
		swap->masa[i]->c_stepb--;
}

void	step_counter_sum(t_swap *swap, int i, int min)
{
	copy_steps(swap);
	while (i < swap->ca)
	{
		while (swap->masa[i]->c_stepa < 0 && swap->masa[i]->c_stepb < 0)
			step_step(swap, i, 1, 1);
		while (swap->masa[i]->c_stepa > 0 && swap->masa[i]->c_stepb > 0)
			step_step(swap, i, -1, -1);
		while (swap->masa[i]->c_stepa > 0)
			step_step(swap, i, -1, 0);
		while (swap->masa[i]->c_stepb > 0)
			step_step(swap, i, 0, -1);
		while (swap->masa[i]->c_stepa < 0)
			step_step(swap, i, 1, 0);
		while (swap->masa[i]->c_stepb < 0)
			step_step(swap, i, 0, 1);
		if (swap->masa[i]->step < min)
		{
			min = swap->masa[i]->step;
			swap->minstep = i;
		}
		i++;
	}
}
