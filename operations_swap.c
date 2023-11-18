/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:21:45 by dlom              #+#    #+#             */
/*   Updated: 2023/11/18 19:08:49 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = (*head)->next;
	*head = second;
	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
}

void	ft_ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}

void	ft_sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ft_sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}
