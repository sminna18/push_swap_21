/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:57:56 by sminna            #+#    #+#             */
/*   Updated: 2021/11/14 20:00:41 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_swap *swap)
{
	int	a;
	int	b;
	int	c;

	a = swap->masa[0]->top;
	b = swap->masa[1]->top;
	c = swap->masa[2]->top;
	if (c > a && a > b)
		sort_sa(swap, 1);
	if (a < b && a > c)
		sort_rra(swap, 1);
	if (c < a && c > b)
		sort_ra(swap, 1);
	if (c > a && c < b)
	{
		sort_sa(swap, 1);
		sort_ra(swap, 1);
	}
	if (c < b && b < a)
	{
		sort_sa(swap, 1);
		sort_rra(swap, 1);
	}
}

void	sort_five_2(t_swap *swap)
{
	while (swap->cb)
	{
		if (swap->masb[0]->top > swap->masa[3]->top && \
		swap->masb[0]->top < swap->masa[0]->top)
			sort_pa (swap, 1);
		else if (swap->masa[3]->top > swap->masa[0]->top && (swap->masb[0]->top \
		> swap->masa[3]->top || swap->masb[0]->top < swap->masa[0]->top))
			sort_pa (swap, 1);
		else
			sort_ra(swap, 1);
	}
	if (!swap->masa[1]->top || !swap->masa[2]->top)
		while (swap->masa[0]->top)
			sort_ra (swap, 1);
	if (!swap->masa[3]->top || !swap->masa[4]->top)
		while (swap->masa[0]->top)
			sort_rra (swap, 1);
}

void	sort_five(t_swap *swap)
{
	int	i;

	i = 0;
	sort_pb (swap, 1);
	sort_pb (swap, 1);
	sort_three(swap);
	while (swap->cb > 1)
	{
		if (swap->masb[0]->top > swap->masa[2]->top && \
		swap->masb[0]->top < swap->masa[0]->top)
			sort_pa (swap, 1);
		else if (swap->masa[2]->top > swap->masa[0]->top && (swap->masb[0]->top \
		> swap->masa[2]->top || swap->masb[0]->top < swap->masa[0]->top))
			sort_pa (swap, 1);
		else
			sort_ra (swap, 1);
	}
	sort_five_2(swap);
}

void	sort_fore(t_swap *swap)
{
	int	i;

	i = 0;
	sort_pb (swap, 1);
	sort_three(swap);
	while (swap->cb)
	{
		if (swap->masb[0]->top > swap->masa[2]->top && \
		swap->masb[0]->top < swap->masa[0]->top)
			sort_pa (swap, 1);
		else if (swap->masa[2]->top > swap->masa[0]->top && (swap->masb[0]->top \
		> swap->masa[2]->top || swap->masb[0]->top < swap->masa[0]->top))
			sort_pa (swap, 1);
		else
			sort_ra(swap, 1);
	}
	if (!swap->masa[1]->top || !swap->masa[2]->top)
		while (swap->masa[0]->top)
			sort_ra (swap, 1);
	if (!swap->masa[3]->top)
		while (swap->masa[0]->top)
			sort_rra (swap, 1);
}
