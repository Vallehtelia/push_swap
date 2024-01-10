
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_stack_node
{
	void				*content;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}					t_stack_node;

int				main(int argc, char **argv);
char			**split(char *str, char separator);
void			ft_lstadd_back(t_stack_node **lst, t_stack_node *new);
t_stack_node	*ft_lstnew(void *content);
void			free_list(t_stack_node **head);
void			free_split(char **split_arr);
int				test_print(t_stack_node **lst);
void			pb(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **head);
void			sb(t_stack_node **head);
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

#endif