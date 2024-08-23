/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:28:17 by souchane          #+#    #+#             */
/*   Updated: 2024/08/23 16:47:33 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(t_philo *philo, char **argv)
{
	philo->philo_number = ft_atoi(argv[1]);
	philo->die_time = ft_atoi(argv[2]);
	philo->eat_time = ft_atoi(argv[3]);
	philo->sleep_time = ft_atoi(argv[4]);
	philo->all_done_eating = 0;
	philo->gone = 0;
	if (philo->philo_number < 1 || philo->die_time < 0 || philo->eat_time < 0
		|| philo->sleep_time < 0 || philo->philo_number > 250)
		return (ERROR);
	if (argv[5])
	{
		philo->meals_number = ft_atoi(argv[5]);
		if (philo->meals_number <= 0)
			return (ERROR);
	}
	else
		philo->meals_number = -1;
	return (SUCCESS);
}
