/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:42:04 by dlom              #+#    #+#             */
/*   Updated: 2023/10/03 21:32:51 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a; // stack

	a = ft_process(argc, argv);
	if (!a || ft_check_dup(a)) //check if there are duplicates
	{
		ft_free(&a);
		ft_print_error();
	}
	if (!ft_check_if_sorted(a)) // check if the stack is sorted
		ft_sort(&a); //if not sorted, let's sort
	ft_free(&a);
	return (0);

}
