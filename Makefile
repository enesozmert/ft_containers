#Definition
NAME        	=   container
CC				=	c++
USER_NAME1		=	eozmert
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -g
RM				=	rm -f

#Directory
OBJ_DIR			=	obj/
SRC_DIR			= 	tests/

#Files
SRC_FILE		=   main test_all test_map

#FileCreate
SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILE)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILE)))

OBJF			=	.cache_exists

all:		welcome $(NAME)

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp | $(OBJF)
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo Compiling Success file is : $< $(SRC_DIR) $@ 

$(NAME):	$(OBJ) $(INC)
			@$(CC) $(OBJ) $(CFLAGS) -o $(NAME) 
			@echo $(NAME) compiled!

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -f $(OBJF)const
			@echo Objects files cleaned!

fclean:		clean
			@$(RM) -f $(NAME)
			@echo $(NAME) executable files cleaned!

re:			fclean all
			@echo Cleaned and rebuilt

welcome:
			@echo "CPP"
			@echo "\n"

.PHONY:		all clean fclean re bonus norm