
#include "push_swap.h"

void	rotate(t_stack_node **stack)
{
	int				len;
	t_stack_node	*last;

	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = find_last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
	last->next->prev = last;
	(*stack)->prev = NULL;
}

void	ra(t_stack_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
