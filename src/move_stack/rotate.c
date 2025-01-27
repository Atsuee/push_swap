/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wailas <wailas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:34:53 by wailas            #+#    #+#             */
/*   Updated: 2025/01/27 12:32:56 by wailas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_rotate(t_stack *lst, char name)
{
	t_node	*first;
	t_node	*temp;

	if (!lst->head || !lst->head->next)
		return ;
	first = lst->head;
	lst->head = lst->head->next;
	temp = lst->head;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
	first->next = NULL;
	ft_printf("r%c\n", name);
}

void	ft_reverse_rotate(t_stack *lst, char name)
{
	t_node	*last;
	t_node	*penultimate;

	if (!lst->head || !lst->head->next)
		return ;
	last = lst->head;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	penultimate->next = NULL;
	last->next = lst->head;
	lst->head = last;
	ft_printf("rr%c\n", name);
}
