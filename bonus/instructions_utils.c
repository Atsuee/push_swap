/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wailas <wailas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:45:50 by wailas            #+#    #+#             */
/*   Updated: 2025/02/03 15:13:13 by wailas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	push_stack(t_stack *stack, int index, int data)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->data = data;
	tmp->s_index = index;
	tmp->next = stack->head;
	stack->head = tmp;
	stack->size++;
}

bool	ft_atoi_max(char *str)
{
	long long	val;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	val = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			sign *= -1;
		i++;
	}
	if (str[i] == '\0')
		return (false);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		val = val * 10 + (str[i] - '0');
		if ((sign == 1 && val > INT_MAX) || (sign == -1 && (-val) < INT_MIN))
			return (false);
		i++;
	}
	return (true);
}
