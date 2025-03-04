/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wailas <wailas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:47:16 by wailas            #+#    #+#             */
/*   Updated: 2025/02/06 14:59:14 by wailas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack *stack)
{
	t_node	*top;

	if (!stack || !stack->head)
		return ;
	while (stack->head)
	{
		top = stack->head;
		stack->head = top->next;
		free(top);
	}
}

void	printf_stack(t_stack *stack, char *stack_name)
{
	t_node	*current;

	if (!stack || !stack->head)
	{
		ft_printf("%s is empty.\n", stack_name);
		return ;
	}
	ft_printf("%s (size: %d):\n", stack_name, stack->size);
	current = stack->head;
	while (current)
	{
		ft_printf("Data: %d, Index: %d\n", current->data, current->s_index);
		current = current->next;
	}
	ft_printf("--------------\n");
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.head = NULL;
	stack_b.head = NULL;
	stack_a.size = 0;
	stack_b.size = 0;
	if (argc < 2)
		display_error("", NULL, NULL);
	verif_arg(argc, argv);
	init_stack(&stack_a, &stack_b, argc, argv);
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
