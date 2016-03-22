/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avl_traverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 14:17:03 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/22 17:15:36 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libavl-internal.h>

void			avl_traverse_inorder
	(t_avl_tree *t, void (*f) (void*))
{
	if (!t)
		return ;
	avl_traverse_inorder(t->left, f);
	f(t->content);
	avl_traverse_inorder(t->right, f);
}
