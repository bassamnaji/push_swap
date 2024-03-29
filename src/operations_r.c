/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 04:10:55 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 18:58:14 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate2(t_var *stack_info, char c, int checker_flag)
{
	int	tmp;
	int	i;

	if ((c == 'b' || c == 'r') && stack_info->btop > 0)
	{
		i = stack_info->btop;
		while (i >= 0)
		{
			if (i == stack_info->btop)
				tmp = stack_info->b_stack[i];
			if (!i)
				stack_info->b_stack[i] = tmp;
			else
				stack_info->b_stack[i] = stack_info->b_stack[i - 1];
			i--;
		}
	}
	if (!checker_flag)
		ft_printf("r%c\n", c);
}

void	rotate(t_var *stack_info, char c, int checker_flag)
{
	int	tmp;
	int	i;

	if ((c == 'a' || c == 'r') && stack_info->atop > 0)
	{
		i = stack_info->atop;
		while (i >= 0)
		{
			if (i == stack_info->atop)
				tmp = stack_info->a_stack[i];
			if (!i)
				stack_info->a_stack[i] = tmp;
			else
				stack_info->a_stack[i] = stack_info->a_stack[i - 1];
			i--;
		}
	}
	rotate2(stack_info, c, checker_flag);
}

static void	rev_rotate2(t_var *stack_info, char c, int checker_flag)
{
	int	tmp;
	int	i;

	if ((c == 'b' || c == 'r') && stack_info->btop > 0)
	{
		i = 0;
		while (i <= stack_info->btop)
		{
			if (!i)
				tmp = stack_info->b_stack[i];
			if (i == stack_info->btop)
				stack_info->b_stack[i] = tmp;
			else
				stack_info->b_stack[i] = stack_info->b_stack[i + 1];
			i++;
		}
	}
	if (!checker_flag)
		ft_printf("rr%c\n", c);
}

void	rev_rotate(t_var *stack_info, char c, int checker_flag)
{
	int	tmp;
	int	i;

	if ((c == 'a' || c == 'r') && stack_info->atop > 0)
	{
		i = 0;
		while (i <= stack_info->atop)
		{
			if (!i)
				tmp = stack_info->a_stack[i];
			if (i == stack_info->atop)
				stack_info->a_stack[i] = tmp;
			else
				stack_info->a_stack[i] = stack_info->a_stack[i + 1];
			i++;
		}
	}
	rev_rotate2(stack_info, c, checker_flag);
}
