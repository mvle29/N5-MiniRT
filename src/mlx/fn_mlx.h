/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 18:05:02 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 18:05:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_MLX_H
# define FN_MLH_H

#include "type_engine.h"

void	swap_images(t_engine *engine);
void	my_pixel_put(t_mlx_img *img, t_vec2 pixel, int color);
int		mlx_render(t_engine *engine);
void	mlx_signals(t_engine *data);

#endif
