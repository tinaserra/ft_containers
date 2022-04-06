# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tinaserra <tinaserra@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 15:14:20 by vserra            #+#    #+#              #
#    Updated: 2022/04/05 19:37:04 by tinaserra        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	main.cpp \
		utils_iterator_traits.cpp \
		utils_reverse_iterator.cpp \
		utils_enable_if.cpp \
		utils_is_integral.cpp \
		utils_equal.cpp \
		utils_lexicographical_compare.cpp \
		utils_pair.cpp \
		utils_make_pair.cpp \
		vector_assign.cpp

NAME = ft_containers

# override -> permet de reecrire la suite de la variable
override CXXFLAGS += -Wall -Wextra -Werror -MMD -std=c++11

OBJ_DIR = obj
SRC_DIR = _main_test
INC_DIR = .

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.o))
DPD = $(addprefix $(OBJ_DIR)/,$(SRC:.cpp=.d))

_CREATED = \033[32mCreated !\033[0m
_DELETED = \033[1;34mdeleted\033[0m

all: $(NAME)

# permet de pouvoir comparer la derniere modification de la dep par rapport a la regle
$(NAME): $(OBJ)
		@c++ $(CXXFLAGS) -o $(NAME) $(OBJ)
		@echo "[$(NAME)]: $(_CREATED)"

# si le .cpp est plus recent que le .o on rentre dans la regle
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | .gitignore
		@mkdir -p $(OBJ_DIR)
		@c++ $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@

.gitignore:
		@echo $(NAME) > .gitignore
		@echo $(OBJ_DIR) >> .gitignore

debug : fclean
	make all CXXFLAGS:="-DDEBUG -g"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "obj $(_DELETED)"

fclean:	clean
	@rm -rf $(NAME)
	@echo "[$(NAME)]: $(_DELETED)"

re: fclean all

.PHONY: all, clean, fclean, re

# Utilise les .d (et ignore s'ils n'existe pas)
-include $(DPD)