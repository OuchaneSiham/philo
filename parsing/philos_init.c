/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 10:49:59 by souchane          #+#    #+#             */
/*   Updated: 2024/08/23 14:53:29 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static void init_single_philosopher(t_philo *philo, int index)
{
    philo->philos[index].ids = index;
    philo->philos[index].eat_count = 0;
    philo->philos[index].id_l_fork = index;
    if(index == philo->philo_number - 1)
        philo->philos[index].id_r_fork = 0;
    else 
        philo->philos[index].id_r_fork = index + 1;
        philo->philos[index].last_meal_check = 0;
        philo->philos[index].philo = philo;
}
static void  init_phs_recursive(t_philo *philo ,int index)
{
    if(index < 0)
    return ;
    init_single_philosopher(philo, index);
    init_phs_recursive(philo, index - 1);
}

int initialize_phs(t_philo *philo)
{
    init_phs_recursive(philo, philo->philo_number - 1);
    return SUCCESS;
}
