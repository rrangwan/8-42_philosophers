/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:50:02 by rrangwan          #+#    #+#             */
/*   Updated: 2022/07/19 23:46:33 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat1(t_ind *ind, t_gen *gen)
{
	ft_write(gen, ind->i_ind, 'f');
	ft_write(gen, ind->i_ind, 'f');
}

void	ft_eat2(t_ind *ind, t_gen *gen)
{
	if (gen->total_p == 1)
		return ;
	if (ind->lfork == 1 && ind->rfork == 1)
	{
		pthread_mutex_lock(&(gen->mut_write));
		if (!gen->stop)
			ft_write(gen, ind->i_ind, 'e');
		ind->time_ate = ft_time();
		pthread_mutex_unlock(&(gen->mut_write));
		ft_usleep(gen->time_eat, gen);
		pthread_mutex_lock(&(gen->mut_write));
		ind->meals_ate++;
		ind->lfork = 0;
		ind->rfork = 0;
		ind->just_ate = 1;
		pthread_mutex_unlock(&(gen->mut_write));
	}
	pthread_mutex_unlock(&gen->mut_forks[ind->i_ind]);
	pthread_mutex_unlock(&gen->mut_forks[(ind->i_ind + 1) % gen->total_p]);
}

void	ft_eat(t_ind *ind, t_gen *gen)
{
	if (gen->total_p == 1)
		return ;
	if (ind->i_ind % 2 != 0)
	{
		pthread_mutex_lock(&gen->mut_forks[ind->i_ind]);
		pthread_mutex_lock(&gen->mut_forks[(ind->i_ind + 1) % gen->total_p]);
	}
	else
	{
		pthread_mutex_lock(&gen->mut_forks[(ind->i_ind + 1) % gen->total_p]);
		pthread_mutex_lock(&gen->mut_forks[ind->i_ind]);
	}
	pthread_mutex_lock(&gen->mut_write);
	if (!gen->stop && ind->rfork == 0 && ind->lfork == 0 \
	&& ind->last_eaten != ind->i_ind \
	&& gen->ind[(ind->i_ind + 1) % gen->total_p].last_eaten != ind->i_ind)
	{
		ind->rfork = 1;
		ind->lfork = 1;
		ind->last_eaten = ind->i_ind;
		gen->ind[(ind->i_ind + 1) % gen->total_p].last_eaten = ind->i_ind;
		ft_eat1(ind, gen);
	}
	pthread_mutex_unlock(&gen->mut_write);
}

void	ft_sleep(t_ind *ind, t_gen *gen)
{
	if (gen->total_p == 1)
	{
		ft_usleep(gen->time_die, gen);
		return ;
	}
	pthread_mutex_lock(&gen->mut_write);
	if (ind->just_ate == 1)
	{
		if (!gen->stop)
		{
			ft_write(gen, ind->i_ind, 's');
		}
	}
	pthread_mutex_unlock(&gen->mut_write);
	ft_usleep(gen->time_sleep, gen);
}

void	ft_think(t_ind *ind, t_gen *gen)
{
	if (gen->total_p == 1)
		return ;
	pthread_mutex_lock(&gen->mut_write);
	if (!gen->stop)
	{
		ft_write(gen, ind->i_ind, 't');
		ind->just_ate = 0;
	}
	pthread_mutex_unlock(&gen->mut_write);
}
