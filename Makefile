#Definition
NAME        	=   ft_containet
CC				=	c++
USER_NAME1		=	eozmert
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -g -I
RM				=	rm -f

#Directory
INC_DIR			= 	inc/
TEST_DIR		= 	tests/
OBJ_DIR			=	obj/

#Files
DIR_COMMON		=   common/
DIR_CONTAINERS	= 	containers/
DIR_FUNCTINOS	= 	functions/
DIR_ITERATOR	= 	iterators/
DIR_TEST		=	test/

COMMON			=	
CONTAINERS		=	vector	
FUNCTINOS		= 
ITERATOR		=	iterator
TEST			= 

DIRS_FILES		+=	$(addprefix $(DIR_COMMON),$(COMMON))
DIRS_FILES		+=	$(addprefix $(DIR_CONTAINERS),$(CONTAINERS))
DIRS_FILES		+=	$(addprefix $(DIR_FUNCTINOS),$(FUNCTINOS))
DIRS_FILES		+=	$(addprefix $(DIR_ITERATOR),$(ITERATOR))
DIRS_TEST		+=	$(addprefix $(DIR_TEST),$(TEST))

#FileCreate
INC 			= 	$(addprefix $(INC_DIR), $(addsuffix .hpp, $(DIRS_FILES)))
SRC 			= 	$(addprefix $(TEST_DIR), $(addsuffix .cpp, $(DIRS_TEST)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(DIRS_FILES)))

OBJF			=	.cache_exists

all:		welcome $(NAME)

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(DIR_COMMON)
			@mkdir -p $(OBJ_DIR)$(DIR_CONTAINERS)
			@mkdir -p $(OBJ_DIR)$(DIR_FUNCTINOS)
			@mkdir -p $(OBJ_DIR)$(DIR_ITERATOR)
			@mkdir -p $(OBJ_DIR)$(DIR_TEST)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp | $(OBJF)
			@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@
			@echo Compiling Success file is : $< $(SRC_DIR) $@ 

$(NAME):	$(OBJ) $(INC)
			@$(CC) $(OBJ) $(CFLAGS) $(INC_DIR) -o $(NAME) 
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