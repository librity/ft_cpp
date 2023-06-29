# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 21:50:19 by lpaulo-m          #+#    #+#              #
#    Updated: 2023/06/28 22:47:03 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = megaphone

CC = c++
CC_STRICT = $(CC) $(CCF_STD) $(CCF_STRICT)

CCF_STRICT = -Wall -Wextra -Werror
CCF_STD =  -std=c++98

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs
COPY = cp

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

SOURCES = megaphone.cpp

################################################################################
# REQUIRED
################################################################################

all: $(NAME)

$(NAME):
	$(CC_STRICT) \
		$(SOURCES) \
		-o $(NAME)

re: fclean all

################################################################################
# CLEAN
################################################################################

clean:
	$(REMOVE) $(NAME)

fclean: clean

################################################################################
# examples
################################################################################

run: re
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME)  Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)
