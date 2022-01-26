/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:57:46 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/26 12:41:26 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*p;

	p = arg;
	if (p->id % 2 == 0)
		ft_usleep(p->tte / 10);
	while (1 && p->m_eat > 0)
	{
		if (p->m_eat == 0)
			exit(0);
		pthread_mutex_lock(&p->lf);
		if (p->total == 1)
		{
			lock_and_print(p, 3);
			break ;
		}
		pthread_mutex_lock(p->rf);
		lock_and_print(p, 0);
		p->last_m = actual_time();
		ft_usleep(p->tte);
		pthread_mutex_unlock(p->rf);
		pthread_mutex_unlock(&p->lf);
		routine_suit(p);
	}
	return (NULL);
}

void	*lamort(void *arg)
{
	t_philo	*p;

	p = arg;
	while (1)
	{
		if (p->m_eat == 0)
			return (NULL);
		if (actual_time() - p->last_m > p->ttd)
		{
			pthread_mutex_lock(&p->print);
			printf("[%ld] - philo %d is dead 😵\n", \
					actual_time() - p->start, p->id);
			pthread_mutex_unlock(&p->print);
			exit(0);
		}
	}
	return (NULL);
}

void	thread_loop(t_philo *p)
{
	pthread_t	death;
	int			i;

	i = 1;
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
		pthread_create(&death, NULL, &lamort, &p[i]);
		pthread_join(death, NULL);
		i++;
	}
}

int	parse_args(int ac, char **av, t_philo *p)
{
	int	i;

	i = 1;
	p->total = ft_atoi(av[i]);
	while (i <= p->total)
	{
		p[i].total = ft_atoi(av[1]);
		p[i].id = i;
		p[i].rf = NULL;
		p[i].ttd = ft_atoi(av[2]);
		p[i].tte = ft_atoi(av[3]);
		p[i].tts = ft_atoi(av[4]);
		p[i].m_eat = MAX;
		p[i].last_m = 0;
		pthread_mutex_init(&p[i].lf, NULL);
		pthread_mutex_init(&p[i].print, NULL);
		struct_condition(p, i, ac, av);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo	*philosophers;
	int		i;

	i = 0;
	philosophers = NULL;
	if (ac != 5 && ac != 6)
		error(0);
	while (av[++i])
	{
		if (ft_str_is_nbr(av[i]) == 0)
			error(0);
		if (ft_atoi(av[i]) < 0 || ft_atoi(av[i]) >= MAX)
			error(0);
	}
	philosophers = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philosophers)
		return (1);
	if (!(parse_args(ac, av, philosophers)))
		error(0);
	thread_loop(philosophers);
	return (0);
}
