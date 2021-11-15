/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:00:57 by sminna            #+#    #+#             */
/*   Updated: 2021/11/15 16:09:50 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_sa(t_swap *swap, int p)
{
	t_nums	*tem;

	if (swap->ca < 2)
		return ;
	tem = swap->masa[0];
	swap->masa[0] = swap->masa[1];
	swap->masa[1] = tem;
	if (p)
		print_sort_name("sa\n", swap);
}

void	sort_sb(t_swap *swap, int p)
{
	t_nums	*tem;

	if (swap->cb < 2)
		return ;
	tem = swap->masb[0];
	swap->masb[0] = swap->masb[1];
	swap->masb[1] = tem;
	if (p)
		print_sort_name("sb\n", swap);
}

void	sort_ss(t_swap *swap, int p)
{
	t_nums	*tem;

	if (swap->ca < 2 || swap->cb < 2)
		return ;
	tem = swap->masa[0];
	swap->masa[0] = swap->masa[1];
	swap->masa[1] = tem;
	tem = swap->masb[0];
	swap->masb[0] = swap->masb[1];
	swap->masb[1] = tem;
	if (p)
		print_sort_name("ss\n", swap);
}

void	sort_pb(t_swap *swap, int p)
{
	int		i;
	t_nums	*leak;

	if (swap->ca == 0)
		return ;
	i = swap->cb;
	leak = swap->masb[i];
	while (i > 0)
	{
		swap->masb[i] = swap->masb[i - 1];
		i--;
	}
	swap->masb[0] = swap->masa[0];
	i = 0;
	while (i + 1 < swap->ca)
	{
		swap->masa[i] = swap->masa[i + 1];
		i++;
	}
	swap->masa[i] = leak;
	swap->ca--;
	swap->cb++;
	if (p)
		print_sort_name("pb\n", swap);
}

void	sort_pa(t_swap *swap, int p)
{
	int		i;
	t_nums	*leak;

	if (swap->cb == 0)
		return ;
	i = swap->ca;
	leak = swap->masa[i];
	while (i > 0)
	{
		swap->masa[i] = swap->masa[i - 1];
		i--;
	}
	swap->masa[0] = swap->masb[0];
	i = 0;
	while (i + 1 < swap->cb)
	{
		swap->masb[i] = swap->masb[i + 1];
		i++;
	}
	swap->masb[i] = leak;
	swap->cb--;
	swap->ca++;
	if (p)
		print_sort_name("pa\n", swap);
}
