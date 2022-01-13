/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfkaier <rfkaier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:49:02 by rfkaier           #+#    #+#             */
/*   Updated: 2022/01/13 16:38:04 by rfkaier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
#define PHILO_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h> // compile with -lpthread
#include <time.h>
#include "libft/libft.h"

#define MIN -2147483648
#define MAX 2147483647

typedef struct philo
{
	int		id;
	int		ttd;
	int		tte;
	int		tts;
	int		time;
	
};			t_philo


#endif
