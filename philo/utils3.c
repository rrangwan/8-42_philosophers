/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:51:59 by rrangwan          #+#    #+#             */
/*   Updated: 2022/07/19 18:31:00 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_die(t_gen *phil_gen, int i)
{
	pthread_mutex_lock(&phil_gen->mut_write);
	printf("%lli %d died\n", \
		ft_time() - phil_gen->time_start, i + 1);
	phil_gen->stop = 1;
	usleep(100);
	pthread_mutex_unlock(&phil_gen->mut_write);
}

void	ft_write(t_gen *gen, int i, char c)
{
	char	*str;

	if (c == 's')
		str = "is sleeping";
	else if (c == 't')
		str = "is thinking";
	else if (c == 'f')
		str = "picked up fork";
	else if (c == 'e')
		str = "is eating";
	else if (c == 'd')
		str = "died";
	else
		str = NULL;
	printf("%lli %d %s\n", \
		ft_time() - gen->time_start, i + 1, str);
}

void	ft_destroy(t_gen *phil_gen)
{
	int		i;
	int		n;

	i = 0;
	n = phil_gen->total_p;
	while (i < n)
	{
		pthread_join(phil_gen->ind[i].th_id, NULL);
		i++;
	}
	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(&phil_gen->mut_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&phil_gen->mut_write);
	err(phil_gen);
}
