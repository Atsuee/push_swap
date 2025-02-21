/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidailas <walidailas@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:45:35 by wailas            #+#    #+#             */
/*   Updated: 2025/02/06 11:14:49 by walidailas       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*convert_args_to_int(int argc, char **argv)
{
	int	*nb;
	int	i;

	nb = malloc(sizeof(int) * argc);
	if (!nb)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			free(nb);
			display_error("Error: Invalid number", NULL, NULL);
			return (NULL);
		}
		nb[i] = ft_atoi(argv[i]);
		i++;
	}
	return (nb);
}

void	initialize_stack_data(t_stack *stack_a, int new_argc, int *nb)
{
	int		i;
	t_node	*tmp;

	i = new_argc - 1;
	while (i >= 0)
	{
		push_stack(stack_a, 0, nb[i]);
		i--;
	}
	insertion_sort(nb, new_argc);
	tmp = stack_a->head;
	while (tmp)
	{
		tmp->s_index = index_of(tmp->data, nb);
		tmp = tmp->next;
	}
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	char	**unified_args;
	int		new_argc;
	int		*nb;

	stack_b->head = NULL;
	unified_args = split_arguments(argc, argv, &new_argc);
	if (!unified_args)
	{
		display_error("Error: Failed to parse arguments", NULL, NULL);
		return ;
	}
	nb = convert_args_to_int(new_argc, unified_args);
	free_split(unified_args);
	if (!nb)
	{
		display_error("Error: Memory allocation failed", NULL, NULL);
		return ;
	}
	initialize_stack_data(stack_a, new_argc, nb);
	free(nb);
}
