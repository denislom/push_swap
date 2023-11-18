/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:15:56 by dlom              #+#    #+#             */
/*   Updated: 2023/11/18 17:16:31 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *argv_i)
{
	long	output_num;
	int		sign;
	int		i;

	output_num = 0;
	sign = 1;
	i = 0;
	while (argv_i[i]
		&& (argv_i[i] == ' ' || argv_i[i] == '\n' || argv_i[i] == '\t'
			|| argv_i[i] == '\v' || argv_i[i] == '\f' || argv_i[i] == '\r'))
		i++;
	if (argv_i[i] == '+')
		i++;
	else if (argv_i[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (argv_i[i] >= '0' && argv_i[i] <= '9')
		output_num = (output_num * 10) + (argv_i[i++] - '0');
	return (output_num * sign);
}
