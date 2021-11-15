/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminna <sminna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:04:47 by sminna            #+#    #+#             */
/*   Updated: 2021/11/14 20:05:50 by sminna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_nums {
	int		num;
	int		top;
	int		step;
	int		stepa;
	int		stepb;
	int		c_stepa;
	int		c_stepb;
}				t_nums;

typedef struct s_swap {
	t_nums	**masa;
	t_nums	**masb;
	int		c;
	int		i;
	int		ca;
	int		cb;
	int		minstep;
	int		iter;
	int		max;
}				t_swap;

int		ft_atoi(const char *str);
char	**ft_split_ps(char const *s, char c, t_swap *swap);
void	sort_sa(t_swap *swap, int p);
void	sort_sb(t_swap *swap, int p);
void	sort_ss(t_swap *swap, int p);
void	sort_pb(t_swap *swap, int p);
void	sort_pa(t_swap *swap, int p);
void	sort_ra(t_swap *swap, int p);
void	sort_rb(t_swap *swap, int p);
void	sort_rr(t_swap *swap, int p);
void	sort_rra(t_swap *swap, int p);
void	sort_rrb(t_swap *swap, int p);
void	sort_rrr(t_swap *swap, int p);
void	push_error(t_swap *swap);
void	sort_three(t_swap *swap);
void	sort_fore(t_swap *swap);
void	sort_five(t_swap *swap);
void	sort_five_2(t_swap *swap);
int		sorted_check(t_swap *swap);
void	step_zeroer(t_swap *swap);
void	roll_b(t_swap *swap);
void	find_max(t_swap *swap);
void	put_in_a(t_swap *swap);
void	step_counter_up(t_swap *swap, int i, int l);
void	step_counter_down(t_swap *swap, int i, int l);
void	copy_steps(t_swap *swap);
void	step_step(t_swap *swap, int i, int a, int b);
void	step_counter_sum(t_swap *swap, int i, int min);
void	print_sort_name(char *name, t_swap *swap);
void	arg_checker(char **argv, t_swap *swap);
void	int_changer(char **argv, t_swap *swap);
char	**parsing_p_s(int argc, char **argv, t_swap *swap);

#endif 