NAME = miniRT
TEST = test
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -MMD -MP
LINK = -lXext -lX11 -lm
HEADER = libs/libft libs/minilibx-linux $(DIRS)
ARC_LIBFT = libs/libft/libft.a
ARC_MINILIBX = libs/minilibx-linux/libmlx_Linux.a libs/minilibx-linux/libmlx.a
ARC = $(ARC_MINILIBX) $(ARC_LIBFT)
INCLUDE = $(foreach H,$(HEADER),-I $H)

DIRS = $(sort $(dir $(SRC))) src/math/ include/

SRC_END_DIR = end_program/
SRC_END_FILES = end_program.c
SRC_END = $(foreach F,$(SRC_END_FILES),$(SRC_END_DIR)$F)


SRC_INIT_SCENE_DIR = init_scene/
SRC_INIT_SCENE_FILES = init_lights.c init_obj.c
SRC_INIT_SCENE = $(foreach F,$(SRC_INIT_SCENE_FILES),$(SRC_INIT_SCENE_DIR)$F)

SRC_INIT_ENGINE_DIR = init_engine/
SRC_INIT_ENGINE_FILES =  init_mlx.c init_scene.c $(SRC_INIT_SCENE)
SRC_INIT_ENGINE = $(foreach F,$(SRC_INIT_ENGINE_FILES),$(SRC_INIT_ENGINE_DIR)$F)

SRC_INIT_DIR = init/
SRC_INIT_FILES = init_engine.c $(SRC_INIT_ENGINE)
SRC_INIT = $(foreach F,$(SRC_INIT_FILES),$(SRC_INIT_DIR)$F)


SRC_MATH_SHAPE_DIR = shape/
SRC_MATH_SHAPE_FILES = is_in_shape.c get_surface_normal.c
SRC_MATH_SHAPE = $(foreach F,$(SRC_MATH_SHAPE_FILES),$(SRC_MATH_SHAPE_DIR)$F)

SRC_MATH_BASIC_DIR = basic_maths/
SRC_MATH_BASIC_FILES = 2nd_degree.c max_min.c change_interval.c
SRC_MATH_BASIC = $(foreach F,$(SRC_MATH_BASIC_FILES),$(SRC_MATH_BASIC_DIR)$F)

SRC_MATH_VEC_DIR = vector/
SRC_MATH_VEC_FILES = basic_vector_math.c build_vec.c dot.c normalize.c projection.c vec_product.c
SRC_MATH_VEC = $(foreach F,$(SRC_MATH_VEC_FILES),$(SRC_MATH_VEC_DIR)$F)

SRC_MATH_DIR = math/
SRC_MATH_FILES = $(SRC_MATH_VEC) $(SRC_MATH_BASIC) $(SRC_MATH_SHAPE)
SRC_MATH = $(foreach F,$(SRC_MATH_FILES),$(SRC_MATH_DIR)$F)


SRC_RAYTRACING_SHOOT_DIR = shoot_ray/
SRC_RAYTRACING_SHOOT_FILES = get_color.c get_closest_object.c
SRC_RAYTRACING_SHOOT = $(foreach F,$(SRC_RAYTRACING_SHOOT_FILES),$(SRC_RAYTRACING_SHOOT_DIR)$F)

SRC_RENDER_RAYTRACING_DIR = raytracing/
SRC_RENDER_RAYTRACING_FILES = build_ray_vec.c shoot_ray_recursive.c $(SRC_RAYTRACING_SHOOT)
SRC_RENDER_RAYTRACING = $(foreach F,$(SRC_RENDER_RAYTRACING_FILES),$(SRC_RENDER_RAYTRACING_DIR)$F)

SRC_RENDER_DIR = render/
SRC_RENDER_FILES = raytrace.c $(SRC_RENDER_RAYTRACING)
SRC_RENDER = $(foreach F,$(SRC_RENDER_FILES),$(SRC_RENDER_DIR)$F)


SRC_MLX_DIR = mlx/
SRC_MLX_FILES = mlx_render_utils.c mlx_render.c mlx_signals.c
SRC_MLX = $(foreach F,$(SRC_MLX_FILES),$(SRC_MLX_DIR)$F)


SRC_DIR = src/
SRC_FILES = main.c $(SRC_RENDER) $(SRC_MATH) $(SRC_INIT) $(SRC_END) $(SRC_MLX)
SRC = $(foreach F,$(SRC_FILES),$(SRC_DIR)$F)

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
	make -C libs/minilibx-linux/

$(ARC_LIBFT) :
	make -C libs/libft/

.PHONY = all re clean fclean clean_everything fclean_everything

-include $(DEPENDENCIES)
