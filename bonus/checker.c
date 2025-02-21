/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidailas <walidailas@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:47:00 by walidailas        #+#    #+#             */
/*   Updated: 2025/02/05 17:45:59 by walidailas       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	my_compare(const char *s1, const char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] && s2[idx] && s1[idx] == s2[idx])
		idx++;
	return (s1[idx] - s2[idx]);
}

int	run_instruction(t_stack *pile1, t_stack *pile2, char *instr)
{
	if (!my_compare(instr, "pa\n"))
		ft_push(pile1, pile2, 'a', false);
	else if (!my_compare(instr, "pb\n"))
		ft_push(pile2, pile1, 'b', false);
	else if (!my_compare(instr, "sa\n"))
		ft_swap(pile1, 'a', false);
	else if (!my_compare(instr, "sb\n"))
		ft_swap(pile2, 'b', false);
	else if (!my_compare(instr, "ss\n"))
		swap_both(pile1, pile2);
	else if (!my_compare(instr, "ra\n"))
		ft_rotate(pile1, 'a', false);
	else if (!my_compare(instr, "rb\n"))
		ft_rotate(pile2, 'b', false);
	else if (!my_compare(instr, "rr\n"))
		rotate_both(pile1, pile2);
	else if (!my_compare(instr, "rra\n"))
		ft_reverse_rotate(pile1, 'a', false);
	else if (!my_compare(instr, "rrb\n"))
		ft_reverse_rotate(pile2, 'b', false);
	else if (!my_compare(instr, "rrr\n"))
		ft_reverse_rotate_both(pile1, pile2);
	else
		return (0);
	return (1);
}

void	ft_check(t_stack *a, t_stack *b)
{
	char	*cmd;

	cmd = get_next_line(0);
	while (cmd)
	{
		if (cmd[0] == '\n')
		{
			free(cmd);
			break ;
		}
		if (!run_instruction(a, b, cmd))
		{
			free(cmd);
			free(get_next_line(-1));
			write(1, "Error\n", 6);
			return ;
		}
		free(cmd);
		cmd = get_next_line(0);
	}
	free(get_next_line(-1));
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
