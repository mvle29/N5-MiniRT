/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 18:04:29 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 18:04:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_mlx.h"
#include "fn_render.h"

int	mlx_render(void *data)
{
	t_engine	*engine;
	t_vec2		screen_coord;
	t_vec2		screen_max;
	int			pixel;

	engine = (t_engine*)data;
	screen_max.y = engine->mlx.win_h;
	screen_max.x = engine->mlx.win_w;
	screen_coord.y = 0;
	while (screen_coord.y < screen_max.y)
	{
		screen_coord.x = 0;
		while (screen_coord.x < screen_max.x)
		{
			raytrace(screen_coord, screen_max, engine, &pixel); // src/render/raytrace.c
			my_pixel_put(&(engine->next), screen_coord, pixel);
			screen_coord.x++;
		}
		screen_coord.y++;
	}
	swap_images(engine);
	return (1);
}
