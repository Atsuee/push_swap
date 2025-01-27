/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wailas <wailas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:43:46 by wailas            #+#    #+#             */
/*   Updated: 2025/01/27 17:24:41 by wailas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
			display_error("Error: Invalid number");
			return (NULL);
		}
		nb[i] = atoi(argv[i]);
		i++;
	}
	return (nb);
}

void	handle_quotes_and_spaces(int *argc, char ***argv)
{
	char	*new_input;
	char	**new_argv;
	int		i;

	new_input = malloc(strlen(*argv[0]) + 1);
	if (!new_input)
	{
		display_error("Memory allocation failed");
		return ;
	}
	strcpy(new_input, (*argv)[0]);
	i = 0;
	while (new_input[i])
	{
		if (new_input[i] == '"')
			new_input[i] = ' ';
		i++;
	}
	new_argv = ft_split(new_input, ' ');
	free(new_input);
	*argv = new_argv;
	*argc = count_words(*new_argv, ' ');
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
		display_error("Error: Failed to parse arguments");
		return ;
	}
	nb = convert_args_to_int(new_argc, unified_args);
	free_split(unified_args);
	if (!nb)
	{
		display_error("Error: Memory allocation failed");
		return ;
	}
	initialize_stack_data(stack_a, new_argc, nb);
	free(nb);
}
