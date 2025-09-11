NAME		=	fractol
SRCS		=	fractol.c


OBJDIR		=	OBJS
OBJS		=	$(SRCS:%.c=$(OBJDIR)/%.o)

MLX_DIR		=	./minilibx-linux
MLX_LIB		=	$(MLX_DIR)/libmlx.a
MLX_FLAGS	=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

all:		$(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
			
$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)
		
$(OBJDIR)/%.o: %.c fractol.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(MLX_DIR) -c $< -o $@

		
run: $(NAME)
	@env DISPLAY=host.docker.internal:0 orb run -m ubuntu2204 ./$(NAME)

	
clean:
	$(RM) $(OBJDIR)
	$(MAKE) -C $(MLX_DIR) clean
		
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(MLX_DIR) clean
	
re:	fclean all
	
.PHONY:	all clean fclean re run
	