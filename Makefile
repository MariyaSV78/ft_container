NAME = ft_containers

FLAGS = -g -Wall -Werror -Wextra -Wshadow -fsanitize=address -g3 -std=c++98

CXX = clang++

INCS_DIR = incs
OBJS_DIR = objs/
SRCS_DIR = srcs/

# --  Search All files in SRCS  -- #
SRC_DIR = $(shell find srcs -type d)
vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)
SRCS = $(foreach dir, $(SRC_DIR), $(foreach file, $(wildcard $(dir)/*.cpp), $(notdir $(file))))

# --  Redirection in OBJS  -- #
 OBJ = $(SRCS:%.cpp=%.opp)
 OBJS = $(addprefix $(OBJS_DIR), $(OBJ))



all: 
	mkdir -p $(OBJS_DIR)
	make $(NAME)

$(NAME): $(OBJS)
	echo "$(OBJS)"
	@echo "\033[93m>> Compilation\033[0m"
	$(CXX) $(FLAGS) $(OBJS)  -o $(NAME) 

$(OBJS_DIR)%.opp:%.cpp
	@echo "\033[93m>> Obj $@\033[0m"
	$(CXX) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re                        
