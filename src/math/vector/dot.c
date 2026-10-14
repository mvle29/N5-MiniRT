/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:26:11 by marvin            #+#    #+#             */
/*   Updated: 2026/10/07 22:26:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_vector.h"

double	dot(t_vec3 u, t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}
// scalar return the area of the rectangle produced by u x v (produit vectoriel)
