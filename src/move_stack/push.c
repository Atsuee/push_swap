/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wailas <wailas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:34:19 by wailas            #+#    #+#             */
/*   Updated: 2025/01/07 10:37:33 by wailas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_push(t_stack *dest, t_stack *src, char name)
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
	ft_printf("p%c\n", name);
}
