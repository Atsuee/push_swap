/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wailas <wailas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:24:07 by wailas            #+#    #+#             */
/*   Updated: 2025/01/27 17:24:26 by wailas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

char	**allocate_result_array(int argc, char **argv, int *total_args)
{
	char	**tmp;
	int		i;

	tmp = NULL;
	*total_args = 0;
	i = 1;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		*total_args += count_words(argv[i], ' ');
		free_split(tmp);
		i++;
	}
	return (malloc(sizeof(char *) * (*total_args + 1)));
}

void	fill_result_array(char **result, int argc, char **argv, int *total_args)
{
	char	**tmp;
	int		i;
	int		j;

	i = 1;
	*total_args = 0;
	while (i < argc)
	{
		tmp = ft_split(argv[i], ' ');
		j = 0;
		while (tmp[j])
		{
			result[*total_args] = ft_strdup(tmp[j]);
			(*total_args)++;
			j++;
		}
		free_split(tmp);
		i++;
	}
	result[*total_args] = NULL;
}

char	**split_arguments(int argc, char **argv, int *new_argc)
{
	char	**result;
	int		total_args;

	result = allocate_result_array(argc, argv, &total_args);
	if (!result)
		return (NULL);
	fill_result_array(result, argc, argv, &total_args);
	*new_argc = total_args;
	return (result);
}
