/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:06:32 by sminna            #+#    #+#             */
/*   Updated: 2021/11/15 13:21:34 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_ps(t_swap *swap)
{
	int	i;

	i = 0;
	while (i < swap->c)
	{
		free(swap->masa[i]);
		free(swap->masb[i]);
		i++;
	}
	free(swap->masa);
	free(swap->masb);
	free(swap);
}

void	swap_alone(t_swap *swap, int a, int b)
{
	while (a > 0)
	{
		sort_ra (swap, 1);
		a--;
	}
	while (b > 0)
	{
		sort_rb (swap, 1);
		b--;
	}
	while (a < 0)
	{
		sort_rra (swap, 1);
		a++;
	}
	while (b < 0)
	{
		sort_rrb (swap, 1);
		b++;
	}
}

void	swap_coupl(t_swap *swap)
{
	int	a;
	int	b;

	a = swap->masa[swap->minstep]->stepa;
	b = swap->masa[swap->minstep]->stepb;
	while (a > 0 && b > 0)
	{
		sort_rr (swap, 1);
		a--;
		b--;
	}
	while (a < 0 && b < 0)
	{
		sort_rrr (swap, 1);
		a++;
		b++;
	}
	swap_alone(swap, a, b);
}

void	sort_start(t_swap *swap)
{
	swap->iter = 0;
	sort_pb (swap, 1);
	sort_pb (swap, 1);
	while (swap->ca > 0)
	{
		step_zeroer(swap);
		step_counter_up(swap, 0, 0);
		step_counter_down(swap, 0, 0);
		step_counter_sum(swap, 0, 9999);
		swap_coupl(swap);
		sort_pb (swap, 1);
	}
	find_max(swap);
	roll_b(swap);
	put_in_a(swap);
}

int	main(int argc, char **argv)
{
	t_swap	*swap;

	swap = malloc (sizeof(t_swap));
	argv = parsing_p_s(argc, argv, swap);
	arg_checker(argv, swap);
	int_changer(argv, swap);
	if (sorted_check(swap) && swap->c > 1)
	{
		if (swap->c > 5)
			sort_start(swap);
		else if (swap->c == 5)
			sort_five(swap);
		else if (swap->c == 4)
			sort_fore(swap);
		else if (swap->c == 3)
			sort_three(swap);
		else if (swap->c == 2)
			sort_ra(swap, 1);
	}
	free_ps(swap);
	return (0);
}
