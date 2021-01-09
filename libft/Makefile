# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcloves <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 20:40:24 by hcloves           #+#    #+#              #
#    Updated: 2019/11/02 15:41:53 by hcloves          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = libft.h

SRC = ft_strlen.c ft_strdup.c ft_putchar.c ft_strncpy.c ft_strcpy.c ft_bzero.c ft_strstr.c ft_strnstr.c \
	  ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
	  ft_islower.c ft_isupper.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c \
	  ft_isalpha.c ft_isdigit.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	  ft_memcmp.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
	  ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	  ft_strtrim.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putchar_fd.c ft_range.c ft_swap.c ft_sqrt.c \
	  ft_lstnew.c ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c ft_calloc.c

OBJCT = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c $(HEADERS)
	@gcc -c -Wall -Wextra -Werror $< -I $(HEADERS)

$(NAME): $(OBJCT)
				@ar rc $(NAME) $(OBJCT)
					@ranlib $(NAME)

clean:
			@/bin/rm -f $(OBJCT)

fclean: clean
			@/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
