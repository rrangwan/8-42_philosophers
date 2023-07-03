/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrangwan <rrangwan@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:08:37 by rrangwan          #+#    #+#             */
/*   Updated: 2022/07/19 23:39:50 by rrangwan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_INT 2147483647

struct	s_gen;

typedef struct s_ind
{
	int					i_ind;
	int					last_eaten;
	int					just_ate;
	int					meals_ate;
	long long			time_ate;
	pthread_t			th_id;
	int					lfork;
	int					rfork;
	struct s_gen		*gen;
}					t_ind;

typedef struct s_gen
{
	int				total_p;
	int				last_eaten;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				min_eat;
	long long		time_start;
	int				stop;
	int				n_eaten;
	pthread_mutex_t	mut_write;
	pthread_mutex_t	*mut_forks;
	t_ind			*ind;
}					t_gen;

int				parser(int argc, char **argv);
int				parser2(int argc, char **argv, t_gen *phil_gen);
int				parser0(int argc, char **argv, t_gen *phil_gen);
int				init(t_gen *phil_gen);
int				init2(t_gen *phil_gen);
int				err(t_gen *phil_gen);
int				ft_philo(t_gen *phil_gen);
void			*ft_philo2(void *ind);
void			ft_stop(t_gen *phil_gen);
int				ft_stop1(t_gen *phil_gen, int i);
int				ft_stop2(t_gen *phil_gen);
void			ft_destroy(t_gen *phil_gen);
void			ft_eat(t_ind *ind, t_gen *gen);
void			ft_eat1(t_ind *ind, t_gen *gen);
void			ft_eat2(t_ind *ind, t_gen *gen);
void			ft_sleep(t_ind *ind, t_gen *gen);
void			ft_think(t_ind *ind, t_gen *gen);
void			ft_die(t_gen *phil_gen, int i);
//utils
void			ft_write(t_gen *gen, int i, char c);
int				ft_is_int(char *str);
int				ft_atoi(char *str);
long long		ft_time(void);
void			ft_usleep(unsigned int time_end, t_gen *phil_gen);
int				ft_error(char *str);
void			*ft_calloc(size_t count, size_t size);
void			ft_bzero(void *s, size_t n);
int				ft_ate(t_ind *ind);
int				ft_ate2(t_ind *ind);
int				ft_died(t_ind *ind);
#endif
