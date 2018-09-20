# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschempe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 10:01:18 by mschempe          #+#    #+#              #
#    Updated: 2018/09/05 15:34:40 by mschempe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= filler

CFLAGS	= -Wall -Werror -Wextra

FILES	= ft_algo\
		  ft_valid\
		  ft_free\
		  ft_get_array\
		  main\

CFILES = $(FILES:%=srcs/%.c)

OFILES = $(FILES:%=./%.o)

all: $(NAME)

$(NAME): $(OFILES)
	$(MAKE) -C ./libft/
	gcc -o $(NAME) $(OFILES) ./libft/libft.a

$(OFILES): $(CFILES)
	gcc -c $(FLAGS) $(CFILES) -I ./inc/

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
