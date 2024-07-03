MAKEFLAGS += --silent

# ------------------------------ Sources ------------------------------

# Files
LIBFT		=	cd libft && make
LIB			=	libft/libft.a

# Sources and objects
SRC			=	src/main.c \
				src/forks.c \
				src/utils.c
OBJS		=	$(SRC:.c=.o)
BONUS_SRC	=	bonus/main_bonus.c\
				bonus/forks_bonus.c\
				bonus/utils_bonus.c
BONUS_OBJ	=	$(BONUS_SRC:.c=.o)	
				
# ------------------------------ Constant strings ------------------------------

GCC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I include -g
SERVER_NAME	=	server
CLIENT_NAME	=	client
NAME		=	pipex

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"
CLI_READY	=	echo "\n📟 $(BOLD_CYAN)Compilation done !\n"
CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"
FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# ------------------------------ Rules ------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMP_START)
	@$(LIBFT)
	@$(GCC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@$(CLI_READY)

bonus: $(BONUS_OBJ)
	@$(COMP_START)
	@$(LIBFT)
	@$(GCC) $(CFLAGS) $(BONUS_OBJ) $(LIB) -o $(NAME)
	@$(CLI_READY)

clean:
	@rm -rf $(OBJS)
	@cd libft && make clean
	@$(CLEANED)

fclean: clean
	@rm -rf $(NAME)
	@cd libft && make fclean
	@$(FCLEANED)


re:	fclean all

.PHONY: all clean fclean re bonus