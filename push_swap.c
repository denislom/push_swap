/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:42:04 by dlom              #+#    #+#             */
/*   Updated: 2023/11/19 00:27:12 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
https://www.youtube.com/watch?v=OaG81sDEpVk 
	- Oceano push_swap
https://www.youtube.com/watch?v=uBZHMkpsTfg&list=
PLfqABt5AS4FmXeWuuNDS3XGENJO1VYGxl
	- Code Vault: Linked lists
Checker_linux:
https://github.com/rlinsdev/42-Push-swap
Random generator:
https://numbergenerator.org/randomnumbergenerator

	// JUST TEST OF THE LIBFT
	// ft_printf("ahoj");
	// char *line;
	// int fd[2];
	// size_t	i;

	// fd[0] = open("gnl.txt", O_RDONLY);
	// fd[1] = open("gnl2.txt", O_RDONLY);

	// i = 0;
	// while (i < 2)
	// {
	// 	line = get_next_line(fd[i]);
	// 	printf("fd: %d | %s\n", fd[i], line);
	// 	free(line);

	// 	line = get_next_line(fd[i]);
	// 	printf("fd: %d | %s\n", fd[i], line);
	// 	free(line);

	// 	line = get_next_line(fd[i]);
	// 	printf("fd: %d | %s\n", fd[i], line);
	// 	free(line);

	// 	line = get_next_line(fd[i]);
	// 	printf("fd: %d | %s\n", fd[i], line);
	// 	free(line);

	// 	close(fd[i]);
	// 	i++;
	// }

TO TEST IN TERMINAL:
add:
	if (sorted_stack(a))
		write(2, "OK\n", 3);

.push_swap 
 ./push_swap 1 2 3 4 5 6 76 42 | wc -l
*/

#include "push_swap.h"
// #include <fcntl.h>

void	ft_push_swap(t_node **a, t_node **b)
{
	if (ft_lstlen(*a) == 2)
		ft_sa(a);
	if (ft_lstlen(*a) == 3)
		ft_small_sort_of_3(a);
	if (ft_lstlen(*a) > 3)
		ft_big_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_create_stack(&a, argv + 1, argc == 2);
	if (!sorted_stack(a))
		ft_push_swap(&a, &b);
	ft_free_stack(&a);
	return (0);
}
