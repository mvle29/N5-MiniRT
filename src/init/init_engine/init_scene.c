/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:48:57 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 15:48:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fn_init.h"
#include "fn_math.h"

void	init_cam(t_cam *cam)
{
	cam->origin = build_vec3(0.0, 1.0, 0.0);
	cam->up = normalize(build_vec3(0.0, 1.0, 0.0));
	cam->fwd = normalize(build_vec3(0.0, 0.0, 1.0));
	cam->right = normalize(vec_product(cam->up, cam->fwd, 0));
}

int	init_scene(t_scene *scene)
{
	ft_memset(scene, 0, sizeof(t_scene));
	scene->ambient_color = build_vec3(105.0, 90.0, 25.0);
	scene->sky_color = build_vec3(173.0, 216.0, 230.0);
	scene->floor_color = build_vec3(0.0, 0.0, 0.0);
	init_cam(&(scene->cam));
	if (!init_light_lst(scene) || !init_obj_lst(scene))
		return (0);
	return (1);
}
