# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ego <ego@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/21 21:47:23 by ego               #+#    #+#              #
#    Updated: 2024/10/25 16:24:36 by ego              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	get_next_line.c			\
			get_next_line_utils.c
OBJS	=	$(SRCS:.c=.o)
IDIR	=	.

NAME	=	test

CC		=	cc
CFLAGS	=	-Wall -Wextra -Warning
RM		=	rm -f
BSIZE	=	42

all		:	$(NAME)

$(NAME)	:	header
			echo "Compiling get_next_line..."
			$(CC) $(CLFAGS) -D BUFFER_SIZE=$(BSIZE) main.c $(SRCS) -I $(IDIR) -o $(NAME)
			echo "$(GREEN)[OK] get_next_line is ready!$(RESET)"

norm	:
			norminette -R CheckForbiddenSourceHeader $(SRCS) get_next_line.h

clean   :
			echo "Removing object files..."
			$(RM) $(OBJS)
			echo "$(ORANGE)[OK] All object files have been removed.$(RESET)"

fclean  :   clean
			echo "Removing binary files..."
			$(RM) $(NAME)
			echo "$(ORANGE)[OK] All binary files have been removed.$(RESET)"

re		:	fclean all

.PHONY	:	all clean fclean re
.SILENT	:	all $(NAME) $(OBJS) norm debug clean fclean re header test bonus

RED		= \033[31m
ORANGE	= \033[38;5;214m
YELLOW	= \033[33m
GREEN	= \033[32m
BLUE	= \033[34m
VIOLET	= \033[38;5;93m
ITALIC	= \033[3m
RESET	= \033[0m

header	:
			echo "========================================================="
			echo "$(RED)             _                     _     _ _            $(RESET)"
			echo "$(RED)            | |                   | |   | (_)           $(RESET)"
			echo "$(ORANGE)   __ _  ___| |_   _ __   _____  _| |_  | |_ _ __   ___ $(RESET)"
			echo "$(YELLOW)  / _  |/ _ \ __| | '_ \ / _ \ \/ / __| | | | '_ \ / _ \ $(RESET)"
			echo "$(GREEN) | (_| |  __/ |_  | | | |  __/>  <| |_  | | | | | |  __/$(RESET)"
			echo "$(GREEN)  \__, |\___|\__| |_| |_|\___/_/\_\\___| |_|_|_| |_|\___|$(RESET)"
			echo "$(BLUE)   __/ |      ______                ______              $(RESET)"
			echo "$(BLUE)  |___/      |______|              |______|             $(RESET)"
			echo "$(ITALIC)$(VIOLET)                         by Ego\n$(RESET)"
			echo "========================================================="