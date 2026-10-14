/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:14:40 by marvin            #+#    #+#             */
/*   Updated: 2026/10/09 18:14:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FN_BASIC_MATH_H
# define FN_BASIC_MATH_H

#include <math.h>

double	change_interval(double n, double *old_interval, double *new_interval);
int		get_2nd_degree_soluce(double a, double b, double c, double *soluce);
double	max(double a, double b);
double	min(double a, double b);

#endif
