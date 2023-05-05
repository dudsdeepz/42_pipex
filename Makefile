# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 13:03:40 by eduarodr          #+#    #+#              #
#    Updated: 2023/05/05 14:13:05 by eduarodr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = pipex.c\
		arguments.c\
		utils.c\

OBJ = ${SRC:.c=.o}

NAME = pipex

CC = cc

RM = rm -f

CCFLAGS = -Werror -Wextra -Werror

all: ${NAME}

$(NAME):	$(OBJ)
	$(CC) $(CCFLAGS) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
