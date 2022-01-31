# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plam <plam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 09:31:35 by plam              #+#    #+#              #
#    Updated: 2022/01/31 16:03:24 by plam             ###   ########.fr        #
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

SRCS_BONUS	+=	utils/ft_split.c\
				utils/ft_strlen.c\
				utils/ft_strlcpy.c\
				utils/ft_strjoin.c\
				utils/ft_strnstr.c\
				utils/ft_putstr_fd.c

SRCS_BONUS	+=	parsing/open_close_bonus.c\
				parsing/child_proc_bonus.c\
				parsing/parent_proc_bonus.c\
				parsing/path_parsing_bonus.c

SRCS_BONUS	+=	init/init_ppx_bonus.c

SRCS_BONUS	+=	free/free_ppx_bonus.c

SRCS_BONUS	+=	cmd_funcs/cmd_exec_bonus.c

SRCS_BONUS	+=	errors_bonus.c\
				main_bonus.c

MAKE		=	/bin/make

PATH		=	srcs/

PATH_BONUS	=	bonus/srcs/

OBJS		= 	$(addprefix $(PATH), $(SRCS:.c=.o))

OBJS_BONUS	= 	$(addprefix $(PATH_BONUS), $(SRCS_BONUS:.c=.o))

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
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus