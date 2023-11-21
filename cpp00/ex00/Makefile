NAME = megaphone

SRC =  megaphone.cpp \

OBJ = ${SRC:.cpp=.o}

CC = c++ 
CPPFLAGS = -Wall -Wextra -Werror -std=c++11
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o ${<:.cpp=.o}

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean
	@$(MAKE) all

.PHONY:	all clean fclean re