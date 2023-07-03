/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:13:58 by rrangwan          #+#    #+#             */
/*   Updated: 2022/06/29 21:47:53 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_gen	phil_gen;

	if (!(argc < 5 || argc > 6))
	{
		if (parser0(argc, argv, &phil_gen))
			return (ft_error("Wrong paramters"));
		if (init(&phil_gen))
			return (ft_error("Malloc or Mutex failded"));
		if (ft_philo(&phil_gen))
			return (ft_error("Threading failded"));
	}
	else
		return (ft_error("Wrong number of arguments"));
	return (0);
}

int	ft_error(char *str)
{
	printf("\nError: %s.\n", str);
	return (1);
}
