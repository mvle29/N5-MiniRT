/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:00:22 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 16:00:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fn_init.h"
#include "fn_math.h"

t_light	*init_light(t_vec3 color, t_vec3 origin)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	ft_memset(light, 0, sizeof(t_light));
	light->color = color;
	light->origin = origin;
	return (light);
}

int	init_light_lst(t_scene *scene)
{
	scene->light_lst = malloc(sizeof(t_list*));
	if (!scene->light_lst)
		return (0);
	*(scene->light_lst) = ft_lstnew(init_light(build_vec3(255.0, 255.0, 255.0), build_vec3(0.0, 7.0, 3.0)));
	if (!*(scene->light_lst))
		return (0);
	return (1);
}
