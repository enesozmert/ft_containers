#Definition
NAME        	=   ft_containet
CC				=	c++
USER_NAME1		=	eozmert
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -g -I
RM				=	rm -f

#Directory
SRC_DIR			= 	src/
OBJ_DIR			=	obj/

#Files
SRC_COMMON		=   common/
SRC_CONTAINERS	= 	containers/
SRC_FUNCTINOS	= 	functions/
SRC_ITERATOR	= 	iterators/
SRC_TEST		=	test/

COMMON			=	
CONTAINERS		=	vector	
FUNCTINOS		= 
ITERATOR		=	iterator
TEST			= 

SRC_FILES		+=	$(addprefix $(SRC_COMMON),$(COMMON))
SRC_FILES		+=	$(addprefix $(SRC_CONTAINERS),$(CONTAINERS))
SRC_FILES		+=	$(addprefix $(SRC_FUNCTINOS),$(FUNCTINOS))
SRC_FILES		+=	$(addprefix $(SRC_ITERATOR),$(ITERATOR))
SRC_FILES		+=	$(addprefix $(SRC_TEST),$(TEST))

#FileCreate
SRC 			= 	$(addprefix $(SRC_DIR), $(addsuffix .hpp, $(SRC_FILES)))
OBJ 			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILE)))

OBJF			=	.cache_exists

all:		welcome $(NAME)

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(SRC_COMMON)
			@mkdir -p $(OBJ_DIR)$(SRC_CONTAINERS)
			@mkdir -p $(OBJ_DIR)$(SRC_FUNCTINOS)
			@mkdir -p $(OBJ_DIR)$(SRC_ITERATOR)
			@mkdir -p $(OBJ_DIR)$(SRC_TEST)

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