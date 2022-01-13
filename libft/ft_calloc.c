/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:43:06 by rfkaier           #+#    #+#             */
/*   Updated: 2021/04/14 11:49:39 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;
	size_t	max;

	max = nmemb * size;
	tab = malloc(max);
	if (!tab)
		return (NULL);
	i = 0;
	while (max--)
	{
		tab[i] = 0;
		i++;
	}
	return ((void *)tab);
}
