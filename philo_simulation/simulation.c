/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:26:42 by souchane          #+#    #+#             */
/*   Updated: 2024/08/20 14:53:04 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int simulation(t_philo *philo)
{
    if(create_philo_threads(philo))
	return (ERROR);
    monitor(philo, philo->philos);
	join_thread(philo, philo->philos);
	destroy_thread(philo);
    return SUCCESS;
}
