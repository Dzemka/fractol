#TARGET
	NAME	=	fractol

#COMMANDS
	CC	=	gcc
	RM	=	rm -rf

#DIRECTORIES
	DIR_SRC	=	./src/
	DIR_INC	=	./includes/
	DIR_OBJ	=	./obj/
	DIR_LIB = ./includes/libft/

#FILES
	SRC	=	fractol.c \
			ft_get_data.c \
			ft_hook_manager.c \
			ft_draw.c \
			 ft_get_iter_color.c \
			 ft_color.c \
			 ft_utils.c \
			 ft_color_shift.c \
			 ft_select_fractal.c \
			 ft_move_fractal.c \
			 ft_fractal_formulas.c \
			 ft_render_info.c \
			 ft_draw_interface.c

	OBJ	=	$(SRC:%.c=$(DIR_OBJ)%.o)

#HEADERS
	HEADER = ./includes/fractol.h
#LIBS
	LIBFT = includes/libft/libft.a

OS = $(shell uname)

#FLAGS
	CFLAGS = -Wall -Werror -Wextra
	CFLAGS = -Iincludes -Iincludes/libft/includes
	LDFLAGS = -L$(DIR_LIB) -lft

	ifeq ($(OS), Linux)
		DIR_MLX = ./includes/mlx_linux/
		CFLAGS += -Iincludes/mlx_linux
		LIB_MLX = $(DIR_MLX)libmlx_Linux.a
		LDFLAGS += -L$(DIR_MLX) -lmlx_Linux -lXext -lX11 -lm -lz
	else
		DIR_MLX = ./includes/minilibx_opengl
		CFLAGS += -I$(DIR_MLX)
		LIB_MLX = $(DIR_MLX)libmlx.a
		LDFLAGS +=  -L$(DIR_MLX) -lmlx -framework OpenGL -framework AppKit
	endif

#PATH_LIST
	VPATH = $(DIR_SRC) $(DIR_INC)

.PHONY	:	all clean fclean re libft libmlx

all	:	libmlx libft $(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(DIR_OBJ)%.o:%.c $(HEADER)
	mkdir -p $(DIR_OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

libft	:
	make -C $(DIR_LIB) all

libmlx	:
	$(MAKE) -C $(DIR_MLX) all

clean	:
	$(RM) $(DIR_OBJ)
	$(MAKE) -C $(DIR_LIB) clean
	$(MAKE) -C $(DIR_MLX) clean

fclean	: clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIR_LIB) fclean

re :	fclean all

