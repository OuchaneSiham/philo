/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 14:30:07 by souchane          #+#    #+#             */
/*   Updated: 2024/08/20 13:12:34 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../philo.h"

time_t	get_time(void)
{
	struct timeval		tv;
    long long  time;
	if(gettimeofday(&tv, NULL))
    {
        ft_putstr_fd("erroe: get_time of days error\n", 2);
        return (-1);
    }
    time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}
void  check_time(time_t time, t_philo *philo)
{
    time_t time0;
    time_t timex;
    time0 = get_time();
    while(!(philo->gone))
    {
        timex = get_time();
        if((timex - time0) >= time)
            break;
        usleep(50);
    }
}
