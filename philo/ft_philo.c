/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:06:11 by rrangwan          #+#    #+#             */
/*   Updated: 2022/07/19 18:33:30 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo(t_gen *phil_gen)
{
	int		i;
	int		n;

	i = 0;
	n = phil_gen->total_p;
	phil_gen->time_start = ft_time();
	while (i < n)
	{
		if (pthread_create(&phil_gen->ind[i].th_id, \
			NULL, &ft_philo2, &phil_gen->ind[i]))
			return (err(phil_gen));
		usleep(200);
		i++;
	}
	ft_stop(phil_gen);
	ft_destroy(phil_gen);
	return (0);
}

void	*ft_philo2(void *ind_v)
{
	t_ind	*ind;
	t_gen	*gen;

	ind = (t_ind *)ind_v;
	gen = ind->gen;
	pthread_mutex_lock(&gen->mut_write);
	ind->time_ate = ft_time();
	pthread_mutex_unlock(&gen->mut_write);
	while (1)
	{
		ft_eat(ind, gen);
		ft_eat2(ind, gen);
		ft_sleep(ind, gen);
		ft_think(ind, gen);
		pthread_mutex_lock(&gen->mut_write);
		if (gen->n_eaten || ind->meals_ate == gen->min_eat)
		{
			pthread_mutex_unlock(&gen->mut_write);
			break ;
		}
		pthread_mutex_unlock(&gen->mut_write);
	}
	return (NULL);
}

int	ft_stop1(t_gen *phil_gen, int i)
{
	pthread_mutex_lock(&phil_gen->mut_write);
	if (ft_time() - phil_gen->ind[i].time_ate > phil_gen->time_die)
	{
		phil_gen->stop = 1;
		phil_gen->n_eaten = 1;
		ft_write(phil_gen, i, 'd');
		pthread_mutex_unlock(&phil_gen->mut_write);
		return (1);
	}
	pthread_mutex_unlock(&phil_gen->mut_write);
	usleep(600);
	return (0);
}

int	ft_stop2(t_gen *phil_gen)
{
	int	i;
	int	n;

	i = 0;
	n = phil_gen->total_p;
	while ((i < n) && (phil_gen->min_eat != -1) && \
	(phil_gen->ind[i].meals_ate >= phil_gen->min_eat))
		i++;
	if (i == n)
	{
		phil_gen->n_eaten = 1;
		phil_gen->stop = 1;
		pthread_mutex_unlock(&phil_gen->mut_write);
		return (1);
	}
	return (0);
}

void	ft_stop(t_gen *phil_gen)
{
	int	i;
	int	n;

	n = phil_gen->total_p;
	while (!phil_gen->n_eaten)
	{
		i = -1;
		while (++i < n)
			if (ft_stop1(phil_gen, i))
				return ;
		pthread_mutex_lock(&phil_gen->mut_write);
		if (phil_gen->stop)
		{
			pthread_mutex_unlock(&phil_gen->mut_write);
			return ;
		}
		if (ft_stop2(phil_gen))
			return ;
		pthread_mutex_unlock(&phil_gen->mut_write);
	}
}
