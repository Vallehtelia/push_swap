
#include "push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	int				len;
	t_stack_node	*last;
	t_stack_node	*second_last;

	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = find_last_node(*stack);
	second_last = last->prev;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	second_last->next = NULL;
	last->prev = NULL;
}

void	rra(t_stack_node **a_stack)
{
	reverse_rotate(a_stack);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **b_stack)
{
	reverse_rotate(b_stack);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **a_stack, t_stack_node **b_stack)
{
	reverse_rotate(a_stack);
	reverse_rotate(b_stack);
	ft_printf("rrr\n");
}
