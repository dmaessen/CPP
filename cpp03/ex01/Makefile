NAME = clapscav

CC = c++ 
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

HEADERS = include/ClapTrap.hpp include/ScavTrap.hpp 

SRC = src/main.cpp src/ClapTrap.cpp src/ScavTrap.cpp \

OBJ = ${SRC:.cpp=.o}
OBJ_DIR = obj/
OBJECT_PREFIXED = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(OBJ_DIR)%.o : %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) -o $@ -c $< 

$(NAME): $(OBJECT_PREFIXED)
	@$(CC) $(OBJECT_PREFIXED)  -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean
	@$(MAKE) all

.PHONY:	all clean fclean re