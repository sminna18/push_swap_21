/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:00:55 by sminna            #+#    #+#             */
/*   Updated: 2021/11/15 16:08:38 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ra(t_swap *swap, int p)
{
	t_nums	*tem;
	int		i;

	tem = swap->masa[0];
	i = 0;
	while (i + 1 < swap->ca)
	{
		swap->masa[i] = swap->masa[i + 1];
		i++;
	}
	swap->masa[i] = tem;
	if (p)
		print_sort_name("ra\n", swap);
}

void	sort_rb(t_swap *swap, int p)
{
	t_nums	*tem;
	int		i;

	tem = swap->masb[0];
	i = 0;
	while (i + 1 < swap->cb)
	{
		swap->masb[i] = swap->masb[i + 1];
		i++;
	}
	swap->masb[i] = tem;
	if (p)
		print_sort_name("rb\n", swap);
}

void	sort_rr(t_swap *swap, int p)
{
	t_nums	*tem;
	int		i;

	tem = swap->masa[0];
	i = 0;
	while (i + 1 < swap->ca)
	{
		swap->masa[i] = swap->masa[i + 1];
		i++;
	}
	swap->masa[i] = tem;
	tem = swap->masb[0];
	i = 0;
	while (i + 1 < swap->cb)
	{
		swap->masb[i] = swap->masb[i + 1];
		i++;
	}
	swap->masb[i] = tem;
	if (p)
		print_sort_name("rr\n", swap);
}

void	print_sort_name(char *name, t_swap *swap)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	write(1, name, i);
	swap->iter++;
}

char	**parsing_p_s(int argc, char **argv, t_swap *swap)
{
	if (argc == 2)
	{
		argv = ft_split_ps(argv[1], ' ', swap);
		swap->i = 0;
	}
	else
	{
		swap->c = argc - 1;
		swap->i = 1;
	}
	return (argv);
}
