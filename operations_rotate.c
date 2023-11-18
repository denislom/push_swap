/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:21:41 by dlom              #+#    #+#             */
/*   Updated: 2023/11/18 19:25:36 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **head)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	first_node = *head;
	second_node = first_node->next;
	last_node = ft_find_last_node(*head);
	if (last_node == NULL)
		return ;
	first_node->next = NULL;
	first_node->prev = last_node;
	last_node->next = first_node;
	second_node->prev = NULL;
	*head = second_node;
}

void	ft_rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	ft_rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	ft_ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}
