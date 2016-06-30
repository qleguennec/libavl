/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 22:20:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/06/30 16:20:38 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBST_H
# define LIBBST_H

# include "libft/libft.h"

typedef int				(*t_cmp) (void*, void*);

typedef struct			s_bst_tree
{
	void				*data;
	struct s_bst_tree	*left;
	struct s_bst_tree	*right;
}						t_bst_tree;

t_bst_tree				*bst_fromarray
	(void *arr, size_t length, size_t elem_size, t_cmp f);
t_bst_tree				*bst_fromlist
	(t_list *l, t_cmp f);
t_bst_tree				*bst_new
	(void *content, size_t content_size);
void					bst_insert_node
	(t_bst_tree **t, t_bst_tree *n, t_cmp f);
void					bst_insert_elem
	(t_bst_tree **t, void *content, size_t content_size, t_cmp f);
void					bst_traverse_inorder
	(t_bst_tree *t, void (*f) (t_bst_tree *t));
size_t					bst_height
	(t_bst_tree *t);
size_t					bst_size
	(t_bst_tree *t);
void					*bst_search
	(t_bst_tree *t, void *elem, t_cmp f);
int						bst_lookup
	(t_bst_tree *t, void *elem, t_cmp f);
void					bst_delete(t_bst_tree *t);
void					bst_delall(t_bst_tree **t);

#endif
