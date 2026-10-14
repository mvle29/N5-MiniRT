/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_end.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:56:24 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 15:56:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_END_H
# define FN_END_H

#include "type_engine.h"


int		exit_program(t_engine *data);
int		end_program(t_engine *data);
void	end_mlx(t_mlx *mlx, t_mlx_img *cur, t_mlx_img *next);
void	end_scene(t_scene *scene);

#endif
