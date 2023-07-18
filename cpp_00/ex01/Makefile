# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/28 21:50:19 by lpaulo-m          #+#    #+#              #
#    Updated: 2023/07/18 18:27:51 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phone_book

CC = c++
CC_STRICT = $(CC) $(CCF_STRICT) $(CCF_STD)

CCF_STRICT = -Wall -Wextra -Werror
CCF_STD = -std=c++98

MAKE_EXTERNAL = make -C
SAFE_MAKEDIR = mkdir -p
ARCHIVE_AND_INDEX = ar -rcs
COPY = cp

REMOVE = /bin/rm -f
REMOVE_RECURSIVE = /bin/rm -rf

SOURCES = PhoneBook.cpp Contact.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

################################################################################
# REQUIRED
################################################################################

all: $(NAME)

%.o: %.cpp
	$(CC_STRICT) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC_STRICT) $(OBJECTS) -o $(NAME)

re: fclean all

################################################################################
# CLEAN
################################################################################

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

################################################################################
# EXAMPLES
################################################################################

run: re
	./$(NAME)

################################################################################
# PHONY
################################################################################

.PHONY: all re clean fclean run
