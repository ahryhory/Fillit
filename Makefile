# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by ahryhory          #+#    #+#              #
#    Updated: 2017/11/22 15:22:38 by ahryhory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

PATHLIBFT = includes/libft

LIBFT = includes/libft/libft.a

SRC =

SRC += ft_check.c
SRC += ft_check_indx.c
SRC += ft_count_blocks.c
SRC += ft_create_indexarr.c
SRC += ft_format_list.c
SRC += ft_get_tet.c
SRC += ft_get_tetriminos.c
SRC += ft_lst_add.c
SRC += ft_read_full.c
SRC += ft_size.c
SRC += ft_x.c
SRC += main.c
SRC += ft_usage.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(PATHLIBFT)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	@gcc $(FLAGS) -c $<

clean:
	@make clean -C $(PATHLIBFT)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C $(PATHLIBFT)
	@rm -rf $(NAME)

re: fclean all
