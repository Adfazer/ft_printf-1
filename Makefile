NAME			= libftprintf.a

SRCS_LIST		= \
					ft_printf.c \
					parse.c \
					parse2.c \
					conversion_type.c \
					conversion_type2.c \
					conversion_type3.c \
					conversion_type4.c \
					conversion_type_float.c \
					conversion_type_add.c \
					conversion_type5.c \
					conversion_type6.c \
					func.c \
					func2.c

SRCS			= $(addprefix ${FOLDER}/, ${SRCS_LIST})

OBJS			= ${SRCS:.c=.o}

HEADER			= includes
FOLDER			= srcs

LIBFT 			= libft

CC				= gcc
CFLAGS 			= -Wall -Wextra -Werror
RM				= rm -f

all:			${NAME}

$(NAME):		${OBJS}
				@make -C $(LIBFT)
				@cp libft/libft.a ./$(NAME)
				@ar -rcs ${NAME} ${OBJS}


%.o: %.c
				@${CC} ${CFLAGS} -I ${HEADER} -o $@ -c $<

clean:
				@${RM} ${OBJS}
				@make clean -C $(LIBFT)

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C $(LIBFT)

re:				fclean all

.PHONY: 		all fclean clean re
