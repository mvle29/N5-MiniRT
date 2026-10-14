/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:14:09 by marvin            #+#    #+#             */
/*   Updated: 2026/10/09 18:14:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_VECTOR_H
# define FN_VECTOR_H

#include "type_vec.h"

t_vec3	vec_product(t_vec3 u, t_vec3 v, int invert);
double	projection(t_vec3 u, t_vec3 v);
t_vec3	normalize(t_vec3 u);
double	dot(t_vec3 u, t_vec3 v);
t_vec3	build_vec3(double x, double y, double z);

double	vec_norm(t_vec3 u);
t_vec3	mult_by_k_vec(t_vec3 u, double k);
t_vec3	sub_vec(t_vec3 u, t_vec3 v);
t_vec3	add_vec(t_vec3 u, t_vec3 v);

#endif
