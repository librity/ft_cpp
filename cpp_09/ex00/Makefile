# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 16:07:56 by lpaulo-m          #+#    #+#              #
#    Updated: 2023/08/07 00:42:12 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

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

SOURCES = BitcoinExchange.cpp main.cpp
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
	./$(NAME) input.txt
	./$(NAME) input_empty.txt

vg: re
	valgrind ./$(NAME) input.txt
	valgrind ./$(NAME) input_empty.txt

################################################################################
# PHONY
################################################################################

.PHONY: all re clean fclean run vg
