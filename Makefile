# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plam <plam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 09:31:35 by plam              #+#    #+#              #
#    Updated: 2022/01/25 17:21:09 by plam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		+=	utils/ft_split.c\
				utils/ft_strlen.c\
				utils/ft_strdup.c\
				utils/ft_strjoin.c\
				utils/ft_strncmp.c

SRCS		+=	parsing/open_close.c\
				parsing/child_proc.c\
				parsing/parent_proc.c\
				parsing/path_parsing.c

SRCS		+=	init/init_ppx.c

SRCS		+=	free/free_ppx.c

SRCS		+=	

SRCS		+=	cmd_funcs/cmd_exec.c\
				cmd_funcs/cmd_verification.c


SRCS		+=	errors.c\
				pipex.c\
				main.c

MAKE		=	/bin/make

PATH		=	srcs/

OBJS		= 	$(addprefix $(PATH), $(SRCS:.c=.o))

OBJS_BONUS	= 	$(addprefix $(PATH), $(SRCS_BONUS:.c=.o))

HEADERS		+=	headers/

NAME		=	pipex

NAME_BONUS	=	pipex

RM			=	/bin/rm -f

CC			=	/usr/bin/clang

CFLAGS		=	-g -Wall -Wextra -Werror -I $(HEADERS)

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME_BONUS):	$(OBJS_BONUS)
				$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAME_BONUS)
%.o: %.c	
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re bonus