/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_traverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:17:03 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/25 09:03:51 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbst.h>

void			bst_traverse_inorder
	(t_bst_tree *t, void (*f) (void*))
{
	if (!t)
		return ;
	bst_traverse_inorder(t->left, f);
	f(t->content);
	bst_traverse_inorder(t->right, f);
}

size_t			bst_height
	(t_bst_tree *t)
{
	if (!t)
		return (-1);
	return (1 + ft_max(bst_height(t->left), bst_height(t->right)));
}

size_t			bst_size
	(t_bst_tree *t)
{
	if (!t)
		return (0);
	return (1 + bst_size(t->left) + bst_size(t->right));
}
