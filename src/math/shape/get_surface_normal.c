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

// A corriger : get_..._normal ne doit pas recevoir t_shape *shape mais u_shape direct (bc d info inutiles)
// aussi transmettre peut etre uniquement des pointeurs pour optimisation.
// idem pour is_in_shape.

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

t_vec3	get_cylinder_normal(t_vec3 point, t_shape *shape, t_vec3 shape_origin)
{
	t_vec3	op;
	t_vec3	op_prime;
	t_vec3	p_primep;
	double	op_prime_height;

	op = sub_vec(point, shape_origin);
	op_prime_height = dot(op, shape->data.cylinder.leader_vec);
	if (op_prime_height >= shape->data.cylinder.height / 2.0)
		return (shape->data.cylinder.leader_vec);
	if (-op_prime_height >= shape->data.cylinder.height / 2.0)
		return (mult_by_k_vec(shape->data.cylinder.leader_vec, -1));
	op_prime = mult_by_k_vec(shape->data.cylinder.leader_vec, op_prime_height);
	p_primemp = sub_vec(op, op_prime);
	return (normalize(p_primep));
}
/*
op = vec qui va de shape origin à point
op_prime correspond au vecteur qui part de shape origin et arrive sur le point p reporte sur la droite directrice du cylindre.
->composantes leader vec presentes dans op
*/
