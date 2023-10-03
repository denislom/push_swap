/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:42:04 by dlom              #+#    #+#             */
/*   Updated: 2023/10/03 17:15:11 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <sys/types.h> // for testing gnl, DELETE afterwards
#include <fcntl.h> // for testing gnl, DELETE afterwards
#include <sys/stat.h> // for testing gnl, DELETE afterwards

int	main(int argc, char **argv)
{
	// t_stack	*a; // stack

	// a = ft_process(argc, argv);
	// if (!a || ft_checkdup(a)) //check if there are duplicates
	// {
	// 	ft_free(&a);
	// 	ft_error();
	// }
	// if (!ft_checksorted(a)) // check if the stack is sorted
	// 	ft_sort(&a); //if not sorted, let's sort
	// ft_free(&a);
	// return (0);
	char *line;
	char *line2;
	int fd[2];
	size_t	i;

	fd[0] = open("gnl.txt", O_RDONLY);
	fd[1] = open("gnl2.txt", O_RDONLY);

	i = 0;
	while (i < 2)
	{
		line = get_next_line(fd[i]);
		line2 = ft_strdup(line);
		ft_printf("fd: %d | %s\n", fd[i], line);
		printf("fd: %d | %s\n", fd[i], line2);
		free(line);

		line = get_next_line(fd[i]);
		printf("fd: %d | %s\n", fd[i], line);
		free(line);

		line = get_next_line(fd[i]);
		printf("fd: %d | %s\n", fd[i], line);
		free(line);

		line = get_next_line(fd[i]);
		printf("fd: %d | %s\n", fd[i], line);
		free(line);

		close(fd[i]);
		i++;
	}

	return (0);
	ft_printf("this is the test of the libft.");

	return (0);
}
