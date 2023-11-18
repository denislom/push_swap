/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 18:01:04 by dlom              #+#    #+#             */
/*   Updated: 2023/11/18 18:12:41 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_aim(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target_node;
	long	best_match;

	while (b)
	{
		best_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_match)
			{
				best_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match)
			b->target_node = ft_find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	ft_up_from_median(t_node *list)
{
	int	i;
	int	median_index;

	i = 0;
	if (list == NULL)
		return ;
	median_index = ft_lstlen(list) / 2;
	while (list)
	{
		list->current_index = i;
		if (i <= median_index)
			list->up_from_median = true;
		else
			list->up_from_median = false;
		list = list->next;
		i++;
	}
}

t_node	*ft_cheapest(t_node *list)
{
	long	lowest_cost_in_list;
	t_node	*cheapest_node;

	if (list == NULL)
		return (NULL);
	lowest_cost_in_list = LONG_MAX;
	while (list)
	{
		if (list->push_price < lowest_cost_in_list)
		{
			lowest_cost_in_list = list->push_price;
			cheapest_node = list;
		}
		list = list->next;
	}
	cheapest_node->cheapest = true;
	return (cheapest_node);
}

void	ft_how_much_it_cost(t_node *a, t_node *b)
{
	int	len_b;

	len_b = ft_lstlen(b);
	while (b)
	{
		b->push_price = b->current_index;
		if (!(b->up_from_median))
			b->push_price = len_b - (b->current_index);
		if (b->target_node->up_from_median)
			b->push_price += b->target_node->current_index;
		else
			b->push_price += ft_lstlen(a) - (b->target_node->current_index);
		b = b->next;
	}
}
