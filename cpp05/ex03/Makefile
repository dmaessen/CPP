NAME = bureaucrat

CC = c++ 
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++11
RM = rm -f

HEADERS = include/Bureaucrat.hpp include/AForm.hpp include/ShrubberyCreationForm.hpp include/RobotomyRequestForm.hpp include/PresidentialPardonForm.hpp include/Intern.hpp \

SRC = src/main.cpp src/Bureaucrat.cpp src/AForm.cpp src/ShrubberyCreationForm.cpp src/RobotomyRequestForm.cpp src/PresidentialPardonForm.cpp src/Intern.cpp \

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