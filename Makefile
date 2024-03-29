# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/29 19:25:41 by emoreau           #+#    #+#              #
#    Updated: 2023/06/30 15:14:18 by emoreau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		= ./srcs/
OBJ_DIR	= ./obj/
SRCS	=	push_swap.c\
			move.c\
			move2.c\
			algo.c\
			init.c\
			verif.c\
			parsing.c\
			utils.c\
			calculateur.c\
			algo_utils.c

OBJS = $(patsubst %.c,$(OBJ_DIR)%.o,$(SRCS))

NAME	=	push_swap
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g3
RM		=	rm -rf

all:	${NAME}

$(NAME):	$(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	${RM} $(OBJ_DIR)
	$(MAKE) -C libft clean

fclean:	clean
		${RM} ${NAME}
		$(MAKE) -C libft fclean

re:		fclean all

.PHONY: 	all clean fclean re