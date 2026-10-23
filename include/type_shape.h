/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_shape.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:35:21 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 15:35:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_SHAPE_H
#define TYPE_SHAPE_H

typedef struct s_sphere
{
	double	diameter;
}	t_sphere;

typedef struct	s_triangle
{
	double	a;
	double	b;
	double	c;
}	t_triangle;

typedef struct s_plane
{
	t_vec3	normal;
}	t_plane;

typedef struct s_cylinder
{
	t_vec3	leader_vec; // droite directrice
	double	diameter;
	double	height;
}	t_cylinder;

enum e_type // enum a surpprimer si non utilisee dans parsing
{
	SPHERE,
	PLANE,
	CYLINDER,
	TRIANGLE,
};

typedef union
{
	t_sphere	sphere;
	t_cylinder	cylinder;
	t_plane		plane;
	t_triangle	triangle;
}	u_shape;

typedef struct s_shape t_shape;

typedef struct s_shape
{
	enum e_type		type;
	u_shape			data;
	int				(*is_in_shape) (t_ray3 *ray, t_shape *shape, t_vec3 shape_origin, double *soluces);
	t_vec3			(*get_surface_normal) (t_vec3 point, t_shape *shape, t_vec3 shape_origin);
}	t_shape;

#endif
