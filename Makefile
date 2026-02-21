# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 15:09:23 by htoe              #+#    #+#              #
#    Updated: 2026/02/21 16:28:43 by htoe             ###   ########.fr        #
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
MLX_BUILD = MLX42/build

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
	@cmake -S MLX42 -B ${MLX_BUILD}
	@make -s -C ${MLX_BUILD}

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
	@if [ -d ${MLX_BUILD} ]; then \
		cmake --build ${MLX_BUILD} --target clean; \
	fi
#@make clean -s -C libft

fclean: clean
	@${RM} ${NAME}
	@${RM} ${MLX_BUILD}
#@make fclean -s -C libft

re: fclean all

.PHONY: all clean fclean re
