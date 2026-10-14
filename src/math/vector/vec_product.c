/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:29:35 by marvin            #+#    #+#             */
/*   Updated: 2026/10/07 22:29:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_vector.h"

t_vec3	vec_product(t_vec3 u, t_vec3 v, int invert)
{
	t_vec3	product;

	product.x = u.y * v.z - u.z * v.y;
	product.y = u.z * v.x - u.x * v.z;
	product.z = u.x * v.y - u.y * v.x;
	(void)invert;
	return (product);
}
// attention : u x v != v x u
// si on souhaite inverser et obtenir le resultat de v x u en envoyant
// u et v en parametre, invert doit alors etre set a 1.
// Toute autre valeur sera ignoree.
