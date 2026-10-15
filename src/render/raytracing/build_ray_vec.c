/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_ray_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 23:30:08 by marvin            #+#    #+#             */
/*   Updated: 2026/10/07 23:30:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_render.h"
#include "fn_math.h"
#include "cste_miniRT.h"

/*
screen_vec.x va de -1 à 1 : il indique la position du pixel en proportion, du bord gauche au bord droit.
Le multiplier par scale convertit cette proportion en position réelle sur l'écran virtuel, entre -tan(fov/2) et +tan(fov/2)*/

void	build_first_rayvec(t_ray3 *ray, t_vec2 screen_ratio, t_cam *cam)
{
	t_vec2	screen_vec;

	screen_vec.x = screen_ratio.x * cam->half_screen_len.x;
	screen_vec.y = screen_ratio.y * cam->half_screen_len.y;
	ray->vec = add_vec(add_vec(cam->fwd, mult_by_k_vec(cam->right, screen_vec.x)),
	mult_by_k_vec(cam->up, screen_vec.y));
	ray->vec = normalize(ray->vec);
	ray->origin = cam->origin;
}
void	build_next_ray(t_ray3 *next_ray)
{
	(void)next_ray;
	return;
}
