/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:57:46 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/21 18:46:12 by rfkaier          ###   ########.fr       */
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

void	lock_and_print(t_philo *p, int num)
{
	if (num == 0)
	{
		pthread_mutex_lock(&p->print);
		printf("%ld - philo %d has taken a fork\n%ld - philo %d has taken a fork\n%ld - philo %d is eating \n", actual_time() - p->start, p->id,actual_time() - p->start,
		p->id, actual_time() - p->start, p->id);
		pthread_mutex_unlock(&p->print);
	}
	// else if (num == 2)
	// {
	// 	pthread_mutex_lock(&p->print);
	// 	printf("%ld - philo %d is dead\n", actual_time() - p->start, p->id);
	// 	pthread_mutex_unlock(&p->print);
	// 	exit(0);
	// }
	// else if (num == 3)
	// {
	// 	pthread_mutex_lock(&p->print);
	// 	printf("%ld - Philo %d is eating, %d\n", actual_time() - p->start, p->id, p->finish + 1);
	// 	pthread_mutex_unlock(&p->print);
	// 	if(p->finish == p->m_eat)
	// 		exit(1);
	// }
	else if (num == 4)
	{
		pthread_mutex_lock(&p->print);
		printf("%ld - philo %d is sleeping\n", actual_time() - p->start, p->id);
		pthread_mutex_unlock(&p->print);
	}
	else if (num == 5)
	{
		pthread_mutex_lock(&p->print);
		printf("%ld - philo %d is thinking\n", actual_time() - p->start, p->id);
		pthread_mutex_unlock(&p->print);
	}
}	

void	*routine(void *arg)
{
	t_philo *p;
	p = arg;
	if (p->id % 2 == 0)
		ft_usleep(p->tte / 10);
	while (1 && p->m_eat > 0)
	{
		pthread_mutex_lock(p->rf);
		pthread_mutex_lock(&p->lf);
		lock_and_print(p, 0);
		ft_usleep(p->tte);
		pthread_mutex_unlock(p->rf);
		pthread_mutex_unlock(&p->lf);
		p->last_m = actual_time();
		lock_and_print(p, 4);
		ft_usleep(p->tts);
		lock_and_print(p, 5);
		if (p->m_eat == 0)
			exit(0);
		p->m_eat--;
	}
	return NULL;
}


void	*lamort(void *arg)
{
	//int i;
	t_philo *p;
	p = arg;
	while (1)
	{
		if (actual_time() - p->last_m > p->ttd)
		{
			pthread_mutex_lock(&p->print);
			printf("%ld - philo %d is dead\n", actual_time() - p->start, p->id + 1);
			pthread_mutex_unlock(&p->print);
			exit(0);
		}
	}
	return NULL;
}

void	thread_loop(t_philo *p)
{
	pthread_t death;
	int i;
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
		p->m_eat = MAX;
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
		p[i].finish = 0;
		p[i].m_eat = MAX;
		if (ac == 6)
			p[i].m_eat = ft_atoi(av[5]);
		pthread_mutex_init(&p[i].lf, NULL);
		pthread_mutex_init(&p[i].print, NULL);
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
