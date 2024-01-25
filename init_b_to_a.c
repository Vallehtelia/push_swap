/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <vvaalant@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:55:10 by vvaalant          #+#    #+#             */
/*   Updated: 2024/01/24 15:55:12 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node;
	t_stack_node	*current_a;
	long			best_match;

	while (b)
	{
		best_match = 9223372036854775807;
		current_a = a;
		while (current_a)
		{
			if (current_a->content > b->content \
				&& current_a->content < best_match)
			{
				best_match = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match == 9223372036854775807)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
