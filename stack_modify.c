
#include "push_swap.h"

// static void	push(t_stack_node **dst, t_stack_node **src)
// {
// 	t_stack_node	*push_node;

// 	if (!*src)
// 		return ;
// 	push_node = *src;
// 	*src = (*src)->next;
// 	if (*src)
// 		(*src)->prev = NULL;
// 	push_node->prev = NULL;
// 	if (!*dst)
// 	{
// 		*dst = push_node;
// 		push_node->prev = NULL;
// 	}
// 	else
// 	{
// 		push_node->next = *dst;
// 		push_node->next->prev = push_node;
// 		*dst = push_node;
// 	}
// }

// void	pa(t_stack_node **a, t_stack_node **b)
// {
// 	push(a, b);
// 	ft_printf("pa\n");
// }

// void	pb(t_stack_node **a, t_stack_node **b)
// {
// 	push(b, a);
// 	ft_printf("pb\n");
// }

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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
}


static void	swap(t_stack_node **head)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (*head == NULL || head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	if (first->next != NULL)
		first->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

// void	sb(t_stack_node **head)
// {
// 	int				len;
// 	t_stack_node	*first;
// 	t_stack_node	*second;

// 	len = stack_len(*head);
// 	if (*head == NULL || head == NULL || len == 1)
// 		return ;
// 	first = *head;
// 	second = first->next;
// 	first->next = second->next;
// 	first->prev = second;
// 	second->prev = NULL;
// 	second->next = first;
// 	if (first->next != NULL)
// 		first->next->prev = first;
// 	*head = second;
// 	ft_printf("sb\n");
// }

void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **head_a, t_stack_node **head_b)
{
	swap(head_a);
	swap(head_b);
	ft_printf("ss\n");
}
