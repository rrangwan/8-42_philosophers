/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:51:59 by rrangwan          #+#    #+#             */
/*   Updated: 2022/07/19 18:20:13 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*des;

	i = 0;
	des = (char *)s;
	if (n > 0)
	{
		while (i < n)
		{
			des[i] = '\0';
			i++;
		}
		s = (void *)des;
	}
}

int	ft_ate2(t_ind *ind)
{
	pthread_mutex_unlock(&ind->gen->mut_write);
	return (0);
}

int	ft_ate(t_ind *ind)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&ind->gen->mut_write);
	if (ind->gen->min_eat == -1)
		return (ft_ate2(ind));
	while (i < ind->gen->total_p)
	{
		if (ind[i].meals_ate < ind->gen->min_eat)
			return (ft_ate2(ind));
		i++;
	}
	ind->gen->stop = 1;
	pthread_mutex_unlock(&ind->gen->mut_write);
	usleep(50);
	return (1);
}

int	ft_died(t_ind *ind)
{
	int	test;

	pthread_mutex_lock(&ind->gen->mut_write);
	test = ind->gen->stop;
	pthread_mutex_unlock(&ind->gen->mut_write);
	if (test == 0)
		return (0);
	return (1);
}
