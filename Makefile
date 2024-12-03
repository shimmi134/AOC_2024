# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shimi-be <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 11:53:14 by shimi-be          #+#    #+#              #
#    Updated: 2024/12/01 18:11:30 by shimi-be         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = aoc.a
RM = rm
RMFLAGAS= -rf
L = $(wildcard libft_src/*.h)
G = $(wildcard gnl_src/*.h)
P = $(wildcard printf_src/*.h)
LIB = ar rcs
SRC = $(wildcard gnl_src/*.c) $(wildcard libft_src/*.c) $(wildcard printf_src/*.c)

CC = cc

CFLAGAS =  -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) $(L) $(G) $(P) $(wildcard ./ex0*.c)
	@$(LIB) $(NAME) $(OBJ)
	@echo "Library created"
	@$(CC) $(CFLAGAS) $(wildcard ./ex0*.c) aoc.a -g
	@echo "Compiled your AOC for today."

%.o: %.c $(L) $(G) $(P) Makefile
	$(CC) $(CFLAGAS) -c $< -o $@

clean:
	@$(RM) $(RMFLAGAS) $(OBJ) $(OBJ_BONUS)
	@echo "Cleaned!"

fclean: clean
	@$(RM) $(RMFLAGAS) $(NAME)
	@echo "Cleaned!"

re: fclean all

.PHONY : all clean fclean re bonus
