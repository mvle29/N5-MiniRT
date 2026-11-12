/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:59:46 by grivault          #+#    #+#             */
/*   Updated: 2026/11/12 19:34:55 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_scene.h"
#include "fn_math.h"
#include "cste_miniRT.h"
#include "libft.h"
#include "fn_parsing.h"

int	parse_ambient(t_scene *scene, char **tokens)
{
	double	ratio;
	t_vec3	color;

	if (scene->ambient_color.r != -1.0)
		return (puterror(ERR_DUP_AMB), 0);
	if (ptrptr_count((void **)tokens) != 3)
		return (puterror(ERR_PARAMS), 0);
	if (!ft_atof(tokens[1], &ratio) || ratio < 0.0 || ratio > 1.0)
		return (puterror(ERR_RATIO), 0);
	if (!parse_color(tokens[2], &color))
		return (puterror(ERR_COLOR), 0);
	scene->ambient_color = mult_by_k_vec(color, ratio);
	return (1);
}

static void	set_cam_vectors(t_scene *scene, t_vec3 fwd, double fov)
{
	double	half_fov_rad;

	scene->cam.fwd = normalize(fwd);
	if (scene->cam.fwd.x == 0.0 && scene->cam.fwd.z == 0.0
		&& (scene->cam.fwd.y == 1.0 || scene->cam.fwd.y == -1.0))
		scene->cam.up = normalize((t_vec3){0.0, 0.0, -scene->cam.fwd.y});
	else
		scene->cam.up = normalize((t_vec3){0.0, 1.0, 0.0});
	scene->cam.right = normalize(vec_product(scene->cam.up,
				scene->cam.fwd, 0));
	scene->cam.up = normalize(vec_product(scene->cam.fwd,
				scene->cam.right, 0));
	scene->cam.fov = fov;
	half_fov_rad = (fov / 2.0) * M_PI / 180.0;
	scene->cam.half_screen_len.x = tan(half_fov_rad);
	scene->cam.half_screen_len.y = scene->cam.half_screen_len.x
		* WIN_H / WIN_W;
}

int	parse_camera(t_scene *scene, char **tokens)
{
	t_vec3	origin;
	t_vec3	fwd;
	double	fov;

	if (scene->cam.fwd.x != 0.0 || scene->cam.fwd.y != 0.0
		|| scene->cam.fwd.z != 0.0)
		return (puterror(ERR_DUP_CAM), 0);
	if (ptrptr_count((void **)tokens) != 4)
		return (puterror(ERR_PARAMS), 0);
	if (!parse_vec3(tokens[1], &origin) || !parse_vec3(tokens[2], &fwd))
		return (puterror(ERR_VEC), 0);
	if (!ft_atof(tokens[3], &fov))
		return (puterror(ERR_FOV), 0);
	if (vec_norm(fwd) == 0.0 || fwd.x < -1.0 || fwd.x > 1.0
		|| fwd.y < -1.0 || fwd.y > 1.0 || fwd.z < -1.0 || fwd.z > 1.0)
		return (puterror(ERR_NORM_VEC), 0);
	if (fov < 0.0 || fov > 180.0)
		return (puterror(ERR_FOV), 0);
	scene->cam.origin = origin;
	set_cam_vectors(scene, fwd, fov);
	return (1);
}

int	parse_light(t_scene *scene, char **tokens)
{
	t_light	*light;
	double	ratio;
	t_vec3	color;
	t_vec3	origin;

	if (*(scene->light_lst) != NULL)
		return (puterror(ERR_DUP_LIG), 0);
	if (ptrptr_count((void **)tokens) != 4)
		return (puterror(ERR_PARAMS), 0);
	if (!parse_vec3(tokens[1], &origin))
		return (puterror(ERR_VEC), 0);
	if (!ft_atof(tokens[2], &ratio) || ratio < 0.0 || ratio > 1.0)
		return (puterror(ERR_RATIO), 0);
	if (!parse_color(tokens[3], &color))
		return (puterror(ERR_COLOR), 0);
	light = malloc(sizeof(t_light));
	if (!light)
		return (puterror(ERR_MALLOC), 0);
	light->origin = origin;
	light->color = mult_by_k_vec(color, ratio);
	ft_lstadd_back(scene->light_lst, ft_lstnew(light));
	return (1);
}
