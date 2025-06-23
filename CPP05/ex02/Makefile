NAME = Forms

SRC	=   sources/Bureaucrat.cpp \
		sources/AForm.cpp \
		sources/ShrubberyCreationForm.cpp \
		sources/RobotomyRequestForm.cpp \
		sources/PresidentialPardonForm.cpp \
		sources/main.cpp

INC =   -I ./includes/
   
OBJS = $(SRC:%.cpp=%.o)

CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME):		$(OBJS)
	@$(CPP) $(CPP_FLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo "\n✨ Forms 28B & 28C are ready.\n"

%.o: %.cpp
	@$(CPP) $(CPP_FLAGS) -c -o $@ $<
	
clean:
	@rm -f $(OBJS)
	@rm -f *.o $(NAME) *_shrubbery
	@echo "\n💧 Clean done \n"

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re