/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:49:02 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/25 20:14:54 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> // compile with -lpthread
#include <sys/time.h>

#define MIN -2147483648
#define MAX 2147483647

typedef struct	s_philo
{
	int				id;
	int 			total;
	int				ttd; // temps entre chq repas, si philo mange pas 'ttd' millisconde apres sa premiere bouffe il clamse
	int				tte; // temps que prends un philo pour manger. A besoin de garder les 2 fourchettes pdt le temps
	int				tts; // temps de sieste dun philo
	int				m_eat; // optionnel, nobre de fois que les philo doivent manger, si tous ont manger, le prog s'arrete. Sinon, des quun filo meurt
	long int		last_m;
	pthread_t		th;
	pthread_mutex_t *rf;
	pthread_mutex_t lf;
	pthread_mutex_t	print;
	int				finish;
	long int 		start;
	int				death;
	
}					t_philo;

long int	actual_time(void);
void	ft_usleep(int ms);
int	parse_args(int ac, char **av, t_philo *p);
void	thread_loop(t_philo *p);
void	*routine(void *arg);

void	error(int n);
int		ft_atoi(const char *str);
int		ft_str_is_nbr(char *str);
int		ft_isdigit(int c);
void	ft_putendl_fd(char *s, int fd);
int		ft_strlen(char *s);
void	ft_putchar_fd(char c, int fd);



#endif
