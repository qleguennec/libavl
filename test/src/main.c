/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:20:47 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/24 22:36:06 by qle-guen         ###   ########.fr       */
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
	return (a - b);
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
		return (1);
	if (ft_strequ(argv[1], "sort"))
	{
		while (get_next_line(0, &line) > 0)
		{
			cur = ft_atoi(line);
			free(line);
			avl_insert_elem(&t, (void*)&cur, sizeof(cur), &cmp_int);
		}
	}
	avl_traverse_inorder(t, &print_int);
	i = 0;
	while (i < a)
	{
		ft_putnbr(result[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
