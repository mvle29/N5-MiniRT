/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 18:03:26 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 18:03:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_mlx.h"

void	my_pixel_put(t_mlx_img *img, t_vec2 pixel, int color)
{
	char	*addr;

	addr = img->addr + (((int)(pixel.x)*(img->bpp / 8)
				+ (int)(pixel.y)*img->ll));
	*(int *)addr = color;
}

void	swap_images(t_engine *engine)
{
	t_mlx_img	tmp;

	tmp = engine->cur;
	engine->cur = engine->next;
	engine->next = tmp;
	mlx_put_image_to_window(engine->mlx.mlx, engine->mlx.win, engine->cur.img, 0, 0);
}
