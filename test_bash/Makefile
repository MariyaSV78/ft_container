NAME_ft_v = ft_vector
NAME_std_v = std_vector
NAME_ft_m = ft_map
NAME_std_m = std_map
NAME_ft_s = ft_stack
NAME_std_s = std_stack

FLAGS_ft = -g -Wall -Werror -Wextra --std=c++98 -D NAMESPACE=ft
FLAGS_std = -g -Wall -Werror -Wextra --std=c++98 -D NAMESPACE=std


#CXX = c++
CXX = clang++

SRC_DIR = srcs/
SRCS_m = test_map.cpp
SRCS_v = test_vector.cpp
SRCS_s = test_stack.cpp


OBJS_FOLDER_ft = objs/ft/
OBJS_FOLDER_std = objs/std/

OBJ_ft_v=  $(addprefix $(OBJS_FOLDER_ft), $(SRCS_v:.cpp=.opp))
OBJ_ft_m=  $(addprefix $(OBJS_FOLDER_ft), $(SRCS_m:.cpp=.opp))
OBJ_ft_s=  $(addprefix $(OBJS_FOLDER_ft), $(SRCS_s:.cpp=.opp))
OBJ_std_v=  $(addprefix $(OBJS_FOLDER_std), $(SRCS_v:.cpp=.opp))
OBJ_std_m=  $(addprefix $(OBJS_FOLDER_std), $(SRCS_m:.cpp=.opp))
OBJ_std_s=  $(addprefix $(OBJS_FOLDER_std), $(SRCS_s:.cpp=.opp))

all: 
	mkdir -p $(OBJS_FOLDER_ft)
	mkdir -p $(OBJS_FOLDER_std)
	make $(NAME_ft_v) $(NAME_ft_m) $(NAME_ft_s) $(NAME_std_v) $(NAME_std_m) $(NAME_std_s)

$(OBJS_FOLDER_ft)%.opp: $(SRC_DIR)%.cpp
	$(CXX) $(FLAGS_ft) -c $< -o $@
$(OBJS_FOLDER_std)%.opp: $(SRC_DIR)%.cpp
	$(CXX) $(FLAGS_std) -c $< -o $@


$(NAME_ft_v): $(OBJ_ft_v)
	$(CXX) $(FLAGS_ft)  $(OBJ_ft_v) -o $(NAME_ft_v)
$(NAME_ft_m): $(OBJ_ft_m)
	$(CXX) $(FLAGS_ft)  $(OBJ_ft_m) -o $(NAME_ft_m)
$(NAME_ft_s): $(OBJ_ft_s) 
	$(CXX) $(FLAGS_ft)  $(OBJ_ft_s) -o $(NAME_ft_s)
$(NAME_std_v): $(OBJ_std_v)
	$(CXX) $(FLAGS_std)  $(OBJ_std_v) -o $(NAME_std_v)
$(NAME_std_m): $(OBJ_std_m)
	$(CXX) $(FLAGS_std)  $(OBJ_std_m) -o $(NAME_std_m)
$(NAME_std_s): $(OBJ_std_s)
	$(CXX) $(FLAGS_std)  $(OBJ_std_s) -o $(NAME_std_s)

clean:
	rm -rf objs/

fclean: clean
	rm -f $(NAME_ft_v)
	rm -f $(NAME_std_v)
	rm -f $(NAME_ft_m)
	rm -f $(NAME_std_m)
	rm -f $(NAME_ft_s)
	rm -f $(NAME_std_s)

re: fclean all

.PHONY: all clean fclean re     
