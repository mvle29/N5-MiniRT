NAME = miniRT
TEST = test
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -MMD -MP -std=gnu17
LINK = -lXext -lX11 -lm
HEADER = libs/libft libs/minilibx-linux $(DIRS)
ARC_LIBFT = libs/libft/libft.a
ARC_MINILIBX = libs/minilibx-linux/libmlx_Linux.a libs/minilibx-linux/libmlx.a
ARC = $(ARC_MINILIBX) $(ARC_LIBFT)
INCLUDE = $(foreach H,$(HEADER),-I $H)

DIRS = $(sort $(dir $(SRC))) src/math/ include/

SRC_END_FILES = end_program.c

SRC_ERROR_FILES = exit_error.c puterror.c

SRC_INIT_SCENE_FILES = init_lights.c init_obj.c
SRC_INIT_ENGINE_FILES = $(addprefix init_scene/, $(SRC_INIT_SCENE_FILES)) init_mlx.c init_scene.c
SRC_INIT_FILES = $(addprefix init_engine/, $(SRC_INIT_ENGINE_FILES)) init_engine.c

SRC_MATH_SHAPE_FILES = is_in_shape.c get_surface_normal.c
SRC_MATH_BASIC_FILES = 2nd_degree.c max_min.c change_interval.c
SRC_MATH_VEC_FILES = basic_vector_math.c build_vec.c dot.c normalize.c projection.c vec_product.c
SRC_MATH_FILES = $(addprefix vector/, $(SRC_MATH_VEC_FILES)) \
				 $(addprefix basic_maths/, $(SRC_MATH_BASIC_FILES)) \
				 $(addprefix shape/, $(SRC_MATH_SHAPE_FILES))

SRC_MLX_FILES = mlx_render_utils.c mlx_render.c mlx_signals.c

SRC_PARSING_FILES = parse_file.c

SRC_RAYTRACING_SHOOT_FILES = get_color.c get_closest_object.c
SRC_RENDER_RAYTRACING_FILES = $(addprefix shoot_ray/, $(SRC_RAYTRACING_SHOOT_FILES)) build_ray_vec.c shoot_ray_recursive.c
SRC_RENDER_FILES = $(addprefix raytracing/, $(SRC_RENDER_RAYTRACING_FILES)) raytrace.c

SRC_FILES = $(addprefix end_program/, $(SRC_END_FILES)) \
			 $(addprefix error_printing/, $(SRC_ERROR_FILES)) \
			 $(addprefix init/, $(SRC_INIT_FILES)) \
			 $(addprefix math/, $(SRC_MATH_FILES)) \
			 $(addprefix mlx/, $(SRC_MLX_FILES)) \
			 $(addprefix parsing/, $(SRC_PARSING_FILES)) \
			 $(addprefix render/, $(SRC_RENDER_FILES)) \
			 main.c

SRC = $(addprefix src/, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

DEPENDENCIES = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ) $(ARC_LIBFT) $(ARC_MINILIBX)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(ARC) -o $(NAME) $(LINK)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -f $(OBJ)
	rm -f $(DEPENDENCIES)

clean_everything : clean
	make clean -C libs/minilibx-linux
	make clean -C libs/libft

fclean : clean
	rm -f $(NAME)

fclean_everything : clean_everything fclean
	make fclean -C libs/libft

re : fclean all

$(ARC_MINILIBX) :
	make -C libs/minilibx-linux/ CC="gcc -std=gnu17"

$(ARC_LIBFT) :
	make -C libs/libft/

.PHONY = all re clean fclean clean_everything fclean_everything

-include $(DEPENDENCIES)
