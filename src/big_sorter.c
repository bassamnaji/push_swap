/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bnaji <bnaji@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 08:58:54 by bnaji             #+#    #+#             */
/*   Updated: 2021/11/27 18:57:57 by bnaji            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_sorter(t_var *stack_info)
{
	if (is_a_sorted(stack_info))
		return ;
	while (stack_info->atop > 4)
	{
		while (go_to_closest_b(stack_info))
		{
			sort_b(stack_info, stack_info->atop);
			rotate_to(stack_info, 'b', stack_info->index, stack_info->btop);
			push(stack_info, 'b', 0);
		}
		if (stack_info->atop <= 4)
		{
			solver(stack_info);
			break ;
		}
		if (stack_info->sorted_chunk <= stack_info->chunk_size)
			stack_info->sorted_chunk = 5;
		else
			stack_info->sorted_chunk -= stack_info->chunk_size;
	}
	sort_by_size(stack_info, 'b');
	if (stack_info->atop >= 0)
		solver (stack_info);
	while (stack_info->btop >= 0)
		push(stack_info, 'a', 0);
}

void	big_big_sorter(t_var *stack_info)
{
	if (is_a_sorted(stack_info))
		return ;
	while (stack_info->atop > 4)
	{
		while (go_to_closest_b(stack_info))
			push(stack_info, 'b', 0);
		if (stack_info->atop <= 4)
		{
			solver(stack_info);
			break ;
		}
		if (stack_info->sorted_chunk <= stack_info->chunk_size)
			stack_info->sorted_chunk = 5;
		else
			stack_info->sorted_chunk -= stack_info->chunk_size;
	}
	while (stack_info->btop >= 0)
	{
		get_closest_a(stack_info);
		sort_a(stack_info, stack_info->b_index);
		rotate_to(stack_info, 'b', stack_info->b_index, stack_info->btop);
		rotate_to(stack_info, 'a', stack_info->a_index, stack_info->atop);
		push(stack_info, 'a', 0);
	}
	sort_by_size(stack_info, 'a');
}
