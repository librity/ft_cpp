# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 16:07:56 by lpaulo-m          #+#    #+#              #
#    Updated: 2023/07/22 17:28:15 by lpaulo-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scalar_converter

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

SOURCES = ScalarConverter.cpp main.cpp
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

TEST_CASES = \
	"c" "a" "0" \
	"-42" "42" "0.0f" "-4.2f" "4.2f" "42.0f" \
	"0.0" "-4.2" "4.2" "42.0" "42.0e-1" "42.0E-1" "-42.0e-1" "-42.0E-1" \
	"-inff" "+inff" "nanf" "-inf" "+inf" "nan"


run: re
#	./$(NAME) ; echo
#	./$(NAME) 42 42 ; echo
	for test_case in $(TEST_CASES); do \
		echo ./$(NAME) $$test_case; \
		./$(NAME) $$test_case; \
		echo; \
	done


vg: re
#	valgrind ./$(NAME) ; echo
#	valgrind ./$(NAME) 42 42 ; echo
	for test_case in $(TEST_CASES); do \
		echo valgrind ./$(NAME) $$test_case; \
		valgrind ./$(NAME) $$test_case; \
		echo; \
	done

################################################################################
# PHONY
################################################################################

.PHONY: all re clean fclean run vg
