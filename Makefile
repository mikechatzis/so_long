# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/05 14:49:43 by mchatzip          #+#    #+#              #
#    Updated: 2021/10/15 12:20:55 by mchatzip         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME       = so_long

LIBFT_PATH = libft/

MLX_PATH_MAC   = mlx/

MLX_PATH_LINUX   = mlxl/

LIBFT_LIB  = libft.a

SRC_FILES = so_long.c hooks.c draw.c errors.c gnl.c draw2.c drawmap.c collision.c collect.c exit.c done.c
			 
SRC_OBJS  = so_long.o hooks.o draw.o errors.o gnl.o draw2.o drawmap.o collision.o collect.o exit.o done.o

CC         = gcc

CFLAGS     = -Wall -Wextra -Werror

RM         = rm -f

AR         = ar crs

LIBFT_OBJS   = ${LIBFT_PATH}*.o

LIBFTMAKE    = $(MAKE) -C ${LIBFT_PATH}

MLXMAKEMAC      = ${MAKE} -C ${MLX_PATH_MAC}

MLXMAKELINUX      = ${MAKE} -C ${MLX_PATH_LINUX}

uname := $(shell uname)

%.o: %.c
	$(CC) -g $(CFLAGS) -c $^ -o $@

all:		mlxmake lftmake ${NAME}

ifeq ($(uname),Linux)

${NAME}:    ${SRC_OBJS}
			${CC} -g ${CFLAGS} -o ${NAME} ${SRC_OBJS} -L libft/ -lft -L mlxl/ -lmlx -lXext -lX11 -lm
mlxmake:	
			${MLXMAKELINUX}

clean:
			make -C ${LIBFT_PATH} clean
			make -C ${MLX_PATH_LINUX} clean 
			${RM} ${SRC_OBJS}
endif
ifeq ($(uname),Darwin)	

$(NAME):	${SRC_OBJS}
			${CC} -framework OpenGL -framework AppKit -g ${CFLAGS} -lm -o ${NAME} ${SRC_OBJS} mlx/libmlx.a -L libft/ -lft
mlxmake:	
			${MLXMAKEMAC}

clean:
			make -C ${LIBFT_PATH} clean
			make -C ${MLX_PATH_MAC} clean 
			${RM} ${SRC_OBJS}
endif
			
lftmake:
			${LIBFTMAKE}

fclean: 	clean
			${RM} ${NAME}

re:         fclean all

.PHONY:     all clean fclean re