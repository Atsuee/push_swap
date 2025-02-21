/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wailas <wailas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:23:49 by wailas            #+#    #+#             */
/*   Updated: 2025/01/29 15:24:23 by wailas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_reverse_rotate_both(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a, 'a', false);
	ft_reverse_rotate(b, 'b', false);
	ft_printf("rrr\n");
}

void	swap_both(t_stack *stack1, t_stack *stack2)
{
	ft_swap(stack1, 'a', false);
	ft_swap(stack2, 'b', false);
	ft_printf("ss\n");
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a, 'a', false);
	ft_rotate(stack_b, 'b', false);
	ft_printf("rr\n");
}
