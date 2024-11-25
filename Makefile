# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 16:51:13 by yabokhar          #+#    #+#              #
#    Updated: 2024/11/25 17:05:37 by yabokhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabokhar <yabokhar@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 02:18:36 by yabokhar          #+#    #+#              #
#    Updated: 2024/11/14 10:37:38 by yabokhar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    =    ft_printf.c        \
            basic_tools.c	\
	    flags_tools.c	\
	    handle_flags.c	\
	    handle_c.c		\
	    handle_s.c		\
	    handle_d_i.c	\
	    handle_u.c		\
	    handle_x_l.c	\
	    handle_x_u.c	\
	    handle_p.c		

OBJ_DIR =   .objects/

OBJS	=	${SRCS:%.c=${OBJ_DIR}%.o}

HEAD	=	ft_printf.h

NAME	=	libftprintf.a

CC	=	cc

AR	=	ar -rc

FLAGS	=	-Wall -Wextra -Werror

all	:	${NAME}

${OBJS} :   ${OBJ_DIR}%.o : %.c ${HEAD} Makefile
	${CC} ${FLAGS} -c $< -o $@

${NAME}	:	${OBJ_DIR} ${OBJS} 
	${AR} ${NAME} ${OBJS}

${OBJ_DIR}  :
	mkdir -p ${OBJ_DIR}

clean	:
	rm -rf ${OBJ_DIR}

fclean	:	clean
	rm -f ${NAME}

re	:	fclean all

.PHONY	:	all clean fclean re
