NAME = ft_containers

FLAGS = -g -Wall -Werror -Wextra --std=c++98

CXX = clang++

SRCS = main.cpp  test_stack.cpp  test_vector.cpp  test_map.cpp

OBJS_FOLDER = objs/
OBJ =  $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJS_FOLDER), $(OBJ))


all: $(NAME)

$(OBJS_FOLDER)%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re                        
