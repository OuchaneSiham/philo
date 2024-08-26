/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:08:58 by souchane          #+#    #+#             */
/*   Updated: 2024/08/26 14:06:04 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	get_time(void)
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
// void  check_time(time_t time, t_philo *philo)
// {
//     time_t time0;
//     time_t timex;
//     time0 = get_time();
//     while(!(philo->gone))
//     {
//         timex = get_time();
//         if((timex - time0) >= time)
//             break;
//         usleep(50);
//     }
// }
int	ft_delay(long long milliseconds)
{
	long	now;

	now = get_time();
	while (get_time() < milliseconds + now)
		usleep(400);
	return (0);
}
