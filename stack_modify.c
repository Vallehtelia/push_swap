
#include "push_swap.h"

void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_b;

	if (*b == NULL)
		return ;
	temp_b = *b;
	*b = temp_b->next;
	if (*b != NULL)
		(*b)->prev = NULL;
	temp_b->next = *a;
	if (*a != NULL)
		(*a)->prev = temp_b;
	*a = temp_b;
	temp_b->prev = NULL;
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*temp_a;

	if (*a == NULL)
		return ;
	temp_a = *a;
	*a = temp_a->next;
	if (*a != NULL)
		(*a)->prev = NULL;
	temp_a->next = *b;
	if (*b != NULL)
		(*b)->prev = temp_a;
	*b = temp_a;
	temp_a->prev = NULL;
}

void	sa(t_stack_node **head)
{
	int				len;
	t_stack_node	*first;
	t_stack_node	*second;

	len = stack_len(*head);
	if (*head == NULL || head == NULL || len == 1)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	if (first->next != NULL)
		first->next->prev = first;
	*head = second;
}

void	sb(t_stack_node **head)
{
	int				len;
	t_stack_node	*first;
	t_stack_node	*second;

	len = stack_len(*head);
	if (*head == NULL || head == NULL || len == 1)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	first->prev = second;
	second->prev = NULL;
	second->next = first;
	if (first->next != NULL)
		first->next->prev = first;
	*head = second;
}

void	ss(t_stack_node **head_a, t_stack_node **head_b)
{
	sa(head_a);
	sb(head_b);
}
