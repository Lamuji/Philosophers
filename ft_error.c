/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:11:08 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/26 11:06:46 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	len;

	if (s)
	{
		len = ft_strlen(s);
		write (fd, s, len);
		ft_putchar_fd('\n', fd);
	}
}

void	error(int n)
{
	if (n == 0)
		ft_putendl_fd("Error. Invalid arguments", 1);
	if (n == 1)
		ft_putendl_fd("Error. arg not nb", 1);
	exit(EXIT_FAILURE);
}
