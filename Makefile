# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchane <souchane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/16 14:42:36 by souchane          #+#    #+#              #
#    Updated: 2024/08/23 17:21:14 by souchane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
CC = cc
RM = rm -rf

PARSING = parsing/check_args.c parsing/initialize.c parsing/mutex_init.c parsing/philos_init.c parsing/utils.c
PHILO_SIMULATION = philo_simulation/about_time.c philo_simulation/join_thread.c philo_simulation/monitor_simu.c \
					philo_simulation/philos_moves.c philo_simulation/simulation.c philo_simulation/thread_routine.c
FILES = $(PARSING) $(PHILO_SIMULATION) main.c
OBJS = $(FILES:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
