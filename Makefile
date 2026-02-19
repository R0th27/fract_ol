# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 15:09:23 by htoe              #+#    #+#              #
#    Updated: 2026/02/19 19:22:05 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

#Compilation & Commands
NAME = a.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
CINCLUDE = -Iinclude -Ilibft/include -IMLX42/include
LIBFLAGS = -Llibft -lft -LMLX42/build -lmlx42 -ldl -lglfw -pthread -lm
RM = rm -Rf

#Directories
SRCDIR = srcs
OBJDIR = objs

#Sources
SRCS = ${wildcard ${SRCDIR}/*.c}
OBJS = ${SRCS:${SRCDIR}/%.c=${OBJDIR}/%.o}
LIB = libft/libft.a
MLXLIB = MLX42/build/libmlx42.a

#Pattern Rules

${OBJDIR}/%.o: ${SRCDIR}/%.c Makefile
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} ${CINCLUDE} -c $< -o $@

${MLXLIB}:
	@echo "COMPILING MLX"
	@make -s -C MLX42/build

${LIB}:
	@echo "COMPILING LIBFT"
	@make -s -C libft

${NAME}: Makefile ${OBJS} ${LIB} ${MLXLIB}
	@echo "COMPILING FRACT_OL"
	@echo "LINKING FRACT_OL"
	@${CC} ${OBJS} ${LIBFLAGS} -o ${NAME}

all: ${NAME}

clean:
	@echo "CLEANING"
	@${RM} ${OBJDIR}
	@make clean -s -C MLX42/build
#@make clean -s -C libft

fclean: clean
	@${RM} ${NAME}
#@make fclean -s -C libft

re: fclean all

.PHONY: all clean fclean re
