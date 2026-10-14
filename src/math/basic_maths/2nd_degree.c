/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2nd_degree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:53:39 by marvin            #+#    #+#             */
/*   Updated: 2026/10/08 16:53:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	get_2nd_degree_soluce(double a, double b, double c, double *soluce)
{
	double	delta;

	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	else if (delta == 0.0)
	{
		soluce[0] = -b / (2 * a);
		return (1);
	}
	else
	{
		soluce[0] = (-b - sqrt(delta)) / (2 * a);
		soluce[1] = (-b + sqrt(delta)) / (2 * a);
		return (2);
	}
}
