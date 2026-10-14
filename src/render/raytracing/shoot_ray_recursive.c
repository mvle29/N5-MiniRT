/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shoot_ray_recursive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:12:32 by marvin            #+#    #+#             */
/*   Updated: 2026/10/07 22:12:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_render.h"

int	shoot_ray_recursive(t_scene *scene, t_ray3 ray, int *color, int lim)
{
	t_object	*closest;
	t_vec3		intersect;
	//t_ray3		next_ray;

	closest = get_closest_object(scene, ray, &intersect);
	if (!closest)
	{
		*color = vec3_to_int_color(scene->sky_color);
		return (0);
	}
	else
	{
		if (lim == 1)
		{

			*color = get_color(scene, ray, closest, intersect);
		}
		/*else
		{
			build_next_rayvec(&next_ray);
			if (shoot_ray_recursive(scene, &next_ray, color, lim - 1))
				*color = mix_colors(*color, get_color(scene, ray, closest));
			else
				*color = get_color(scene, ray_origin, ray_vec, closest);
		}*/
	}
	return (1);
}
