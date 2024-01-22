
#include "push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		// ft_printf("debugging2");
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_last_node(t_stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max_node;
	long			n;

	if (!stack)
		return (NULL);
	n = -9223372036854775807;
	while (stack)
	{
		if (stack->content > n)
		{
			n = stack->content;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min_node;
	long			n;

	if (!stack)
		return (NULL);
	n = 9223372036854775807;
	while (stack)
	{
		if (stack->content < n)
		{
			n = stack->content;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
