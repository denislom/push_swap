/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:21:11 by dlom              #+#    #+#             */
/*   Updated: 2023/11/18 20:40:08 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **head)
{
	t_node	*first_node;
	t_node	*prev_last_node;
	t_node	*last_node;

	if (head == NULL || *head == NULL)
		return ;
	first_node = *head;
	last_node = ft_find_last_node(*head);
	if (last_node == NULL || last_node->prev == NULL)
		return ;
	prev_last_node = last_node->prev;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	prev_last_node->next = NULL;
	*head = last_node;
}

void	ft_rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	ft_rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}
