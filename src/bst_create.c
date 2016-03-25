/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:47:33 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/25 00:59:43 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbst-internal.h>

t_bst_tree			*bst_new
	(void *content, size_t content_size)
{
	t_bst_tree		*new;

	if (!(new = ft_memalloc(sizeof(*new))))
		return (NULL);
	new->content = ft_memalloc(content_size);
	if (!content)
		return (new);
	ft_memcpy(new->content, content, content_size);
	return (new);
}

void				bst_insert_node
	(t_bst_tree **t, t_bst_tree *n, t_cmp f)
{
	t_bst_tree		*cur_node;

	cur_node = *t;
	if (!n)
		return ;
	if (!cur_node)
		*t = n;
	else if (f(n->content, cur_node->content) <= 0)
		bst_insert_node(&cur_node->left, n, f);
	else
		bst_insert_node(&cur_node->right, n, f);
}

void				bst_insert_elem
	(t_bst_tree **t, void *content, size_t content_size, t_cmp f)
{
	t_bst_tree		*new;

	new = bst_new(content, content_size);
	bst_insert_node(t, new, f);
}
