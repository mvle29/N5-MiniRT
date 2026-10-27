/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_surface_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 02:33:16 by marvin            #+#    #+#             */
/*   Updated: 2026/10/14 02:33:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_math.h"

t_vec3	get_sphere_normal(t_vec3 point, t_shape *shape, t_vec3 shape_origin)
{
	t_vec3	res;

	(void)shape;
	res = normalize(sub_vec(point, shape_origin));
	return (res);
}

t_vec3	get_plane_normal(t_vec3 point, t_shape *shape, t_vec3 shape_origin)
{
	(void)point;
	(void)shape_origin;
	return (shape->data.plane.normal);
}
