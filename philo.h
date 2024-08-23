/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:53:11 by souchane          #+#    #+#             */
/*   Updated: 2024/08/23 17:38:09 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#define ERROR 1
#define SUCCESS 0
#define N_PHILO 250
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>
struct s_philo;

typedef struct s_phs_infos
{
    int ids;
    int id_l_fork;
    int id_r_fork;
    int  eat_count;
    long long  last_meal_check;
    struct s_philo *philo;
    pthread_t id_of_thread;
} t_phs_infos;

typedef struct s_philo
{
    int philo_number;
    int die_time;
    int eat_time;
    int sleep_time;
    int meals_number;
    int gone;
    int all_done_eating;
    long long  start_time;
    pthread_mutex_t check_meal_lock;  
    pthread_mutex_t n_forks[N_PHILO];
    pthread_mutex_t action_lock;
    t_phs_infos philos[N_PHILO];
} t_philo;

// init args, locks, phs
int initialize(t_philo *philo, char **args);
int check_args(t_philo *philo, char **args);
int initialize_locks(t_philo *philo);
int initialize_phs(t_philo *philo);
//about time
time_t	get_time(void);
void  check_time(time_t time, t_philo *philo);
// routine
int simulation(t_philo *philo);
int create_philo_threads(t_philo *philo);
void monitor(t_philo *philo, t_phs_infos *infos);
void join_thread(t_philo *philo, t_phs_infos *infos);
void destroy_thread(t_philo *philo);
// moves
void printing(t_philo *philo, int id, char *move);
void eating_action(t_phs_infos *infos);
//utils
int			ft_atoi(const char *str);
void ft_putstr_fd(char *s, int fd);
#endif
