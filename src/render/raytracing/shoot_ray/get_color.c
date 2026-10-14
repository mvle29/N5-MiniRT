/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:00:14 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 17:00:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_render.h"
#include "fn_math.h"
#include "cste_miniRT.h"


int	in_shadow(t_scene *scene, t_ray3 light_ray, t_vec3 light_origin, t_vec3 normal)
{
	double		coeff;
	t_object	*closest;

	coeff = dot(sub_vec(light_origin, light_ray.origin), normalize(light_ray.vec));
	light_ray.origin = add_vec(light_ray.origin, mult_by_k_vec(normal, EPSILON));
	light_ray.vec = normalize(light_ray.vec);
	closest = get_closest_object(scene, light_ray, NULL);
	if (closest && closest->coeff < coeff)
		return (1);
	return (0);
}

t_vec3	get_light_lvl(t_scene *scene, t_light *light, t_vec3 normal, t_vec3 intersect)
{
	t_vec3	light_lvl;
	t_ray3	light_ray;
	double	diff;

	light_lvl = (t_vec3){0.0, 0.0, 0.0};
	light_ray.vec = sub_vec(light->origin, intersect);
	light_ray.origin = intersect;
	diff = max(0.0, dot(normal, normalize(light_ray.vec)));
	if (diff > 0.0 && !in_shadow(scene, light_ray, light->origin, normal))
		light_lvl = mult_by_k_vec(light->color, diff);
	return (light_lvl);
}

t_vec3	get_light_sum(t_scene *scene, t_vec3 normal, t_vec3 intersect)
{
	t_list	*light;
	t_vec3	light_sum;

	light = *(scene->light_lst);
	light_sum = scene->ambient_color;
	while (light)
	{
		light_sum = add_vec(light_sum, get_light_lvl(scene, (t_light*)(light->content), normal, intersect));
		light_sum = (t_vec3){min(255.0, light_sum.x), min(255.0, light_sum.y), min(255.0, light_sum.z)};
		light = light->next;
	}
	return (mult_by_k_vec(light_sum, 1.0/255.0));
}

int	vec3_to_int_color(t_vec3 color)
{
	int	r;
	int	g;
	int b;

	r = (int)(color.x);
	g = (int)(color.y);
	b = (int)(color.z);
	return (r << 16 | g << 8 | b);
}

int	get_color(t_scene *scene, t_ray3 ray, t_object *closest, t_vec3 intersect)
{
	t_vec3	light_sum;
	t_vec3	surface_normal;
	t_vec3	color;

	surface_normal = closest->shape.get_surface_normal(intersect, &(closest->shape), closest->origin);
	if (dot(ray.vec, surface_normal) > 0.0)
		surface_normal = mult_by_k_vec(surface_normal, -1.0);
	light_sum = get_light_sum(scene, surface_normal, intersect);
	color.x = closest->color.x * light_sum.x;
	color.y = closest->color.y * light_sum.y;
	color.z = closest->color.z * light_sum.z;
	//(void)scene;
	//(void)ray;
	return (vec3_to_int_color(color));
}

/* pour avoir la couleur finale, on a besoin :
 - de construire la normale a notre shape en notre point d intersection (O + ray * obj->coeff)
 - de construire le ou les rayons qui vont vers mes light
 - d établir leur poids dans la couleur finale : si le vecteur est ombrage ne pas compter etc
 - a la fin, d'additionner ttes les light
 - faire light x chaque composante rgb de notre objet
 - transformer en un int qui concatene ttes les infos*/

int	mix_colors(int col1)
{
	return (col1);
}
