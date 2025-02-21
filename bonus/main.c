/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wailas <wailas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:50:49 by wailas            #+#    #+#             */
/*   Updated: 2025/02/03 16:36:55 by wailas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	ft_check(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
