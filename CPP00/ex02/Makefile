NAME = account

SRC	=   sources/Account.cpp \
		sources/tests.cpp

INC =   -I ./includes/
   
OBJS = $(SRC:%.cpp=%.o)

CPP = c++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME):		$(OBJS)
	@$(CPP) $(CPP_FLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo "\n📟 Account ready.\n"

%.o: %.cpp
	@$(CPP) $(CPP_FLAGS) -c -o $@ $<
	
clean:
	@rm -f $(OBJS)
	@echo "\n💧 Clean done \n"

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re