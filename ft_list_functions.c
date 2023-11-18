/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 19:38:02 by dlom              #+#    #+#             */
/*   Updated: 2023/11/18 21:33:14 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_create_stack(t_node **list, char **argv, bool input_string)
{
	long	number;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (input_isnt_num(argv[i]))
			ft_free_error(list, argv, input_string);
		number = ft_atol(argv[i]);
		if (ft_duplicate_num(*list, (int)number))
			ft_free_error(list, argv, input_string);
		if (number > INT_MAX || number < INT_MIN)
			ft_free_error(list, argv, input_string);
		ft_create_and_append_node(list, (int)number);
		i++;
	}
	if (input_string)
		ft_free_matrix(argv);
}

void	ft_create_and_append_node(t_node **list, int num)
{
	t_node	*node;
	t_node	*last_node;

	if (list == NULL)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->value = num;
	node->next = NULL;
	if (*list == NULL)
	{
		*list = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last_node(*list);
		last_node->next = node;
		node->prev = last_node;
	}
}

bool	sorted_stack(t_node *list)
{
	if (list == NULL)
		return (1);
	while (list->next)
	{
		if (list->value > list->next->value)
			return (false);
		list = list->next;
	}
	return (true);
}

int	ft_lstlen(t_node *list)
{
	int	count;

	if (list == NULL)
		return (0);
	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

t_node	*ft_find_smallest(t_node *stack)
{
	long	smallest;
	t_node	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (smallest > stack->value)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}
