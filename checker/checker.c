/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 19:26:59 by sminna            #+#    #+#             */
/*   Updated: 2021/11/15 16:10:06 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	sort_funcs2(char *str, t_swap *swap)
{
	if (!ft_strncmp(str, "rra\n", 4))
		sort_rra(swap, 0);
	else if (!ft_strncmp(str, "rrb\n", 4))
		sort_rrb(swap, 0);
	else if (!ft_strncmp(str, "rrr\n", 4))
		sort_rrr(swap, 0);
	else
	{
		write(1, "Error\n", 6);
		free_ps(swap);
		exit(0);
	}
}

void	sort_funcs(char *str, t_swap *swap)
{
	if (!ft_strncmp(str, "sa\n", 3))
		sort_sa(swap, 0);
	else if (!ft_strncmp(str, "sb\n", 3))
		sort_sb(swap, 0);
	else if (!ft_strncmp(str, "ss\n", 3))
		sort_ss(swap, 0);
	else if (!ft_strncmp(str, "pb\n", 3))
		sort_pb(swap, 0);
	else if (!ft_strncmp(str, "pa\n", 3))
		sort_pa(swap, 0);
	else if (!ft_strncmp(str, "ra\n", 3))
		sort_ra(swap, 0);
	else if (!ft_strncmp(str, "rb\n", 3))
		sort_rb(swap, 0);
	else if (!ft_strncmp(str, "rr\n", 3))
		sort_rr(swap, 0);
	else
		sort_funcs2(str, swap);
}

void	start_chek(t_swap *swap)
{
	char	*str;
	int		f;

	f = 1;
	while (f)
	{
		str = get_next_line(0);
		if (!str)
			f = 0;
		else
		{
			sort_funcs(str, swap);
			free(str);
		}
	}
}

int	main(int argc, char **argv)
{
	t_swap	*swap;

	swap = malloc (sizeof(t_swap));
	argv = parsing_p_s(argc, argv, swap);
	arg_checker(argv, swap);
	int_changer(argv, swap);
	start_chek(swap);
	if (!sorted_check(swap))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_ps(swap);
	return (0);
}
