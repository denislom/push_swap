/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:24:24 by dlom              #+#    #+#             */
/*   Updated: 2023/11/18 18:08:17 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ft_find_max(t_node *head)
{
	t_node	*temp_max;

	if (head == NULL)
		return (NULL);
	temp_max = head;
	while (head)
	{
		if (head->value > temp_max->value)
			temp_max = head;
		head = head->next;
	}
	return (temp_max);
}

void	ft_small_sort_of_3(t_node **head)
{
	t_node	*max_node;

	max_node = ft_find_max(*head);
	if (max_node == *head)
		ft_ra(head);
	else if (max_node == (*head)->next)
		ft_rra(head);
	if ((*head)->value > (*head)->next->value)
		ft_sa(head);
}
