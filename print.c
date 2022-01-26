/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:59:53 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/26 12:45:07 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine_suit(t_philo *p)
{
	lock_and_print(p, 1);
	ft_usleep(p->tts);
	lock_and_print(p, 2);
}

int	struct_condition(t_philo *p, int i, int ac, char **av)
{
	if (p[i].total <= 0 || p[i].ttd <= 0 || p[i].tte <= 0 || p[i].tts <= 0)
		return (0);
	if (ac == 6)
		p[i].m_eat = ft_atoi(av[5]);
	if (i == p->total)
		p[i].rf = &p[0].lf;
	else
		p[i].rf = &p[i + 1].lf;
	return (1);
}

void	print_eating(t_philo *p)
{
	pthread_mutex_lock(&p->print);
	printf("[%ld] - P %d took a fork\n[%ld] - P %d took a fork\n",
		actual_time() - p->start, p->id, actual_time() - p->start, p->id);
	printf("\033[34;01m[%ld] - P %d is eating 🍱\033[00m\n",
		actual_time() - p->start, p->id);
	p->m_eat--;
	pthread_mutex_unlock(&p->print);
}

void	lock_and_print(t_philo *p, int num)
{
	if (num == 0)
		print_eating(p);
	else if (num == 1)
	{
		pthread_mutex_lock(&p->print);
		printf("[%ld] - P %d is sleeping 💤\n", \
				actual_time() - p->start, p->id);
		pthread_mutex_unlock(&p->print);
	}
	else if (num == 2)
	{
		pthread_mutex_lock(&p->print);
		printf("[%ld] - P %d is thinking 💬\n", \
				actual_time() - p->start, p->id);
		pthread_mutex_unlock(&p->print);
	}
	else if (num == 3)
	{
		printf("%ld - philo %d has taken a fork 🥢\n", \
			actual_time() - p->start, p->id);
		pthread_mutex_unlock(&p->lf);
	}
}
