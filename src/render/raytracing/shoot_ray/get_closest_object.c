/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:15:41 by marvin            #+#    #+#             */
/*   Updated: 2026/10/07 22:15:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_render.h"
#include "fn_math.h"

int	valid_intersection(t_object *obj, t_ray3 ray)
{
	double	soluces[2];
	int		nb_soluces;

	nb_soluces = obj->shape.is_in_shape(&ray, &(obj->shape), obj->origin, soluces);
	if (nb_soluces == 0)
		return (0);
	else if (nb_soluces == 1 && soluces[0] > 0)
	{
		obj->coeff = soluces[0];
		return (1);
	}
	else if (nb_soluces == 2 && !(soluces[0] < 0 && soluces[1] < 0))
	{
		if (soluces[0] < 0)
			obj->coeff = soluces[1];
		else if (soluces[1] < 0)
			obj->coeff = soluces[0];
		else if (soluces[1] < soluces[0])
			obj->coeff = soluces[1];
		else
			obj->coeff = soluces[0];
		return (1);
	}
	return (0);
}

static int	is_closest(t_object *obj, t_object *to_cmp)
{
	if (obj->coeff < to_cmp->coeff)
		return (1);
	return (0);
}

t_object	*get_closest_object(t_scene *scene, t_ray3 ray, t_vec3 *intersect)
{
	t_list		*obj_lst;
	t_object	*closest;

	obj_lst = *(scene->obj_lst);
	closest = NULL;
	while (obj_lst)
	{
		if (valid_intersection((t_object*)(obj_lst->content), ray) &&
			(!closest || is_closest((t_object*)(obj_lst->content), closest)))
			closest = (t_object*)(obj_lst->content);
		obj_lst = obj_lst->next;
	}
	if (closest && intersect)
		*intersect = add_vec(ray.origin, mult_by_k_vec(ray.vec, closest->coeff));
	return(closest);
}
