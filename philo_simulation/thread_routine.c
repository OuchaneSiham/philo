/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:53:18 by souchane          #+#    #+#             */
/*   Updated: 2024/08/23 17:37:29 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int is_even(int n) 
{
    while (n > 0) 
    {
        n -= 2;
    }
    return n == 0;
}

void  thread_routine(t_phs_infos *infos)
{
    t_philo *philos ;
    philos = infos->philo;
    if(!is_even(infos->ids))
        usleep(10000 * (infos->ids + 1));
    while(!(philos->gone))
    {
        eating_action(infos);
        if(philos->all_done_eating)
            break;
        if(!philos->all_done_eating)
            printing(philos, infos->ids, "is sleeping");
        check_time(philos->sleep_time, philos);
        if(!philos->all_done_eating)
            printing(philos, infos->ids, "is thinking");
    }
}

void    *start_routine_func(void *sole_arg)
{
    t_phs_infos *phs;
    phs = (t_phs_infos *)sole_arg;
    thread_routine(phs);
    return NULL;
}

int create_philo_threads(t_philo *philo)
{
    int i;
    int result;
    t_phs_infos *thread;
    
    i = 0;
    thread = philo->philos;
    philo->start_time = get_time();
    while( i < philo->philo_number)
    {
        result = pthread_create(&(thread[i].id_of_thread), NULL, start_routine_func, &(thread[i]));
        if(result != 0)
        {
            ft_putstr_fd("ERROR: creating threads failed\n", 2);
            return ERROR;
        }
        thread[i].last_meal_check = get_time();
        i++;
    }
    return SUCCESS;
}
