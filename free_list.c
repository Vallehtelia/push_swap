/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaalant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:50:30 by vvaalant          #+#    #+#             */
/*   Updated: 2024/01/09 16:50:32 by vvaalant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack_node **head)
{
	t_stack_node	*temp;

	if (head == NULL || *head == NULL)
		return ;
	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

void	free_split(char **split_arr)
{
	int	i;

	i = 0;
	if (split_arr == NULL)
		return ;
	while (split_arr[i] != NULL)
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}
