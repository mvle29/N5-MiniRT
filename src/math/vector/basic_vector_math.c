/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_vector_math.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:58:04 by marvin            #+#    #+#             */
/*   Updated: 2026/10/07 22:58:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_vector.h"
#include <math.h>

t_vec3	add_vec(t_vec3 u, t_vec3 v)
{
	return((t_vec3){u.x + v.x, u.y + v.y, u.z + v.z});
}

t_vec3	sub_vec(t_vec3 u, t_vec3 v)
{
	return((t_vec3){u.x - v.x, u.y - v.y, u.z - v.z});
}

t_vec3	mult_by_k_vec(t_vec3 u, double k)
{
	return((t_vec3){u.x * k, u.y * k, u.z * k});
}

double	vec_norm(t_vec3 u)
{
	return(sqrt(u.x * u.x + u.y * u.y + u.z * u.z));
}
