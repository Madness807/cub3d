NAME			=		cub3d

# Sources / Objs
SRC				=		srcs/main.c\
						srcs/init.c\
						srcs/parsing/read_map_cub.c\
						srcs/parsing/fill_map_struct.c\
						srcs/engine/render.c\
						srcs/engine/rays.c\
						srcs/engine/3d.c\
						srcs/engine/hook.c\
						srcs/error/print_error.c\
						srcs/test/verbos.c\
						srcs/utils/utils.c

OBJ_DIR			=		build/
OBJS			=		$(patsubst srcs/%,$(OBJ_DIR)%,$(SRC:.c=.o))

MAKEFLAGS += --no-print-directory

# Libft
LIBFT_DIR		=		./lib/libft/
LIBFT			=		$(LIBFT_DIR)libft.a

# MLX
MLX_DIR         =       ./lib/mlx/
MLX				=		$(MLX_DIR)libmlx.a

#***** Couleurs *****#
GREEN			=		\033[1;32m
BG_GREEN		=		\033[42m
BLUE			=		\033[0;94m
RED				=		\033[1;31m
GREY			=		\033[0;37m
ENDCOLOR		=		\033[0m

#******Echo********#
START			=		echo "$(BLUE)Start compilation cub3D\n$(ENDCOLOR)"

# Compiler and flags
CC				=		gcc -g
MINILBX			=		-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
CFLAGS			=		-Wall -Wextra -Werror
L				=		$(CFLAGS) -fsanitize=address
RM				=		rm -f

# Recipes
all: logo $(LIBFT) $(MLX) start  $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

start:
	@${START}
logo :
	@cat ./assets/logo.txt

$(OBJ_DIR)%.o: srcs/%.c 
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I./include -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) -L $(LIBFT_DIR) -lft $(MINILBX) -o $(NAME)

l :
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(L) -I./include $(SRC) -L $(LIBFT_DIR) -lft $(MINILBX) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all 
