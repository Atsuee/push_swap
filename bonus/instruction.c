/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidailas <walidailas@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:41:47 by wailas            #+#    #+#             */
/*   Updated: 2025/02/05 15:50:08 by walidailas       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_push(t_stack *dest, t_stack *src, char name, bool print)
{
	t_node	*temp;

	if (!src->head)
		return ;
	temp = src->head;
	src->head = src->head->next;
	temp->next = dest->head;
	dest->head = temp;
	dest->size++;
	src->size--;
	if (print)
		ft_printf("p%c\n", name);
}

void	ft_rotate(t_stack *lst, char name, bool print)
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
	if (print)
		ft_printf("rr%c\n", name);
}

void	ft_reverse_rotate(t_stack *lst, char name, bool print)
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
	if (print)
		ft_printf("r%c\n", name);
}

void	ft_swap(t_stack *lst, char name, bool print)
{
	t_node	*first;
	t_node	*second;

	if (!lst->head || !lst->head->next)
		return ;
	first = lst->head;
	second = lst->head->next;
	first->next = second->next;
	second->next = first;
	lst->head = second;
	if (print)
		ft_printf("s%c\n", name);
}
