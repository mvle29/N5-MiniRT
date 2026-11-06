/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fn_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 15:12:42 by grivault          #+#    #+#             */
/*   Updated: 2026/11/06 18:00:07 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_PARSING_H
# define FN_PARSING_H

# include "type_scene.h"
# include "fn_errors.h"
# include "cste_errors.h"
# include "cste_parsing_errors.h"

int	parse_rt_file(t_scene *scene, char *filename);

int	parse_ambient(t_scene *scene, char **tokens);
int	parse_camera(t_scene *scene, char **tokens);
int	parse_light(t_scene *scene, char **tokens);

int	parse_sphere(t_scene *scene, char **tokens);
int	parse_plane(t_scene *scene, char **tokens);
int	parse_cylinder(t_scene *scene, char **tokens);

int	ft_atof(const char *str, double *out);
int	parse_vec3(char *str, t_vec3 *out);
int	parse_color(char *str, t_vec3 *out);

#endif
