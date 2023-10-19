NAME			=		cub3d

# Sources / Objs
SRC				=		srcs/main.c\
						srcs/init.c\
						srcs/render.c\
						srcs/utils.c\
						srcs/rays.c\
						srcs/3d.c\
						srcs/hook.c\
						srcs/error/print_error.c\
						srcs/parsing/fill_map_struct.c\
						srcs/parsing/read_map_cub.c

OBJ_DIR			=		build/
OBJS			=		$(patsubst srcs/%,$(OBJ_DIR)%,$(SRC:.c=.o))

MAKEFLAGS += --no-print-directory

# Libft
LIBFT_DIR		=		./lib/libft/
LIBFT			=		$(LIBFT_DIR)libft.a

# MLX
MLX_DIR         =       ./lib/mlx/
MLX				=		$(MLX_DIR)libmlx.a

# Compiler and flags
CC				=		gcc -g
MINILBX			=		-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
CFLAGS			=		-Wall -Wextra -Werror
L				=		$(CFLAGS) -fsanitize=address
RM				=		rm -f

# Recipes
all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

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
