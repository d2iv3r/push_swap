# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efarhat <efarhat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 18:55:26 by efarhat           #+#    #+#              #
#    Updated: 2023/04/10 01:29:14 by efarhat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = libft.c ft_atoi_v2.c ft_split.c ft_substr.c ft_isdigit.c ft_strncmp.c get_pos.c push_swap.c check_argv.c utils_lst.c utils.c moves.c sorting.c operations.c

SRC_BNS = libft.c ft_atoi_v2.c ft_split.c ft_substr.c ft_isdigit.c check_argv.c utils_lst.c utils.c ft_strjoin_v2.c ft_strncmp.c operations.c checker.c

OBJ = $(SRC:.c=.o)

OBJ_BNS = $(SRC_BNS:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJ) push_swap.h
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o : %.c push_swap.h
	$(CC) -c $(CFLAGS) $< -o $@

$(BONUS) : $(OBJ_BNS) checker.h
	$(CC) $(CFLAGS) $(OBJ_BNS) -o $@

%.o : %.c checker.h
	$(CC) -g -c $(CFLAGS) $< -o $@

clean : 
	rm -rf $(OBJ) $(OBJ_BNS)

fclean : clean
	rm -rf $(NAME) $(BONUS)

re : fclean all bonus

.PHONY : clean all fclean re bonus
