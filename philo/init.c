/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 03:02:16 by rrangwan          #+#    #+#             */
/*   Updated: 2022/07/19 23:41:25 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	err(t_gen *phil_gen)
{
	if (phil_gen->mut_forks)
		free (phil_gen->mut_forks);
	if (phil_gen->ind)
		free (phil_gen->ind);
	return (1);
}

int	init(t_gen *phil_gen)
{
	int				i;
	int				n;

	i = 0;
	n = phil_gen->total_p;
	phil_gen->mut_forks = ft_calloc(phil_gen->total_p, sizeof(pthread_mutex_t));
	phil_gen->ind = ft_calloc(phil_gen->total_p, sizeof(t_ind));
	if (!phil_gen->mut_forks || !phil_gen->ind)
		return (err(phil_gen));
	while (i < n)
	{
		if (pthread_mutex_init(&(phil_gen->mut_forks[i]), NULL))
			return (err(phil_gen));
		i++;
	}
	if (pthread_mutex_init(&(phil_gen->mut_write), NULL))
		return (err(phil_gen));
	return (init2(phil_gen));
}

int	init2(t_gen *phil_gen)
{
	int		i;
	int		n;
	t_ind	*ind;

	i = 0;
	n = phil_gen->total_p;
	while (i < n)
	{
		ind = &phil_gen->ind[i];
		ind->last_eaten = 300;
		ind->just_ate = 0;
		ind->gen = phil_gen;
		ind->i_ind = i;
		ind->time_ate = 0;
		ind->meals_ate = 0;
		ind->lfork = 0;
		ind->rfork = 0;
		i++;
	}
	return (0);
}
