# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 15:09:23 by htoe              #+#    #+#              #
#    Updated: 2026/02/27 19:36:13 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

#Compilation & Commands
NAME		:= fractol
CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror -Wunreachable-code -Ofast
CINCLUDE	:= -Iinclude -Ilibft/include -IMLX42/include
LIBFLAGS 	:= -Llibft -lft -LMLX42/build -lmlx42 -ldl -lglfw -pthread -lm
RM 			:= rm -Rf

#Directories
SRCDIR 		:= srcs
OBJDIR 		:= objs
LIBFT		:= libft
MLX_BUILD 	:= MLX42/build

#Sources
SRCS 		:= \
			${SRCDIR}/main.c \
			${SRCDIR}/parse.c \
			${SRCDIR}/fractals/computing.c \
			${SRCDIR}/fractals/computing_utils.c \
			${SRCDIR}/fractals/mandelbrot.c \
			${SRCDIR}/fractals/julia.c \
			${SRCDIR}/fractals/burning_ship.c \
			${SRCDIR}/events/hooks.c \
			${SRCDIR}/events/events.c \
			${SRCDIR}/color/smooth_color.c \
			${SRCDIR}/color/palette.c \
			${SRCDIR}/utils/error.c \
			${SRCDIR}/utils/math_utils.c
OBJS 		:= ${SRCS:${SRCDIR}/%.c=${OBJDIR}/%.o}
LIB 		:= libft/libft.a
MLXLIB 		:= MLX42/build/libmlx42.a

#Pattern Rules

${OBJDIR}/%.o: ${SRCDIR}/%.c Makefile
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} ${CINCLUDE} -c $< -o $@

${MLXLIB}:
	@echo "COMPILING MLX"
	@if [ ! -d ${MLX_BUILD} ]; then \
		cmake -S MLX42 -B ${MLX_BUILD}; \
	fi
	@make -s -C ${MLX_BUILD} -j4

${LIB}:
	@echo "COMPILING LIBFT"
	@make -s -C ${LIBFT}

${NAME}: Makefile ${OBJS} ${LIB} ${MLXLIB}
	@echo "LINKING FRACT_OL"
	@echo "COMPILING FRACT_OL"
	@${CC} ${OBJS} ${LIBFLAGS} -o ${NAME}

all: ${NAME}

clean:
	@echo "CLEANING"
	@${RM} ${OBJDIR}
	@if [ -d ${MLX_BUILD} ]; then \
		make -s -C ${MLX_BUILD} clean; \
	fi
	@make clean -s -C ${LIBFT}

fclean: clean
	@${RM} ${NAME}
	@${RM} ${MLX_BUILD}
	@make fclean -s -C ${LIBFT}

re: fclean all

.PHONY: all clean fclean re
