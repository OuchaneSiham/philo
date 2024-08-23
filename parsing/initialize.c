/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:11:01 by souchane          #+#    #+#             */
/*   Updated: 2024/08/23 15:36:18 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"

int initialize(t_philo *philo, char **args)
{
    int arg;
    int lock;
    int philos;
    arg = check_args(philo, args);
    if(arg != 0)
    {
        ft_putstr_fd("ERROR: invalid values of args\n", 2);
        return ERROR;
    }
    lock = initialize_locks(philo);
    if(lock != 0)
    {
        ft_putstr_fd("ERROR: the mutexs initialization failed\n", 2);
        return ERROR;
    }
    philos = initialize_phs(philo);
    if(philos != 0)
    {
        ft_putstr_fd("ERROR: the philosophers initialization failed\n", 2);
        return ERROR;
    }
    return SUCCESS;
}
