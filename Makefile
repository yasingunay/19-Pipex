# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygunay <ygunay@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 13:20:58 by ygunay            #+#    #+#              #
#    Updated: 2022/09/22 16:11:23 by ygunay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADER_SRCS = pipex.h 
HEADER_DIR = ./
HEADER = $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS = pipex.c childs.c error_check.c ft_strncmp.c ft_split.c ft_strjoin.c ft_strlen.c
MPATH_DIR = ./
MPATH = $(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M = $(MPATH:.c=.o)


%.o: %.c $(HEADER) Makefile
		@${CC} ${FLAGS} -c $< -o $@

$(NAME): $(OBJ_M) $(OBJ_L) $(OBJ_GNL)
		@$(CC) $(OBJ_M) $(OBJ_L) $(OBJ_GNL) -o $(NAME)
		@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

all:	$(NAME)

clean:
		@$(RM) $(OBJ_M)
		@$(RM) $(OBJ_L)
		@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:	clean
		@$(RM) $(NAME)
		@echo "$(RED)all deleted!$(DEFAULT)"

re:	fclean all

.PHONY:	all clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
