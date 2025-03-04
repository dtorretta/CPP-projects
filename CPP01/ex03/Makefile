NAME = Violence

SRC	=   sources/HumanA.cpp \
		sources/HumanB.cpp \
		sources/Weapon.cpp \
		sources/main.cpp

INC =   -I ./includes/
   
OBJS = $(SRC:%.cpp=%.o)

CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME):		$(OBJS)
	@$(CPP) $(CPP_FLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo "\n🔪 Violence is ready.\n"

%.o: %.cpp
	@$(CPP) $(CPP_FLAGS) -c -o $@ $<
	
clean:
	@rm -f $(OBJS)
	@echo "\n💧 Clean done \n"

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re