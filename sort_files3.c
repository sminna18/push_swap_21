/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:00:52 by sminna            #+#    #+#             */
/*   Updated: 2021/11/14 20:01:58 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_rra(t_swap *swap, int p)
{
	t_nums	*tem;
	int		i;

	i = swap->ca - 1;
	tem = swap->masa[i];
	while (i > 0)
	{
		swap->masa[i] = swap->masa[i - 1];
		i--;
	}
	swap->masa[0] = tem;
	if (p)
		print_sort_name("rra\n", swap);
}

void	sort_rrb(t_swap *swap, int p)
{
	t_nums	*tem;
	int		i;

	i = swap->cb - 1;
	tem = swap->masb[i];
	while (i > 0)
	{
		swap->masb[i] = swap->masb[i - 1];
		i--;
	}
	swap->masb[0] = tem;
	if (p)
		print_sort_name("rrb\n", swap);
}

void	sort_rrr(t_swap *swap, int p)
{
	t_nums	*tem;
	int		i;

	i = swap->ca - 1;
	tem = swap->masa[i];
	while (i > 0)
	{
		swap->masa[i] = swap->masa[i - 1];
		i--;
	}
	swap->masa[0] = tem;
	i = swap->cb - 1;
	tem = swap->masb[i];
	while (i > 0)
	{
		swap->masb[i] = swap->masb[i - 1];
		i--;
	}
	swap->masb[0] = tem;
	if (p)
		print_sort_name("rrr\n", swap);
}
