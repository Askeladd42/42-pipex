# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plam <plam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 09:31:35 by plam              #+#    #+#              #
#    Updated: 2022/01/28 00:03:39 by plam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		+=	utils/ft_split.c\
				utils/ft_strlen.c\
				utils/ft_strlcpy.c\
				utils/ft_strjoin.c\
				utils/ft_strnstr.c\
				utils/ft_putstr_fd.c

SRCS		+=	parsing/open_close.c\
				parsing/child_proc.c\
				parsing/parent_proc.c\
				parsing/path_parsing.c

SRCS		+=	init/init_ppx.c

SRCS		+=	free/free_ppx.c

SRCS		+=	cmd_funcs/cmd_exec.c\

SRCS		+=	errors.c\
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

%.o: %.c	
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean all

.PHONY:			all clean fclean re bonus