
#include "push_swap.h"


int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				i;
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
	i = 1;
	while (argv[i])
	{
		ft_lstadd_back(&a, ft_lstnew(argv[i]));
		i++;
	}
	test_print(&a);
	test_print(&b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	test_print(&a); //Testing purposes to print current list.
	test_print(&b);
	rrr(&a, &b);
	rrr(&a, &b);
	test_print(&a);
	test_print(&b);
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	test_print(&a);
	free_list(&a);
	if (argc == 2)
		free_split(original_argv);
	return (0);
}
