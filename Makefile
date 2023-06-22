# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:03:40 by eduarodr          #+#    #+#              #
#    Updated: 2023/06/21 17:31:40 by eduarodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = pipex.c\
		arguments.c\
		utils.c\
		utils2.c\

OBJ = ${SRC:.c=.o}

NAME = pipex

CC = cc

RM = rm -f

CFLAGS = -Werror -Wextra -Werror

all: ${NAME}

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
