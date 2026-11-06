/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:59:46 by grivault          #+#    #+#             */
/*   Updated: 2026/11/02 20:59:55 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_scene.h"
#include "fn_math.h"
#include "cste_miniRT.h"
#include "libft.h"

int parse_ambient(t_scene *scene, char **tokens)
{
	double	ratio;
	t_vec3	color;

	if (ptrptr_count((void **)tokens) != 3)
		return (0);
	if (!ft_atof(tokens[1], &ratio) || ratio < 0.0 || ratio > 1.0)
		return (0);
	if (!parse_color(tokens[2], &color))
		return (0);
	scene->ambient_color = mult_by_k_vec(color, ratio);
	return (1);
}

int parse_camera(t_scene *scene, char **tokens)
{
	t_vec3	origin;
	t_vec3	fwd;
	double	fov;
	double	half_fov_rad;

	if (ptrptr_count((void **)tokens) != 4)
		return (0);
	if (!parse_vec3(tokens[1], &origin) || !parse_vec3(tokens[2], &fwd) || !ft_atof(tokens[3], &fov))
		return (0);
	if (fwd.x < -1.0 || fwd.x > 1.0 || fwd.y < -1.0 || fwd.y > 1.0 || fwd.z < -1.0 || fwd.z > 1.0)
		return (0);
	if (fov < 0.0 || fov > 180.0)
		return (0);
	scene->cam.origin = origin;
	scene->cam.fwd = normalize(fwd);
	if (scene->cam.fwd.x == 0.0 && scene->cam.fwd.z == 0.0 && (scene->cam.fwd.y == 1.0 || scene->cam.fwd.y == -1.0))
		scene->cam.up = normalize((t_vec3){.x = 0.0, .y = 0.0, .z = -scene->cam.fwd.y});
	else
		scene->cam.up = normalize((t_vec3){.x = 0.0, .y = 1.0, .z = 0.0});
	scene->cam.right = normalize(vec_product(scene->cam.up, scene->cam.fwd, 0));
	scene->cam.up = normalize(vec_product(scene->cam.fwd, scene->cam.right, 0));
	scene->cam.fov = fov;
	half_fov_rad = (fov / 2.0) * M_PI / 180.0;
	scene->cam.half_screen_len.x = tan(half_fov_rad);
	scene->cam.half_screen_len.y = scene->cam.half_screen_len.x * WIN_H / WIN_W;
	return (1);
}

int parse_light(t_scene *scene, char **tokens)
{
	t_light	*light;
	double	ratio;
	t_vec3	color;
	t_vec3	origin;

	if (ptrptr_count((void **)tokens) != 4)
		return (0);
	if (!parse_vec3(tokens[1], &origin) || !ft_atof(tokens[2], &ratio) || ratio < 0.0 || ratio > 1.0)
		return (0);
	if (!parse_color(tokens[3], &color))
		return (0);
	light = malloc(sizeof(t_light));
	if (!light)
		return (0);
	light->origin = origin;
	light->color = mult_by_k_vec(color, ratio);
	ft_lstadd_back(scene->light_lst, ft_lstnew(light));
	return (1);
}
