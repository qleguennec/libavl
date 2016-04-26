/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:20:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/04/26 14:24:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbst.h>
#include <get_next_line.h>
#include <libft.h>

static int		result[4096] = {0};
static t_list	*result_l = NULL;
static size_t	a = 0;

static void		print_int(t_bst_tree *t)
{
	t_list		*new;

	if (a >= 4096)
		return ;
	new = ft_lstnew(t->content, sizeof(int));
	ft_lstadd(&result_l, new);
	result[a++] = (*(int*)t->content);
}

static int		cmp_int(void *a, void *b)
{
	int			x;
	int			y;

	x = (*(int*)a);
	y = (*(int*)b);
	if (x > y)
		return (1);
	else if (x < y)
		return (-1);
	return (0);
}

int				main
	(int argc, char **argv)
{
	int			cur;
	char		*line;
	t_bst_tree	*t;
	t_bst_tree	*t1;
	size_t		i;

	t = NULL;
	if (argc != 2)
	{
		ft_putendl("must provide function");
		return (1);
	}
	while (get_next_line(0, &line) > 0)
	{
		cur = ft_atoi(line);
		free(line);
		bst_insert_elem(&t, (void*)&cur, sizeof(cur), &cmp_int);
	}
	if (ft_strequ(argv[1], "sort"))
	{
		bst_traverse_inorder(t, &print_int);
		i = 0;
		while (i < a)
		{
			ft_putnbr(result[i]);
			ft_putchar('\n');
			i++;
		}
		ft_bzero(result, 4096);
	}
	else if (ft_strequ(argv[1], "height"))
	{
		ft_putnbr(bst_height(t));
		ft_putchar('\n');
	}
	else if (ft_strequ(argv[1], "fromarray"))
	{
		bst_traverse_inorder(t, &print_int);
		t1 = bst_fromarray((void*)result, (size_t)a, sizeof(int), &cmp_int);
		return (!(bst_size(t) == bst_size(t1)));
	}
	else if (ft_strequ(argv[1], "size"))
	{
		bst_traverse_inorder(t, &print_int);
		return (!(bst_size(t) == a));
	}
	else if (ft_strequ(argv[1], "fromlist"))
	{
		bst_traverse_inorder(t, &print_int);
		t1 = bst_fromlist(result_l, &cmp_int);
		return (!((bst_size(t) == bst_size(t1)) &&
					(bst_size(t) == (size_t)ft_lstsize(result_l))));
	}
	else
	{
		ft_putstr("unknown function: ");
		ft_putendl(argv[1]);
		return (1);
	}
	return (0);
}
