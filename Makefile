NAME			=		cub3d

# Sources / Objs
SRC				=		srcs/main.c\
						srcs/init.c\
						srcs/parsing/read_map_cub.c\
						srcs/error/print_error.c\
						srcs/test/verbos.c\
						srcs/parsing/fill_map_struct.c

OBJ_DIR			=		build/
OBJS			=		$(patsubst srcs/%,$(OBJ_DIR)%,$(SRC:.c=.o))

# Libft
LIBFT_DIR		=		./lib/libft/
LIBFT			=		$(LIBFT_DIR)libft.a

# MLX
MLX_DIR         =       ./lib/mlx/
MLX				=		$(MLX_DIR)libmlx.a

# Compiler and flags
CC				=		gcc -g
MINILBX			=		-Lmlx -lmlx -framework OpenGL -framework AppKit
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
	$(CC) $(OBJS) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) $(MINILBX) -o $(NAME)

l :
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(L) -I./include $(SRC) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all
