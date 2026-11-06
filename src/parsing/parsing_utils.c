/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:58:58 by grivault          #+#    #+#             */
/*   Updated: 2026/11/06 18:07:22 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "type_vec.h"
#include <stdlib.h>

int ft_atof(const char *str, double *out)
{
	double	res = 0.0;
	double	fraction = 1.0;
	int		sign = 1;
	int		i = 0;

	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		res = res * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			fraction *= 10.0;
			res += (str[i++] - '0') / fraction;
		}
	}
	if (str[i] != '\0')
		return (0);
	*out = res * sign;
	return (1);
}

int parse_vec3(char *str, t_vec3 *out)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (!tab)
		return (0);
	if (ptrptr_count((void **)tab) != 3)
	{
		ptrptr_free((void **)tab);
		return (0);
	}
	if (!ft_atof(tab[0], &out->x) || !ft_atof(tab[1], &out->y) || !ft_atof(tab[2], &out->z))
	{
		ptrptr_free((void **)tab);
		return (0);
	}
	ptrptr_free((void **)tab);
	return (1);
}

int parse_color(char *str, t_vec3 *out)
{
	if (!parse_vec3(str, out))
		return (0);
	if (out->r < 0.0 || out->r > 255.0 || 
		out->g < 0.0 || out->g > 255.0 || 
		out->b < 0.0 || out->b > 255.0)
		return (0);
	return (1);
}
