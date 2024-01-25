/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:55:56 by vvaalant          #+#    #+#             */
/*   Updated: 2024/01/24 16:56:03 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "./libft/inc/libft.h"
# include "./libft/inc/ft_printf.h"

typedef struct s_stack_node
{
	int					content;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}					t_stack_node;

int				main(int argc, char **argv);
char			**split(char *str, char separator);
void			lstadd_back(t_stack_node **lst, t_stack_node *new);
t_stack_node	*lstnew(int content);
void			free_list(t_stack_node **head);
void			free_split(char **split_arr);
void			pb(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
int				stack_len(t_stack_node *stack);
void			ss(t_stack_node **head_a, t_stack_node **head_b);
t_stack_node	*find_last_node(t_stack_node *head);
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **stack_a);
void			rb(t_stack_node **stack_b);
void			rr(t_stack_node **stack_a, t_stack_node **stack_b);
void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a_stack);
void			rrb(t_stack_node **b_stack);
void			rrr(t_stack_node **a_stack, t_stack_node **b_stack);
int				error_syntax(char *str);
int				error_duplicate(t_stack_node *a, int n);
void			create_list(t_stack_node **a, char **argv);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node \
						*top_node, char stack_name);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			min_on_top(t_stack_node **a);
void			free_error(t_stack_node **stack);

#endif