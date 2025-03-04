NAME = HI_THIS_IS_BRAIN

SRC	=   main.cpp

INC =   -I ./includes/
   
OBJS = $(SRC:%.cpp=%.o)

CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME):		$(OBJS)
	@$(CPP) $(CPP_FLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo "\n🧠 HI THIS IS BRAIN ready.\n"

%.o: %.cpp
	@$(CPP) $(CPP_FLAGS) -c -o $@ $<
	
clean:
	@rm -f $(OBJS)
	@echo "\n💧 Clean done \n"

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re