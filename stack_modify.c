/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_modify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:56:20 by vvaalant          #+#    #+#             */
/*   Updated: 2024/01/24 16:07:22 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
