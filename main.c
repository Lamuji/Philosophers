/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:57:46 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/13 17:05:34 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(int n)
{
	if (n == 0)
		ft_putendl_fd("Error. Nb of arg", 1);
	if (n == 1)
		ft_putendl_fd("Error. arg not nb", 1);
	exit(EXIT_FAILURE);
}

int main(int ac, char **av)
{
	int i;
	int *tab;
	int j;
	pthread_t philo[*av[1]];

	tab = malloc(sizeof(int *) * ac - 1);
	j = 0;
	i = 1;
	if (ac < 5 || ac > 6)
		error(0);
	while (av[i])
	{
		if (ft_str_is_nbr(av[i]) == 0)
			error(1);
		tab[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
	
	return 0;
}