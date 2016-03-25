/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 09:46:24 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/25 09:51:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbst.h>

void			*bst_search(t_bst_tree *t, void *elem, t_cmp f)
{
	int			cmp;

	if (!t)
		return (NULL);
	cmp = f(elem, t->content);
	if (!cmp)
		return (t->content);
	else if (cmp < 0)
		return (bst_search(t->left, elem, f));
	else
		return (bst_search(t->right, elem, f));
}
