# **************************************************************************** #DERS = 
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: maberkan <maberkan@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/03 12:12:20 by maberkan     #+#   ##    ##    #+#        #
#    Updated: 2018/10/22 11:38:09 by maberkan    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_atoi.c ./ft_itoa.c ./ft_memmove.c ./ft_putnbr_fd.c \
      ./ft_strlcat.c ./ft_strnequ.c ./ft_tolower.c ./ft_bzero.c \
	  ./ft_memset.c ./ft_memalloc.c ./ft_putstr.c ./ft_strdel.c \
	  ./ft_strstr.c ./ft_isalnum.c ./ft_memccpy.c ./ft_putchar.c \
	  ./ft_strmap.c ./ft_strnstr.c ./ft_isalpha.c ./ft_memchr.c \
	  ./ft_memcmp.c ./ft_strdup.c ./ft_strlen.c ./ft_strcmp.c \
	  ./ft_strcat.c ./ft_strequ.c ./ft_strmapi.c ./ft_isascii.c \
	  ./ft_putendl.c ./ft_strchr.c ./ft_striter.c ./ft_putchar_fd.c \
	  ./ft_strncat.c ./ft_isdigit.c ./ft_memcpy.c ./ft_putendl_fd.c \
	  ./ft_striteri.c ./ft_strncmp.c ./ft_strsub.c ./ft_strtrim.c \
	  ./ft_memdel.c ./ft_putnbr.c ./ft_strjoin.c ./ft_strncpy.c \
	  ./ft_strnew.c ./ft_toupper.c ./ft_putstr_fd.c ./ft_isprint.c \
	  ./ft_strclr.c ./ft_strcpy.c ./ft_strrchr.c ./ft_strsplit.c \
	  ./ft_strrev.c ./ft_nbrlen.c ./ft_nbrword.c ./ft_strndup.c \
	  ./ft_lstnew.c ./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c \
	  ./ft_lstdelone.c ./ft_lstdel.c ./ft_realloc.c

HEADERS = libft.h

CC = gcc

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ ranlib $(NAME)

%.o: %.c
	@ gcc $(FLAGS) -I $(HEADERS) -o $@ -c $<

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
