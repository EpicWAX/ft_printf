# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/11 19:46:55 by qhusler           #+#    #+#              #
#    Updated: 2016/06/27 10:17:56 by qhusler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc
CFLAG	= -c -Wall -Werror -Wextra
HDR		= -I./includes
RM		= rm -f

LIBFT 	= ./libft/
LIB_O	= $(addsuffix ft_*.o, $(LIBFT))


SRC		= $(addprefix ./src/, $(FILES))
FILES	= ft_printf.c \
		  ft_convert_base.c
OBJ		= $(SRC:.c=.o)




all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@$(CC) $(CFLAG) $(SRC) $(HDR)
	mv *.o ./src
	ar rc $(NAME) $(OBJ) $(LIB_O)
	ranlib $(NAME)

clean:
	@$(RM) $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
	@make re -C $(LIBFT)

norme:
	@echo "-----NORMINETTE-----"
	norminette -RCheckForbiddenSourceHeader ./*.c
	norminette -RCheckForbiddenSourceHeader ./includes/*.h











#FILE	= (src)
#OBJ		= $(SRC:.c=.o)

#	@make -C $(LIBFT)
#	@$(CC) $(CFLAG) $(SRC_NAME)

#	@$(AR) $(NAME) $(OBJ) $(LIB_O)
#	@$(RLIB) $(NAME)
#$(NAME): $(OBJECTS) $(LIBFT)
#	    libtool -static -o $@ $^
		
