NAME		= libftprintf.a
SRC_FR		= src/
OBJ_FR		= obj/
LIBFT		= libft
INCLUDES	= ./include
CFLAGS		= -Wall -Werror -Wextra -I
CC			= gcc

SRC_FILES	= ft_printf ntoa print_args print_p

SRC			= $(addprefix $(SRC_FR), $(addsuffix .c, $(SRC_FILES)))
OBJ	 		= $(addprefix $(OBJ_FR), $(addsuffix .o, $(SRC_FILES)))

all: ${OBJ_FR} ${NAME}

$(OBJ_FR)%.o : $(SRC_FR)%.c 
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@

$(OBJ_FR):
	mkdir -p ${OBJ_FR}

$(NAME): ${OBJ}
	make -C ${LIBFT}
	cp ${LIBFT}/libft.a .
	mv libft.a ${NAME}
	ar rcs ${NAME} ${OBJ}

clean:	
	rm -rf ${OBJ_FR}
	make clean -C ${LIBFT}
fclean: clean
	rm -f ${NAME} ${LIBFT}/libft.a
re: fclean all

.PHONY:	all clean fclean re
