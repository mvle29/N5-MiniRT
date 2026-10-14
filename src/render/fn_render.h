/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:03:07 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 16:03:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_RENDER_H
# define FN_RENDER_H

#include "type_engine.h"

void		raytrace(t_vec2 screen_coord, t_vec2 screen_max, t_engine *engine, int *pixel);

int			shoot_ray_recursive(t_scene *scene, t_ray3 ray, int *color, int lim);

void		build_first_rayvec(t_ray3 *vec, t_vec2 screen_vec, t_cam *cam);

t_object	*get_closest_object(t_scene *scene, t_ray3 ray, t_vec3 *intersect);
int			get_color(t_scene *scene, t_ray3 ray, t_object *closest, t_vec3 intersect);
int			vec3_to_int_color(t_vec3 color);

void		swap_images(t_engine *engine);
void		my_pixel_put(t_mlx_img *img, t_vec2 pixel, int color);

#endif
