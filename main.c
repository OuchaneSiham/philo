/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 14:51:22 by souchane          #+#    #+#             */
/*   Updated: 2024/08/23 16:52:40 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void f()
// {
//     system(" leaks philo");
// }
int main(int ac, char **av)
{
    // atexit(f);
    t_philo ph;
    int result;
    if(ac != 5 && ac != 6)
    {
        ft_putstr_fd("Error: Invalid arguments\n", 2);
        return ERROR;
    }
    result = initialize(&ph, av);
    if(result != 0)
        return ERROR;
    if (simulation(&ph))
		return (ERROR);
    return SUCCESS;
}
