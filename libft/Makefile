NAME = libft.a
SOURCES = ft_atoi.c ft_bzero.c ft_isalnum.c \
          ft_isalpha.c ft_isascii.c ft_isdigit.c \
          ft_isprint.c ft_memcpy.c ft_memchr.c \
          ft_memcmp.c ft_memmove.c \
          ft_memset.c ft_strchr.c ft_strncmp.c \
          ft_strlcpy.c ft_strlcat.c ft_strlen.c \
          ft_strrchr.c ft_tolower.c \
          ft_toupper.c ft_strnstr.c ft_strjoin.c \
          ft_strtrim.c ft_strmapi.c ft_striteri.c \
          ft_split.c ft_itoa.c ft_putchar_fd.c \
          ft_putstr_fd.c ft_putendl_fd.c \
          ft_putnbr_fd.c ft_calloc.c ft_strdup.c \
		  ft_substr.c \
          ft_printf.c ft_printhex.c ft_printid.c\
          ft_printu.c ft_printp.c \
          get_next_line.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = libft.h
RM = rm -rf                                                     

all: $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:                                                                          
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
