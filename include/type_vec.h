/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_math.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:34:55 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 15:34:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_MATH_H
#define TYPE_MATH_H

typedef struct s_vec3
{
	union
	{
		struct
		{
			double x;
			double y;
			double z;
		};
		struct
		{
			double r;
			double g;
			double b;
		};
	};
}	t_vec3;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_ray3
{
	t_vec3	origin;
	t_vec3	vec;
}	t_ray3;

#endif
