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

void	build_first_rayvec(t_ray3 *ray, t_vec2 screen_vec, t_cam *cam)
{
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
