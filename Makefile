NAME		=	fractol

SRCS		=	colors.c	\
				complex.c	\
				fractol.c	\
				hooks.c		\
				inits.c		\
				main.c		\
				mapping.c	\
				mlx.c		\
				parse.c		\
				sets.c		\
				utils.c

OBJDIR		=	OBJS
OBJS		=	$(SRCS:%.c=$(OBJDIR)/%.o)

MLX_DIR		=	./minilibx-linux
LIBFT_DIR	=	./libft

MLX_LIB		=	$(MLX_DIR)/libmlx.a
LIBFT_LIB	=	$(LIBFT_DIR)/libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

INCLUDES	=	-I $(LIBFT_DIR) -I $(MLX_DIR)
LIBS		=	-L $(LIBFT_DIR) -lft \
				-L $(MLX_DIR) -lmlx -lXext -lX11 -lm

all:		$(NAME)

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: %.c fractol.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

run: $(NAME)
	@env DISPLAY=host.docker.internal:0 orb run -m ubuntu2204 ./$(NAME)

clean:
	$(RM) $(OBJDIR)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re:	fclean all

.PHONY:	all clean fclean re run
