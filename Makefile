#***** Name *****#

NAME			=		cub3d

#***** Sources / Objs *****#

SRC				=		srcs/cub3d.c \
						srcs/exit.c \
						srcs/moove_player.c\
						srcs/read_map.c\
						srcs/write_map.c\
						srcs/check_map.c\
						srcs/init_content.c\
						srcs/check_map_Pathf.c\
						srcs/error.c\
						srcs/events.c

OBJ_DIR			=		obj/
OBJS			=		$(patsubst srcs/%,$(OBJ_DIR)%,$(SRC:.c=.o))

MAKEFLAGS += --no-print-directory

#***** Libft *****#

LIBFT			=		./libft/libft.a
MLIBFT			=		@$(MAKE) -C libft

#***** MLX *****#

MLX				=		./mlx/libmlx.a
MMLX			=		@$(MAKE) -C mlx


#***** Couleurs *****#

GREEN			=		\033[1;32m
BLUE			=		\033[0;94m
RED				=		\033[1;31m
ENDCOLOR		=		\033[0m
BG_G			=		\033[42m

#***** Textes *****#

START			=		echo "$(GREEN)Start compilation\n$(ENDCOLOR)"
TEST			=		echo "Run test\n"
END_COMP		=		echo "$(GREEN)End compilation\n$(ENDCOLOR)"
S_OBJS			=		echo "$(RED)Suppression des objets\n$(ENDCOLOR)"
S_NAME			=		echo "$(RED)Suppression du programme\n$(ENDCOLOR)"
CHARG_LINE		=		echo "$(BG_G)    $(ENDCOLOR)\c"
BS_N			=		echo "\n"

#***** Logo *****#

MSHELL			=		echo "$(GREEN) \t     __  ______    ____  _   __________________\n\
\t    /  |/  /   |  / __ \/ | / / ____/ ___/ ___/\n\
\t   / /|_/ / /| | / / / /  |/ / __/  \__ \\__ \ \n\
\t  / /  / / ___ |/ /_/ / /|  / /___ ___/ /__/ / \n\
\t /_/  /_/_/  |_/_____/_/ |_/_____//____/____/   $(ENDCOLOR)\n"

#***** Flags *****#

GCC				=		gcc -g
MINILBX			=		-Lmlx -lmlx -framework OpenGL -framework AppKit
CFLAGS			=		-Wall -Wextra -Werror
L				=		$(CFLAGS) -fsanitize=address
RM				=		rm -f

#***** Compilation *****#

all : lib start logo $(NAME)

lib:
			@$(MLIBFT)
			@$(MMLX)

start:
			@$(START)

logo :
			@$(MSHELL)	

$(OBJ_DIR)%.o: srcs/%.c
	@mkdir -p $(OBJ_DIR)
	$(GCC) $(CFLAGS) -c $< -o $@

$(NAME) :	${OBJS}
			@$(BS_N)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} $(MINILBX)
			@$(END_COMP)

# $(NAME) :
			# $(GCC) $(FLAGS) $(SRC) $(LIBFT) $(MINILBX) -o $(NAME)
			

l :
			@$(MLIBFT)
			@$(MMLX)
			$(GCC) $(L) $(SRC) $(LIBFT) $(MINILBX) -o $(NAME)


#***** Clean *****#

clean:
			@$(S_OBJS)
			@${RM} -r $(OBJ_DIR)
			@${MLIBFT} clean
			@${MMLX} clean

fclean:		clean
			@$(S_NAME)
			@${RM} ${NAME}
			@${MLIBFT} fclean
			@echo "Succes cleaning"

re:			fclean all

.PHONY:		all clean fclean 
