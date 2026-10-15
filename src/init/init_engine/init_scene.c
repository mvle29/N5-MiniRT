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
#include "cste_miniRT.h"

void	init_cam(t_cam *cam)
{
	double	half_fov_deg;
	double	half_fov_rad;

	cam->origin = (t_vec3){.x = 0.0, .y = 1.0, .z = 0.0}; // valeur arbitraire, a changer (parsing)
	cam->up = normalize((t_vec3){.x = 0.0, .y = 1.0, .z = 0.0}); // parsing : cas limite : si fwd mm valeurs que up
	cam->fwd = normalize((t_vec3){.x = 0.0, .y = 0.0, .z = 1.0}); // parsing
	cam->right = normalize(vec_product(cam->up, cam->fwd, 0));
	cam->fov = 90; // parsing : min = 0, max = 180
	half_fov_deg = cam->fov / 2.0;
	half_fov_rad = half_fov_deg * M_PI / 180.0;
	cam->half_screen_len.x = tan(half_fov_rad);
	cam->half_screen_len.y = cam->half_screen_len.x * WIN_H / WIN_W;
}

int	init_scene(t_scene *scene)
{
	ft_memset(scene, 0, sizeof(t_scene));
	scene->ambient_color = (t_vec3){.r = 105.0, .g = 90.0, .b = 25.0}; // parsing
	scene->sky_color = (t_vec3){.r = 173.0, .g = 216.0, .b = 230.0}; // parsing
	init_cam(&(scene->cam));
	if (!init_light_lst(scene) || !init_obj_lst(scene)) // init lst parsing
		return (0);
	return (1);
}
