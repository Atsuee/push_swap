/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wailas <wailas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:33:30 by wailas            #+#    #+#             */
/*   Updated: 2025/02/03 16:31:18 by wailas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	display_error(char *error_msg, void (*cleanup)(void*), void *data)
{
	if (cleanup != NULL)
		cleanup(data);
	write(2, error_msg, ft_strlen(error_msg));
	exit(EXIT_FAILURE);
}

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

int	index_of(int n, int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != n)
		i++;
	return (i);
}
