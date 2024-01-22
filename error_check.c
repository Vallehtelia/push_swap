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

int	error_syntax(char *str)
{
	if (!(*str == '-' || *str == '+' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '-' || *str == '+') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	while (*++str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->content == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_error(t_stack_node **stack)
{
	free_list(stack);
	write(2, "Error\n", 6);
	exit(1);
}
