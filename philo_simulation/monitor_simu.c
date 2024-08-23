/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_simu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:14:57 by souchane          #+#    #+#             */
/*   Updated: 2024/08/23 17:27:15 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include"../philo.h"
static int check_if_dead(t_philo *philo, t_phs_infos *infos, int i)
{
    pthread_mutex_lock(&(philo->check_meal_lock));
    if(get_time() - infos[i].last_meal_check > philo->die_time)
    {
        printing(philo, i, "died");
        philo->gone = 1;
        pthread_mutex_unlock(&(philo->check_meal_lock));
        return ERROR;
    }
    pthread_mutex_unlock(&(philo->check_meal_lock));
    return SUCCESS;
}
static int check_all_done_eating(t_philo *philo, t_phs_infos *infos)
{
    int i;
    i = 0;
    while(philo->meals_number != -1 && i < philo->philo_number 
    && infos[i].eat_count >= philo->meals_number)
        i++;
    return (i == philo->philo_number);
}

void monitor(t_philo *philo, t_phs_infos *infos)
{
    int i;
    while(!philo->all_done_eating)
    {
        i = 0;
        while(i < philo->philo_number && !philo->gone)
        {
            if(check_if_dead(philo, infos, i))
                return;
            i++;
        }
        if(check_all_done_eating(philo, infos))
            philo-> all_done_eating = 1;
        usleep(100);
    }
}
