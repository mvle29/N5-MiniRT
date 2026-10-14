/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_scene.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:14:19 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 15:14:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_SCENE_H
# define TYPE_SCENE_H

#include "type_libft.h"
#include "type_vec.h"
#include "type_shape.h"
#include "type_mesh.h"

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
	int	t;
}	t_color;

typedef struct	s_cam
{
	t_vec3	origin;
	t_vec3	fwd;
	t_vec3	right;
	t_vec3	up;
}	t_cam;

typedef struct	s_light
{
	t_vec3	origin;
	t_vec3	color;
}	t_light;

typedef struct	s_object
{
	t_vec3	origin;
	double	coeff;
	t_shape	shape; // forme geometrique predeterminee (plan, triangle, sphere, cylindre)
	t_mesh	mesh;  //.obj file
	double	transparency;
	double	reflectivity;
	t_vec3	color;
}	t_object;

typedef struct	s_scene
{
	t_list	**obj_lst;
	t_list	**light_lst;
	t_cam	cam;
	t_vec3	ambient_color;
	t_vec3	sky_color;
	t_vec3	floor_color;
}	t_scene;

#endif
