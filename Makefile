# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmateo-m <mmateo-m@student.42madrid.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/27 18:58:24 by mmateo-m          #+#    #+#              #
#    Updated: 2023/04/04 08:28:05 by mmateo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		gcc
RM			=		rm -fr
AR			= 		ar
CFLAGS		=		-Wall -Wextra -Werror

NAME		=		libftprintf.a
LIBFT		= 		libft

SRCS = 				
 
SRCS_DEBUG	=		./src/test.c

OBJS		=		$(SRCS:.c=.o)
OBJS_DEBUG	=		$(SRCS_DEBUG:.c=.o)


all:		$(NAME)

$(NAME): 	$(OBJS)
				make -C $(LIBFT)
				cp $(LIBFT)/libft.a .
				mv libft.a $(NAME)
				$(AR) rcs $(NAME) $(OBJS) 
				
clean:		
			make clean -C $(LIBFT)
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

debug:		
			gcc -g -Wall -Wextra -Werror ./libft/*.c ./push_swap.c $(SRCS) -o push_swap


