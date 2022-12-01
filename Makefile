# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfumiya <kfumiya@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 00:18:10 by kfumiya           #+#    #+#              #
#    Updated: 2021/11/08 03:36:07 by kfumiya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= main.c ph_init_pram.c message.c util.c ph_mutex.c \
			ph_loop.c ph_observer.c ph_solo.c ph_act.c
			


NAME		= philo
INCLUDES	= includes
SRCS_DIR	= srcs
OBJS_DIR	= objs

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
HEADER		= -I includes

OBJ =		$(SRC:.c=.o)
OBJS =		$(addprefix $(OBJS_DIR)/, $(OBJ))

.PHONY :	all clean fclean re

all :		$(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(HEADER) -c -o $@ $<

$(NAME) :	$(OBJS)
	$(CC) $(CFLAGS) $(HEADER) $(OBJS) -o $@

clean :
	@/bin/rm -rf $(OBJS_DIR)
	@echo "[philo - clean]"

fclean :
	@/bin/rm -rf $(OBJS_DIR)
	@/bin/rm -rf philo.dSYM
	@/bin/rm -f philo
	@echo "[philo - fclean]"

re : fclean all
