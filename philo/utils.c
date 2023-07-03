/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:51:59 by rrangwan          #+#    #+#             */
/*   Updated: 2022/07/05 12:22:49 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_int(char *str)
{
	int			i;
	long long	ret;

	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	if (ret > MAX_INT)
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	unsigned int	i;
	unsigned int	ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		ret = (ret * 10) + (str[i] - '0');
		i++;
	}
	return ((int) ret);
}

long long	ft_time(void)
{
	struct timeval	t_val;
	long long		ret;

	gettimeofday(&t_val, NULL);
	ret = t_val.tv_sec * 1000 + (t_val.tv_usec / 1000);
	return (ret);
}

void	ft_usleep(unsigned int time_end, t_gen *phil_gen)
{
	long long	time_start;

	time_start = ft_time();
	while (1)
	{
		pthread_mutex_lock(&(phil_gen->mut_write));
		if (phil_gen->stop || ((ft_time() - time_start) >= time_end))
		{
			pthread_mutex_unlock(&(phil_gen->mut_write));
			break ;
		}
		pthread_mutex_unlock(&(phil_gen->mut_write));
		usleep(50);
	}
}
