/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:50:28 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 15:50:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_init.h"

int	init_mlx(t_mlx *mlx, t_mlx_img *cur, t_mlx_img *next)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_w, mlx->win_h,
			"miniRT :p");
	if (!mlx->win)
		return (0);
	cur->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
	next->img = mlx_new_image(mlx->mlx, mlx->win_w, mlx->win_h);
	if (!cur->img || !next->img)
		return (0);
	cur->addr = mlx_get_data_addr(cur->img, &cur->bpp, &cur->ll,
			&cur->endian);
	next->addr = mlx_get_data_addr(next->img, &next->bpp, &next->ll,
			&next->endian);
	cur->mlx = mlx;
	next->mlx = mlx;
	return (1);
}
