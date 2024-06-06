NAME = PmergeMe

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++11
RM = rm -f

HEADERS = include/PmergeMe.hpp

SRC = src/main.cpp src/PmergeMe.cpp src/PmergeMeVec.cpp src/PmergeMeDeque.cpp

OBJ_DIR = obj/
OBJ = $(SRC:src/%.cpp=$(OBJ_DIR)%.o)

all: $(NAME)

$(OBJ_DIR)%.o: src/%.cpp $(HEADERS)
	@echo "Compiling $< to $@"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "Linking $@"
	@$(CC) $(CPPFLAGS) $^ -o $@

clean:
	@echo "Cleaning object files in $(OBJ_DIR)"
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@echo "Cleaning executable $(NAME)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re