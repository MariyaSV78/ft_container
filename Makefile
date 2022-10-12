NAME = ft_containers

FLAGS = -g -Wall -Werror -Wextra --std=c++98

#CXX = c++
CXX = clang++

OBJS =  $(SRCS:.cpp=.o)

SRCS = main.cpp test_stack.cpp test_vector.cpp

all: $(NAME)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re                        
