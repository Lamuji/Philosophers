/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:44:07 by rfkaier           #+#    #+#             */
/*   Updated: 2021/04/14 11:51:36 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*p_courant;

	p_courant = *alst;
	if (*alst)
	{
		while (p_courant -> next != NULL)
			p_courant = p_courant -> next;
		p_courant -> next = new;
		p_courant = new;
	}
	else
		*alst = new;
}
