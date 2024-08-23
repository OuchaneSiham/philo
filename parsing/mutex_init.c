/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:10:13 by souchane          #+#    #+#             */
/*   Updated: 2024/08/20 14:12:39 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"

static int initialize_single_mutex(pthread_mutex_t *mutex)
{
    if(pthread_mutex_init(mutex, NULL) != 0)
        return ERROR;
   return SUCCESS;
}
static int initialize_all_forks(t_philo *philos)
{
    int nbr;
    nbr = philos->philo_number;
    while(--nbr >= 0)
    {
        if(initialize_single_mutex((&philos->n_forks[nbr])) != 0)
            return ERROR;
    }
   return SUCCESS;
}
int initialize_locks(t_philo *philo)
{
    if(initialize_all_forks(philo) != 0)
        return ERROR;
    if(initialize_single_mutex(&(philo->action_lock)) != 0)
        return ERROR;
    if(initialize_single_mutex(&(philo->check_meal_lock)) != 0)
        return ERROR;
   return SUCCESS;
}
