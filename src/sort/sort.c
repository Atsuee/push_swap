/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wailas <wailas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:33:22 by wailas            #+#    #+#             */
/*   Updated: 2025/01/13 12:33:23 by wailas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_rot_sort(t_stack *stack, int min_s_index)
{
	int	a;
	int	b;
	int	c;

	(void)min_s_index;
	a = stack->head->data;
	b = stack->head->next->data;
	c = stack->head->next->next->data;
	if (a < b && b < c)
		return (1);
	if (b < c && a > c)
		return (1);
	if (c < a && a < b)
		return (1);
	return (0);
}

void	simple_sort(t_stack *stack, int length)
{
	int		min_s_index;
	int		r;

	if (is_sorted(stack))
		return ;
	min_s_index = get_min_index(stack);
	r = count(stack->head, min_s_index);
	if (is_rot_sort(stack, min_s_index))
	{
		if (r < length - r)
			ft_rotate(stack, 'a');
		else
			ft_reverse_rotate(stack, 'a');
	}
	else
	{
		ft_swap(stack, 'a');
		if (is_sorted(stack))
			return ;
		if (r < length - r)
			ft_rotate(stack, 'a');
		else
			ft_reverse_rotate(stack, 'a');
	}
}

void	s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	min_index;
	int	iter;
	int	n;

	iter = 0;
	n = length;
	while (iter++ < n - 3)
	{
		min_index = get_min_index(stack_a);
		if (count(stack_a->head, min_index) <= n - min_index - \
			count(stack_a->head, min_index))
			while (stack_a->head->s_index != min_index)
				ft_rotate(stack_a, 'a');
		else
			while (stack_a->head->s_index != min_index)
				ft_reverse_rotate(stack_a, 'a');
		if (is_sorted(stack_a) && stack_b->size == 0)
			return ;
		ft_push(stack_b, stack_a, 'b');
		length--;
	}
	simple_sort(stack_a, length);
	iter = 0;
	while (iter++ < n - 3)
		ft_push(stack_a, stack_b, 'a');
}

void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->s_index <= i)
		{
			ft_push(stack_b, stack_a, 'b');
			ft_rotate(stack_b, 'b');
			i++;
		}
		else if (stack_a->head->s_index <= i + range)
		{
			ft_push(stack_b, stack_a, 'b');
			i++;
		}
		else
			ft_rotate(stack_a, 'a');
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count(stack_b->head, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->s_index != length - 1)
				ft_rotate(stack_b, 'b');
			ft_push(stack_a, stack_b, 'a');
			length--;
		}
		else
		{
			while (stack_b->head->s_index != length - 1)
				ft_reverse_rotate(stack_b, 'b');
			ft_push(stack_a, stack_b, 'a');
			length--;
		}
	}
}
