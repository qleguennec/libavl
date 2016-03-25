/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libavl-internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 22:20:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/25 00:22:37 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBAVL_INTERNAL_H
# define LIBAVL_INTERNAL_H

#include <libft.h>
#include <stdio.h>

typedef int (*t_cmp) (void*, void*);

typedef struct			s_avl_tree
{
	void				*content;
	struct s_avl_tree	*left;
	struct s_avl_tree	*right;
}						t_avl_tree;

t_avl_tree				*avl_fromarray
	(void *arr, size_t length, size_t elem_size, t_cmp f);
t_avl_tree				*avl_fromlist
	(t_list *l, t_cmp f);
t_avl_tree				*avl_new
	(void *content, size_t content_size);
void					avl_insert_node
	(t_avl_tree **t, t_avl_tree *n, t_cmp f);
void					avl_insert_elem
	(t_avl_tree **t, void *content, size_t content_size, t_cmp f);
void					avl_traverse_inorder
	(t_avl_tree *t, void (*f) (void*));
int						avl_height
	(t_avl_tree *t);

#endif
