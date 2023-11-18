/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlom <dlom@student.42prague.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:18:39 by dlom              #+#    #+#             */
/*   Updated: 2023/11/18 20:53:18 by dlom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_node
{
	int				value;
	int				current_index;
	int				push_price;
	bool			up_from_median;
	bool			cheapest;

	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;

}	t_node;

//ft_list_functions.c
void			ft_create_stack(t_node **list, char **argv, bool input_string);
void			ft_create_and_append_node(t_node **list, int num);
bool			sorted_stack(t_node *list);
int				ft_lstlen(t_node *list);
t_node			*ft_find_smallest(t_node *stack);

//ft_list_funnction2.c
t_node			*ft_find_last_node(t_node *list_head);

//checks.c
int				input_isnt_num(char *str);
int				ft_duplicate_num(t_node *list, int nbr);

//free_functions.c
void			ft_free_stack(t_node **list);
void			ft_free_matrix(char **matrix);
void			ft_free_error(t_node **list, char **argv, bool input_string);

//ft_atol.c
long			ft_atol(char *argv_i);

//small_sort.c
void			ft_small_sort_of_3(t_node **head);
static t_node	*ft_find_max(t_node *head);

//big_sort.c
static void		ft_locker_rotation(t_node **head, t_node *stop_node, char name);
void			ft_shoot(t_node **a, t_node **b);
void			ft_final_rotation(t_node **a);
void			ft_big_sort(t_node **a, t_node **b);

//big_sort_utils.c
void			ft_up_from_median(t_node *list);
void			ft_aim(t_node *a, t_node *b);
void			ft_how_much_it_cost(t_node *a, t_node *b);
t_node			*ft_cheapest(t_node *list);

//operations_swap.c
static void		swap(t_node **head);
void			ft_sa(t_node **a);
void			ft_sb(t_node **b);
void			ft_ss(t_node **a, t_node **b);

//operations_rotate.c
static void		rotate(t_node **head);
void			ft_rr(t_node **a, t_node **b);
void			ft_rb(t_node **b);
void			ft_ra(t_node **a);

//operations_reverse_rotate.c
static void		reverse_rotate(t_node **head);
void			ft_rrb(t_node **b);
void			ft_rrr(t_node **a, t_node **b);
void			ft_rra(t_node **a);

//operations_push.c
static void		push(t_node **dest, t_node **src);
void			ft_pb(t_node **a, t_node **b);
void			ft_pa(t_node **a, t_node **b);

#endif