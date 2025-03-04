/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidailas <walidailas@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:14:09 by wailas            #+#    #+#             */
/*   Updated: 2025/02/04 12:26:48 by wailas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include <stdlib.h>

int	ft_is_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_numeric(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	cleanup_args(void *data)
{
	char	**args;
	int		i;

	args = (char **)data;
	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	check_arg_errors(char **args, int i, int allocated)
{
	long	tmp;

	if (!ft_atoi_max(args[i]))
	{
		if (allocated)
			cleanup_args(args);
		display_error("Error\n", NULL, NULL);
	}
	tmp = ft_atoi(args[i]);
	if (ft_is_duplicate(tmp, args, i) || tmp < -2147483648 || tmp > 2147483647)
	{
		if (allocated)
			cleanup_args(args);
		display_error("Error\n", NULL, NULL);
	}
}

void	verif_arg(int argc, char **argv)
{
	int		i;
	char	**args;
	int		allocated;

	allocated = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		allocated = 1;
		i = 0;
	}
	else
	{
		args = argv;
		i = 1;
	}
	while (args[i])
	{
		check_arg_errors(args, i, allocated);
		i++;
	}
	if (allocated)
		ft_free(args);
}
