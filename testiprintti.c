
#include "push_swap.h"

int	test_print(t_stack_node **lst)
{
	int				arguments;
	t_stack_node	*temp;

	if (*lst == NULL)
	{
		printf("empty list\n\n");
		return (0);
	}
	arguments = 1;
	temp = *lst;
	while (temp != NULL)
	{
		printf("node %i is: %s\n", arguments, temp->content);
		if (temp->next == NULL)
			break ;
		arguments++;
		temp = temp->next;
	}
	printf ("\nNow in reverse order to test its double linked list \n\n");
	while (temp != NULL && arguments >= 0)
	{
		printf("node %i is: %s\n", arguments, temp->content);
		if (temp->prev == NULL)
		{
			arguments--;
			break ;
		}
		arguments--;
		temp = temp->prev;
	}
	printf("\n\nend-----of-----print\n\n");
	return (0);
}
