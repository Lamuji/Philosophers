/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:44:14 by rfkaier           #+#    #+#             */
/*   Updated: 2021/04/14 11:44:22 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*p_courant;
	t_list	*tmp;

	if (lst)
	{
		p_courant = *lst;
		while (p_courant)
		{
			tmp = p_courant -> next;
			ft_lstdelone(p_courant, del);
			p_courant = tmp;
		}
		*lst = NULL;
	}
}
