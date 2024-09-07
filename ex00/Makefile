CPP:= g++
CPP_RULES := -Wall -Wextra -Werror -std=c++98

NAME := fixed

SRC := main.cpp \
		Fixed.cpp

OBJ := $(SRC:.cpp=.o)

all:$(NAME)


$(NAME):$(OBJ)
	$(CPP) $(CPP_RULES) -o $(NAME) $(OBJ)

%.o:%.cpp
	$(CPP) $(CPP_RULES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: clean fclean all

.PHONY:clean fclean re all