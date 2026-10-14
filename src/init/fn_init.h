#ifndef INIT_H
# define INIT_H

#include "type_engine.h"

int	init_engine(t_engine *engine);
int	init_scene(t_scene *scene);
int	init_mlx(t_mlx *mlx, t_mlx_img *cur, t_mlx_img *next);
int	init_light_lst(t_scene *scene);
int	init_obj_lst(t_scene *scene);

#endif
