
#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->content > (*a)->next->content)
		sa(a);
}
