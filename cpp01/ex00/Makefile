NAME = zombie

CC = c++ 
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRC = main.cpp newZombie.cpp randomChump.cpp Zombie.cpp \

OBJ = ${SRC:.cpp=.o}
OBJ_DIR = obj/
OBJECT_PREFIXED = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(OBJ_DIR)%.o : %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJECT_PREFIXED)
	@$(CC) $(OBJECT_PREFIXED) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean
	@$(MAKE) all

.PHONY:	all clean fclean re