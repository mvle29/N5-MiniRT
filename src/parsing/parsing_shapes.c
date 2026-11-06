/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:02:45 by grivault          #+#    #+#             */
/*   Updated: 2026/11/02 20:58:33 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_scene.h"
#include "fn_math.h"
#include "fn_shape.h"
#include "libft.h"

int parse_sphere(t_scene *scene, char **tokens)
{
	t_object	*obj;
	double		diameter;

	if (ptrptr_count((void **)tokens) != 4)
		return (0);
	obj = malloc(sizeof(t_object));
	if (!obj)
		return (0); //error malloc
	ft_memset(obj, 0, sizeof(t_object));
	if (!parse_vec3(tokens[1], &obj->origin) || !ft_atof(tokens[2], &diameter)
			|| !parse_color(tokens[3], &obj->color))
		return (free(obj), 0);
	obj->shape.type = SPHERE;
	obj->shape.data.sphere.diameter = diameter;
	obj->shape.is_in_shape = is_in_sphere;
	obj->shape.get_surface_normal = get_sphere_normal;
	ft_lstadd_back(scene->obj_lst, ft_lstnew(obj));
	return (1);
}

int parse_plane(t_scene *scene, char **tokens)
{
	t_object	*obj;
	t_vec3		normal;

	if (ptrptr_count((void **)tokens) != 4)
		return (0);
	obj = malloc(sizeof(t_object));
	if (!obj)
		return (0); // error malloc
	ft_memset(obj, 0, sizeof(t_object));
	if (!parse_vec3(tokens[1], &obj->origin) || !parse_vec3(tokens[2], &normal)
			|| !parse_color(tokens[3], &obj->color))
		return (free(obj), 0);
	if (normal.x < -1.0 || normal.x > 1.0 || normal.y < -1.0 || normal.y > 1.0
			|| normal.z < -1.0 || normal.z > 1.0)
		return (free(obj), 0);
	obj->shape.type = PLANE;
	obj->shape.data.plane.normal = normalize(normal);
	obj->shape.is_in_shape = is_in_plane;
	obj->shape.get_surface_normal = get_plane_normal;
	ft_lstadd_back(scene->obj_lst, ft_lstnew(obj));
	return (1);
}

int parse_cylinder(t_scene *scene, char **tokens)
{
	t_object	*obj;
	t_vec3		axis;
	double		diameter;
	double		height;

	if (ptrptr_count((void **)tokens) != 6)
		return (0);
	obj = malloc(sizeof(t_object));
	if (!obj)
		return (0); //error malloc
	ft_memset(obj, 0, sizeof(t_object));
	if (!parse_vec3(tokens[1], &obj->origin) || !parse_vec3(tokens[2], &axis)
			|| !ft_atof(tokens[3], &diameter) || !ft_atof(tokens[4], &height)
			|| !parse_color(tokens[5], &obj->color))
		return (free(obj), 0);
	if (axis.x < -1.0 || axis.x > 1.0 || axis.y < -1.0 || axis.y > 1.0
			|| axis.z < -1.0 || axis.z > 1.0)
		return (free(obj), 0);
	obj->shape.type = CYLINDER;
	obj->shape.data.cylinder.leader_vec = normalize(axis);
	obj->shape.data.cylinder.diameter = diameter;
	obj->shape.data.cylinder.height = height;
	obj->shape.is_in_shape = is_in_cylinder;
	obj->shape.get_surface_normal = get_cylinder_normal;
	ft_lstadd_back(scene->obj_lst, ft_lstnew(obj));
	return (1);
}
