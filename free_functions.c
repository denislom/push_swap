/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 15:46:30 by dlom              #+#    #+#             */
/*   Updated: 2023/11/18 16:41:29 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_node **list)
{
	t_node	*temp;
	t_node	*head;

	if (list == NULL)
		return ;
	head = *list;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
	*list = NULL;
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = -1;
	if (matrix == NULL || *matrix == NULL)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix - 1);
}

void	ft_free_error(t_node **list, char **argv, bool input_string)
{
	ft_free_stack(list);
	if (input_string)
		ft_free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}
