/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:57:46 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/19 19:23:46 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error(int n)
{
	if (n == 0)
		ft_putendl_fd("Error. Invalid arguments", 1);
	if (n == 1)
		ft_putendl_fd("Error. arg not nb", 1);
	exit(EXIT_FAILURE);
}

void	*routine(void *arg)
{
	t_philo *p;
	long int i;
	p = arg;
	i = 0;
	if (p->id % 2 == 0)
		ft_usleep(p->tte / 10);
	while (1)
	{
		pthread_mutex_lock(p->rf);
		printf("%ld - philo %d has taken a fork\n", actual_time() - p->start, p->id);
		pthread_mutex_lock(&p->lf);
		printf("%ld - philo %d has taken a fork\n", actual_time() - p->start, p->id);
		if (actual_time() - p[i].last_m > p[i].ttd)
		{
			printf("%ld - philo %d is dead\n", actual_time() - p->start, p->id);
			exit(0);
		}
		printf("%ld - Philo %d is eating\n", actual_time() - p->start, p->id);
		pthread_mutex_unlock(p->rf);
		pthread_mutex_unlock(&p->lf);
		p[i].last_m = actual_time();
		printf("%ld - philo %d is sleeping\n", actual_time() - p->start, p->id);
		ft_usleep(p[i].tts);
		printf("%ld - philo %d is thinking\n", actual_time() - p->start, p->id);
	}
	return NULL;
}

void	thread_loop(t_philo *p)
{
	int i;
	i = 1;
	printf("%d\n", p->ttd);
	while (i <= p->total)
	{
		p[i].start = actual_time();
		p[i].last_m = actual_time();
		if (pthread_create(&p[i].th, NULL, &routine, &(p[i])) != 0)
			error(2);
		i++;
	}
	i = 1;
	while (i <= p->total)
	{
		if (pthread_join(p[i].th, NULL) != 0)
			error(2);
		i++;
	}
}

int	parse_args(int ac, char **av, t_philo *p)
{
	int i;

	i = 1;
	if ((ac == 5 || ac == 6) && ft_str_is_nbr(av[1]))
	{
		p->total = ft_atoi(av[1]);
		p->ttd = ft_atoi(av[2]);
		p->tte = ft_atoi(av[3]);
		p->tts = ft_atoi(av[4]);
		p->m_eat = -1;
		p->last_m = 0;
	}
	if (ac == 6)
		p->m_eat = ft_atoi(av[5]);
	if (p->total <= 0 || p->ttd <= 0 || p->tte <= 0 || p->tts <= 0)
		return (0);
	while (i <= p->total)
	{
		p[i].id = i;
		p[i].rf = NULL;
		p[i].ttd = ft_atoi(av[2]);
		p[i].tte = ft_atoi(av[3]);
		p[i].tts = ft_atoi(av[4]);
		pthread_mutex_init(&p[i].lf, NULL);
	//	pthread_mutex_init(p[i].rf, NULL);
		p[i].finish = 0;
		if (p->total == 1)
			return (1);
		if (i == p->total)
			p[i].rf = &p[0].lf;
		else
			p[i].rf = &p[i + 1].lf;
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	//printf("%d\n", 42);
	t_philo *philosophers;
	philosophers = NULL;
	philosophers = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philosophers)
		error(0);
	if (!(parse_args(ac, av, philosophers)))
		error(0);
	thread_loop(philosophers);
	return 0;
}
