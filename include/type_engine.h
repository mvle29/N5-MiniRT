/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_engine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:11:55 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 15:11:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_ENGINE_H
# define TYPE_ENGINE_H

#include "type_scene.h"
#include "type_mlx.h"
#include "type_vec.h"

typedef struct s_params
{
	t_vec3	fwd;
}	t_params;

typedef struct s_engine
{
	t_scene		scene;
	t_mlx_img	cur;
	t_mlx_img	next;
	t_mlx		mlx;
	t_params	params;
}	t_engine;

#endif
