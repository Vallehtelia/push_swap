
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**original_argv;

	a = NULL;
	b = NULL;
	original_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = split(argv[1], ' ');
		original_argv = argv;
		if (!argv)
			return (0);
	}
	create_list(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	if (argc == 2)
		free_split(original_argv);
	free_list(&a);
	return (0);
}
