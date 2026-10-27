/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:10:13 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 17:10:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_math.h"
#include "cste_miniRT.h"

int	is_in_sphere(t_ray3 *ray, t_shape *sphere, t_vec3 sphere_origin, double *soluces)
{
	t_vec3	eq;
	double	r;
	int		nb_soluces;

	r = sphere->data.sphere.diameter / 2;
	eq.x = vec_norm(ray->vec) * vec_norm(ray->vec);
	eq.y = 2 * (dot(sub_vec(ray->origin, sphere_origin), ray->vec));
	eq.z = vec_norm(sub_vec(ray->origin, sphere_origin)) * vec_norm(sub_vec(ray->origin, sphere_origin)) - r * r;
	nb_soluces = get_2nd_degree_soluce(eq.x, eq.y, eq.z, soluces);
	if (nb_soluces == 0)
		return (0);
	else if (nb_soluces == 1)
		return (1);
	return (2);
}

int	is_in_plane(t_ray3 *ray, t_shape *plane, t_vec3 plane_origin, double *soluces)
{
	double	denom;

	denom = dot(ray->vec, plane->data.plane.normal);
	if (fabs(denom) == 0.0)
	{
		if (fabs(dot(sub_vec(plane_origin, ray->origin), ray->vec)) == 1.0)
		{
			soluces[0] = DBL_MIN;
			soluces[1] = DBL_MAX;
			return (3);
		}
		return (0);
	}
	soluces[0] = dot(sub_vec(plane_origin, ray->origin), plane->data.plane.normal) / denom;
	if (soluces[0] < 0.0)
		return (0);
	return (1);
}

//o - p donne le vecteur PO .
//si p est dans la sphere, PO a la meme longueur que le rayon de la sphere
// (ou diametre / 2)
//
