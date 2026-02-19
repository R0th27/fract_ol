# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htoe <htoe@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 15:09:23 by htoe              #+#    #+#              #
#    Updated: 2026/02/19 16:20:50 by htoe             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL := all

#Compilation & Commands
NAME = a.out
CC = cc
CFLAGS = -Wall -Wextra -Werror
CINCLUDE = -Iinclude -Ilibft/include
LIBFLAGS = -Llibft -lft
RM = rm -Rf

#Directories
SRCDIR = srcs
OBJDIR = objs

#Sources
SRCS = ${wildcard ${SRCDIR}/*.c}
OBJS = ${SRCS:${SRCDIR}/%.c=${OBJDIR}/%.o}
LIBS = libft/libft.a

#Pattern Rules

${OBJDIR}/%.o: ${SRCDIR}/%.c Makefile
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} ${CINCLUDE} -c $< -o $@

${LIBS}:
	@echo "COMPILING LIBFT"
	@make -s -C libft

${NAME}: Makefile ${OBJS} ${LIBS}
	@echo "COMPILING FRACT_OL"
	@echo "LINKING FRACT_OL"
	@${CC} ${OBJS} ${LIBFLAGS} -o ${NAME}

all: ${NAME}

clean:
	@echo "CLEANING"
	@${RM} ${OBJDIR}
#@make clean -s -C libft

fclean: clean
	@${RM} ${NAME1}
	@${RM} ${NAME2}
#@make fclean -s -C libft

re: fclean all

.PHONY: all clean fclean re
