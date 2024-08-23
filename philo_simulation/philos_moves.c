/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:25:15 by souchane          #+#    #+#             */
/*   Updated: 2024/08/23 17:36:54 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"

void	printing(t_philo *philo, int id, char *move)
{
	if (!(philo->gone))
	{
	    pthread_mutex_lock(&(philo->action_lock));
		printf("%lli %i %s\n", get_time() - philo->start_time, id +1 , move);
	    pthread_mutex_unlock(&(philo->action_lock));
	}
	return ;
}

void lock_forks(t_philo *philo, t_phs_infos *infos)
{
    pthread_mutex_lock(&(philo->n_forks[infos->id_l_fork]));
    if(!philo->all_done_eating)
        printing(philo, infos->ids, "has taken a fork");
    pthread_mutex_lock(&(philo->n_forks[infos->id_r_fork]));
    if(!philo->all_done_eating)
        printing(philo, infos->ids, "has taken a fork");
}
void unlock_forks( t_philo *philo,t_phs_infos *infos)
{
    pthread_mutex_unlock(&(philo->n_forks[infos->id_l_fork]));
    pthread_mutex_unlock(&(philo->n_forks[infos->id_r_fork]));
}
void eating_action(t_phs_infos *infos)
{
    t_philo *philo;
    philo = infos->philo;
    lock_forks(philo, infos);
    pthread_mutex_lock(&(philo->check_meal_lock));
    if(!philo->all_done_eating)
        printing(philo, infos->ids, "is eating");
    infos->last_meal_check = get_time();
    pthread_mutex_unlock(&(philo->check_meal_lock));
    check_time(philo->eat_time, philo);
    (infos->eat_count)++;
    unlock_forks(philo, infos);
}
