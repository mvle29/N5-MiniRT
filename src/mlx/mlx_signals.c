/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:59:26 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 17:59:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_end.h"
#include "fn_render.h"
#include "fn_mlx.h"

int	key_hook(int keycode, t_engine *data)
{
	if (keycode == XK_Escape)
		exit_program(data);
	return (0);
}

void	mlx_signals(t_engine *data)
{
	mlx_hook(data->mlx.win, DestroyNotify, ButtonPressMask, exit_program, data);
	mlx_key_hook(data->mlx.win, key_hook, data);
	mlx_loop_hook(data->mlx.mlx, mlx_render, data);
}
