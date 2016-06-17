/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:16:36 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/17 21:35:08 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libbst.h>
#include <stdlib.h>

void		bst_delete
	(t_bst_tree *t)
{
	ft_memdel(&t->data);
	free(t);
}

void		bst_delall
	(t_bst_tree **t)
{
	bst_traverse_inorder(*t, &bst_delete);
	ft_memdel((void **)t);
}
