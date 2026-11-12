/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:48:46 by marvin            #+#    #+#             */
/*   Updated: 2026/11/09 14:16:26 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_init.h"
#include "fn_end.h"
#include "libft.h"
#include <stdio.h>
#include "cste_miniRT.h"
#include "cste_errors.h"
#include "fn_errors.h"

/*
int	init_engine(t_engine *engine)
{
	ft_memset(engine, 0, sizeof(t_engine));
	engine->mlx.win_h = WIN_H;
	engine->mlx.win_w = WIN_W;
	if (!init_scene(&(engine->scene)))
	{
		end_program(engine);
		printf("Couldnt init scene");
	}
	else if (!init_mlx(&(engine->mlx), &(engine->cur), &(engine->next)))
	{
		end_program(engine);
		printf("Couldnt init mlx");
	}
	else
		return (1);
	return (0);
}
*/

int	init_engine(t_engine *engine, char *filename)
{
	ft_memset(engine, 0, sizeof(t_engine));
	engine->mlx.win_h = WIN_H;
	engine->mlx.win_w = WIN_W;
	if (!init_scene(&(engine->scene), filename))
		return (end_program(engine), 0);
	if (!init_mlx(&(engine->mlx), &(engine->cur), &(engine->next)))
		return (end_program(engine), puterror("Failed to init MLX"), 0);
	return (1);
}
