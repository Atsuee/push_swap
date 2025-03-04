/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wailas <wailas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:04:39 by wailas            #+#    #+#             */
/*   Updated: 2025/01/29 15:29:38 by wailas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

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
