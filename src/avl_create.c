/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:47:33 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/22 17:11:20 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libavl-internal.h>

t_avl_tree			*avl_new
	(void *content, size_t content_size)
{
	t_avl_tree		*new;

	if (!(new = ft_memalloc(sizeof(*new))))
		return (NULL);
	new->content = ft_memalloc(content_size);
	if (!content)
		return (new);
	ft_memcpy(new->content, content, content_size);
	return (new);
}

void				avl_insert_node
	(t_avl_tree **t, t_avl_tree *n, t_cmp f)
{
	t_avl_tree		*cur_node;

	cur_node = *t;
	if (!n)
		return ;
	if (!cur_node)
		*t = n;
	else if (f(cur_node->content, n->content) <= 0)
		avl_insert_node(&cur_node->left, n, f);
	else
		avl_insert_node(&cur_node->right, n, f);
}

void				avl_insert_elem
	(t_avl_tree **t, void *content, size_t content_size, t_cmp f)
{
	t_avl_tree		*new;

	new = avl_new(content, content_size);
	avl_insert_node(t, new, f);
}
