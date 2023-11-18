/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:57:22 by dlom              #+#    #+#             */
/*   Updated: 2023/11/18 20:54:09 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_locker_rotation(t_node **head, t_node *stop_node, char name)
{
	ft_up_from_median(*head);
	if (stop_node->up_from_median)
	{
		while (*head != stop_node)
		{
			if (name == 'a')
				ft_ra(head);
			if (name == 'b')
				ft_rb(head);
		}
	}
	else
	{
		while (*head != stop_node)
		{
			if (name == 'a')
				ft_rra(head);
			if (name == 'b')
				ft_rrb(head);
		}
	}
}

void	ft_shoot(t_node **a, t_node **b)
{
	t_node	*chpst;

	chpst = ft_cheapest(*b);
	if (chpst->up_from_median && chpst->target_node->up_from_median)
	{
		while (chpst != *b && chpst->target_node != *a)
			ft_rr(a, b);
	}
	else if (!(chpst->up_from_median) && !(chpst->target_node->up_from_median))
	{
		while (chpst != *b && chpst->target_node != *a)
			ft_rrr(a, b);
	}
	ft_locker_rotation(a, chpst->target_node, 'a');
	ft_locker_rotation(b, chpst, 'b');
	ft_pa(a, b);
}

void	ft_final_rotation(t_node **a)
{
	t_node	*smallest;

	ft_up_from_median(*a);
	smallest = ft_find_smallest(*a);
	if (smallest->up_from_median)
		while (*a != smallest)
			ft_ra(a);
	else
		while (*a != smallest)
			ft_rra(a);
}

void	ft_big_sort(t_node **a, t_node **b)
{
	int	len_a;

	len_a = ft_lstlen(*a);
	while (len_a-- > 3)
		ft_pb(a, b);
	ft_small_sort_of_3(a);
	while (*b)
	{
		ft_up_from_median(*a);
		ft_up_from_median(*b);
		ft_aim(*a, *b);
		ft_how_much_it_cost(*a, *b);
		ft_shoot(a, b);
	}
	ft_final_rotation(a);
}
