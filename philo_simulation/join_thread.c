/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 14:20:05 by souchane          #+#    #+#             */
/*   Updated: 2024/08/23 15:36:38 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"
void join_thread(t_philo *philo, t_phs_infos *infos)
{
    int i;
    i = 0;
    while(++i < philo->philo_number)
    {
        if(pthread_join(infos[i].id_of_thread , NULL))
        { 
            ft_putstr_fd("ERROR: joining threads error", 2);
            return ;
        }
    }
}

void destroy_thread(t_philo *philo)
{
    int i;
    i = 0;
    while(++i<philo->philo_number)
    {
        pthread_mutex_destroy(&(philo->n_forks[i]));
    }
    pthread_mutex_destroy(&(philo->action_lock));
}
