/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:13:22 by dlom              #+#    #+#             */
/*   Updated: 2023/11/18 20:42:30 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*moving_node;

	if (src == NULL || *src == NULL || dest == NULL)
		return ;
	moving_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	moving_node->prev = NULL;
	moving_node->next = NULL;
	if (*dest == NULL)
		*dest = moving_node;
	else
	{
		moving_node->next = *dest;
		moving_node->next->prev = moving_node;
		*dest = moving_node;
	}
}

void	ft_pb(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	ft_pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}
