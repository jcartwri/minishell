# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcartwri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/01 09:43:45 by jcartwri          #+#    #+#              #
#    Updated: 2019/06/01 12:13:55 by jcartwri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = vector/vector_add.c vector/vector_deinit.c vector/vector_del_value.c vector/vector_del.c vector/vector_get.c vector/vector_init.c vector/vector_resize.c vector/vector_search.c vector/vector_set.c

ENV = Environment/env_deinit.c Environment/env_get.c Environment/env_init.c Environment/env_print.c Environment/env_set.c Environment/env_unset.c Environment/env_update.c

MINI = d_minishell/commands.c d_minishell/env_commands.c d_minishell/ft_split.c d_minishell/read_line.c d_minishell/src.c

#OBJ = vector_add.c vector_deinit.c vector_del_value.c vector_del.c vector_get.c vector_init.c vector_resize.c vector_search.c vector_set.c env_deinit.c env_get.c env_init.c env_print.c env_set.c env_unset.c env_update.c commands.c env_commands.c ft_split.c read_line.c src.o

#SRC = vector/*.c Environment/*.c d_minishell/*.c

OBJ = *.o

FLAGS = -Wall -Werror -Wextra

LIBRF = ./ft_printf/libftprintf.a

LIBRL = ./ft_printf/libft/libft.a

all: $(NAME)

$(NAME):
	make re -C ft_printf
	gcc -c $(SRC) $(ENV) $(MINI) main.c
	gcc $(LIBRF) $(LIBRL) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	make clean -C ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C ft_printf
	@rm -f $(NAME)

re: fclean all
