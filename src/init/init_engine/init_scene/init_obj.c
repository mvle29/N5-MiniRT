/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:51:36 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 15:51:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fn_init.h"
#include "fn_math.h"

t_object	*init_obj(t_vec3 color, t_vec3 origin, int diameter)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	ft_memset(obj, 0, sizeof(t_object));
	obj->color = color;
	obj->origin = origin;
	obj->shape.type = SPHERE;
	obj->shape.data.sphere.diameter = diameter;
	obj->shape.is_in_shape = is_in_sphere;
	obj->shape.get_surface_normal = get_sphere_normal;
	return (obj);
}

int	init_obj_lst(t_scene *scene)
{
	scene->obj_lst = malloc(sizeof(t_list*));
	if (!scene->obj_lst)
		return (0);
	*(scene->obj_lst) = ft_lstnew(init_obj((t_vec3){139.0, 5.0, 10.0}, (t_vec3){0.0, 2.0, 3.0}, 2.0));
	ft_lstadd_front(scene->obj_lst, ft_lstnew(init_obj((t_vec3){5.0, 139.0, 10.0}, (t_vec3){0.0, 0.0, 3.0}, 2.0)));
	if (!*(scene->obj_lst))
		return (0);
	return (1);
}
