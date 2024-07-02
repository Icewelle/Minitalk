MAKEFLAGS += --silent

CC = cc
CCFLAGS = -Wall -Werror -Wextra -Iincludes
SRC =	convert/ft_atoi.c \
		str/ft_bzero.c \
		str/ft_calloc.c\
		verifications/ft_isalnum.c\
		verifications/ft_isalpha.c\
		verifications/ft_isascii.c\
		verifications/ft_isdigit.c\
		verifications/ft_isprint.c\
		convert/ft_itoa.c\
		str/ft_memchr.c\
		str/ft_memcmp.c\
		str/ft_memcpy.c\
		str/ft_memmove.c\
		str/ft_memset.c\
		print/ft_putchar_fd.c\
		print/ft_putendl_fd.c\
		print/ft_putnbr_fd.c\
		print/ft_putstr_fd.c\
		str/ft_split.c\
		str/ft_strchr.c\
		str/ft_strdup.c\
		str/ft_striteri.c\
		str/ft_strjoin.c\
		str/ft_strlcat.c\
		str/ft_strlcpy.c\
		str/ft_strlen.c\
		str/ft_strmapi.c\
		str/ft_strncmp.c\
		str/ft_strnstr.c\
		str/ft_strrchr.c\
		str/ft_strtrim.c\
		str/ft_substr.c\
		str/ft_substr.c\
		convert/ft_tolower.c\
		convert/ft_toupper.c\
		lst/ft_lstnew.c\
		lst/ft_lstadd_front.c\
		lst/ft_lstsize.c\
		lst/ft_lstlast.c\
		lst/ft_lstadd_back.c\
		lst/ft_lstdelone.c\
		lst/ft_lstclear.c\
		lst/ft_lstiter.c\
		lst/ft_lstmap.c\
		verifications/ft_nbrsize.c\
		convert/ft_uitoa.c\
		printf/ft_arg_c.c\
		printf/ft_arg_d.c\
		printf/ft_arg_i.c\
		printf/ft_arg_lower_x.c\
		printf/ft_arg_p.c\
		printf/ft_arg_s.c\
		printf/ft_arg_u.c\
		printf/ft_arg_upper_x.c\
		printf/ft_printf.c\
		printf/ft_utils.c\
		gnl/get_next_line.c
OBJ = $(SRC:.c=.o)
NAME = libft.a

all : $(NAME)

%.o : %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	ar rcs -o $@ $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME) $(OBJ)

re : fclean all

.PHONY : all clean fclean re
