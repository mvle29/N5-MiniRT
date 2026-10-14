/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:35:54 by marvin            #+#    #+#             */
/*   Updated: 2026/10/07 22:35:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_vector.h"

double	projection(t_vec3 u, t_vec3 v)
{
	double len = vec_norm(v);

	if (len < 1e-8)
		return (0.0);
	return (dot(u, v) / len);
}
