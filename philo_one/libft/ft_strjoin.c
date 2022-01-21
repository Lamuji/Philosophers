/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:44:14 by rfkaier           #+#    #+#             */
/*   Updated: 2021/04/14 11:45:31 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		len_s2;
	char		*dest;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (i + len_s2 + 1));
	if (!dest)
		return (NULL);
	i = -1;
	while (s1[++i])
		dest[i] = s1[i];
	len_s2 = -1;
	while (s2[++len_s2])
	{
		dest[i] = s2[len_s2];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
