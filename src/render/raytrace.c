/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:03:20 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 16:03:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_render.h"
#include "fn_math.h"
#include "cste_miniRT.h"
// ou shoot ray ?

void	raytrace(t_vec2 screen_coord, t_vec2 screen_max, t_engine *engine, int *pixel)
{
	t_ray3	ray_vec;
	t_vec2	screen_vec;
	//t_color	pixel_color;

	screen_vec.x = change_interval(screen_coord.x, (double[2]){0.0, screen_max.x}, (double[2]){-1.0, 1.0});
	screen_vec.y = change_interval(screen_coord.y, (double[2]){0.0, screen_max.y}, (double[2]){1.0, -1.0});
	build_first_rayvec(&ray_vec, screen_vec, &(engine->scene.cam));
	//P(t) = O + t * ray
	*pixel = 0;
	shoot_ray_recursive(&(engine->scene), ray_vec, pixel, RT_LIMIT);
	(void)screen_coord;
	(void)screen_max;
}
