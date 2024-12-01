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

NAME = lib.a
L = $(wildcard libft_src/*.h)
G = $(wildcard gnl_src/*.h)
P = $(wildcard printf_src/*.h)
LIB = ar rcs
SRC = $(wildcard gnl_src/*.c) $(wildcard libft_src/*.c) $(wildcard printf_src/*.c)

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) $(L) $(G) $(P)
	$(LIB) $(NAME) $(OBJ)

bonus : $(OBJ) $(OBJ_BONUS) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ) $(OBJ_BONUS)

%.o: %.c $(L) $(G) $(P) Makefile
	cc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
