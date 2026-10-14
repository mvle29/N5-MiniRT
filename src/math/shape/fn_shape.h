/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_shape.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:55:31 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 15:55:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_SHAPE_H
# define FN_SHAPE_H

#include "type_vec.h"
#include "type_shape.h"

int	is_in_shape(t_ray3 *ray, void *shape, t_vec3 shape_origin, double *soluces);

int	is_in_plane(t_ray3 *ray, t_shape *plane, t_vec3 shape_origin, double *soluces);
int	is_in_triangle(t_ray3 *ray, t_shape *triangle, t_vec3 shape_origin, double *soluces);
int	is_in_sphere(t_ray3 *ray, t_shape *sphere, t_vec3 shape_origin, double *soluces);
int	is_in_cylinder(t_ray3 *ray, t_shape *cylinder, t_vec3 shape_origin, double *soluces);

t_vec3	get_surface_normal(t_vec3 point, t_shape *shape, t_vec3 shape_origin);

t_vec3	get_sphere_normal(t_vec3 point, t_shape *shape, t_vec3 shape_origin);
t_vec3	get_triangle_normal(t_vec3 point, t_shape *shape, t_vec3 shape_origin);
t_vec3	get_cylinder_normal(t_vec3 point, t_shape *shape, t_vec3 shape_origin);
t_vec3	get_plane_normal(t_vec3 point, t_shape *shape, t_vec3 shape_origin);

#endif
