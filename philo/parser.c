/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:21:56 by rrangwan          #+#    #+#             */
/*   Updated: 2022/07/19 20:06:26 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parser(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i] || !ft_is_int(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	parser2(int argc, char **argv, t_gen *phil_gen)
{
	phil_gen->total_p = ft_atoi(argv[1]);
	phil_gen->last_eaten = ft_atoi(argv[1]);
	phil_gen->time_die = ft_atoi(argv[2]);
	phil_gen->time_eat = ft_atoi(argv[3]);
	phil_gen->time_sleep = ft_atoi(argv[4]);
	phil_gen->stop = 0;
	phil_gen->n_eaten = 0;
	phil_gen->min_eat = -1;
	if (argc == 6)
		phil_gen->min_eat = ft_atoi(argv[5]);
	if (phil_gen->total_p < 1 || phil_gen->total_p > 200 \
	|| phil_gen->time_die < 60 \
	|| phil_gen->time_eat < 60 || phil_gen->time_sleep < 60 \
	|| (phil_gen->min_eat < 0 && argc == 6))
		return (1);
	return (0);
}

int	parser0(int argc, char **argv, t_gen *phil_gen)
{
	if (parser(argc, argv))
		return (1);
	if (parser2(argc, argv, phil_gen))
		return (1);
	return (0);
}
