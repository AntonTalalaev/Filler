# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwunsch <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 13:27:57 by mwunsch           #+#    #+#              #
#    Updated: 2019/02/15 18:23:33 by mwunsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mwunsch.filler

SRC = ./fdir/filler.c \
		./fdir/filler_tool_one.c \
		./fdir/filler_tool_two.c \
		./fdir/filler_tool_three.c \
		./fdir/filler_tool_four.c \
		./fdir/filler_tool_five.c \
		./fdir/filler_tool_six.c

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ)
	@echo "\x1b[32mFiller: \x1b[0mCompiling the project.."
	@make --directory ./libft
	@gcc -o $(NAME) -Wextra -Wall -Werror $(OBJ) -L./libft -lft
	@echo "\x1b[32mFiller: \x1b[0mCompilation of the project completed"

$(OBJ): %.o: %.c
	@gcc -Wall -Werror -Wextra -c $< -o $@

clean:
	@echo "\x1b[32mFiller: \x1b[0mDeleting binaries"
	@rm -f $(OBJ)
	@make clean --directory ./libft

fclean:
	@echo "\x1b[32mFiller: \x1b[0mDeleting binaries"
	@rm -f $(OBJ)
	@echo "\x1b[32mFiller: \x1b[0mDeleting program"
	@rm -f $(NAME)
	@make fclean --directory ./libft

re: fclean all
