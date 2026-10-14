/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:01:38 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 16:01:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fn_end.h"

void	end_scene(t_scene *scene)
{
	if (scene)
	{
		if (scene->light_lst)
			ft_lstclear(scene->light_lst, free);
		if (scene->obj_lst)
			ft_lstclear(scene->obj_lst, free);
	}
}

void	end_mlx(t_mlx *mlx, t_mlx_img *cur, t_mlx_img *next)
{

	if (cur && mlx && cur->img && mlx->mlx)
	{
		mlx_destroy_image(mlx->mlx, cur->img);
		cur->img = 0;
	}
	if (next && mlx && next->img && mlx->mlx)
	{
		mlx_destroy_image(mlx->mlx, next->img);
		next->img = 0;
	}
	if (mlx && mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx && mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		mlx->mlx = 0;
	}
}

int	end_program(t_engine *data)
{
	end_scene(&(data->scene));
	end_mlx(&(data->mlx), &(data->cur), &(data->next));
	return (0);
}

int	exit_program(t_engine *data)
{
	end_scene(&(data->scene));
	end_mlx(&(data->mlx), &(data->cur), &(data->next));
	exit(0);
}
