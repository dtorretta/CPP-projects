NAME = PhoneBook

SRC	=   sources/PhoneBook.cpp \
		sources/Contact.cpp \
		sources/main.cpp 

INC_DIR	=	includes
INC =   $(shell find $(INC_DIR) -type f -name "*.hpp")
   
OBJS = $(SRC:%.cpp=%.o)

CPP = g++
CPP_FLAGS = -Wall -Wextra -Werror -std=c++98 

all: $(NAME)

$(NAME):		$(OBJS)
	@$(CPP) $(CPP_FLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo "\n📟 PhoneBook ready.\n"

%.o: %.cpp
	@$(CPP) $(CPP_FLAGS) -c -o $@ $<
	
clean:
	@rm -f $(OBJS)
	@echo "\n💧 Clean done \n"

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re