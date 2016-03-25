/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:20:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/25 01:00:19 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libavl-internal.h>
#include <get_next_line.h>
#include <libft.h>

static int		result[4096] = {0};
static size_t	a = 0;

static void		print_int(void *x)
{
	if (a >= 4096)
		return ;
	result[a++] = (*(int*)x);
}

static int		cmp_int(void *a, void *b)
{
	int			x;
	int			y;

	x = (*(int*)a);
	y = (*(int*)b);
	return (x - y);
}

int				main
	(int argc, char **argv)
{
	int			cur;
	char		*line;
	t_avl_tree	*t;
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
		avl_insert_elem(&t, (void*)&cur, sizeof(cur), &cmp_int);
	}
	if (ft_strequ(argv[1], "sort"))
	{
		avl_traverse_inorder(t, &print_int);
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
		ft_putnbr(avl_height(t));
		ft_putchar('\n');
	}
	else
	{
		ft_putstr("unknown function: ");
		ft_putendl(argv[1]);
	}
	return (0);
}
