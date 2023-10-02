/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:42:04 by dlom              #+#    #+#             */
/*   Updated: 2023/10/02 23:24:17 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a; // stack

	a = ft_process(argc, argv);
	if (!a || ft_checkdup(a)) //check if there are duplicates
	{
		ft_free(&a);
		ft_error();
	}
	if (!ft_checksorted(a)) // check if the stack is sorted
		ft_sort(&a); //if not sorted, let's sort
	ft_free(&a);
	return (0);
}
