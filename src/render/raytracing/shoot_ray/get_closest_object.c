/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest_object.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 22:15:41 by marvin            #+#    #+#             */
/*   Updated: 2026/10/20 20:02:14 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_render.h"
#include "fn_math.h"
#include "cste_miniRT.h"
#include <stddef.h>

double	get_valid_solution(double *soluces, int nb_soluces)
{
	int		i;
	double	res;

	res = -1;
	i = 0;
	if (nb_soluces > 2 && soluces[1] > 0.0)
	{
		if (soluces[0] < 0.0)
			res = EPSILON;
		else
			res = soluces[0];
	}
	else if (nb_soluces <= 2)
	{
		while (i < nb_soluces)
		{
			if (soluces[i] > 0.0 && (res < 0 || min(soluces[i], res) == soluces[i]))
				res = soluces[i];
			i++;
		}
	}
	return (res);
}
// soluces aura la valeur du coeff min et max dans le cas d un plan ou d un cylindre
// si les solutions correspondent a un segment
// sur le plan (plan pile dans l'alignement du rayon cam / ou haut du cylindre)

int	valid_intersection(t_object *obj, t_ray3 ray)
{
	double	soluces[2];
	int		nb_soluces;
	double	valid_soluce;

	nb_soluces = obj->shape.is_in_shape(&ray, &(obj->shape), obj->origin, soluces);
	valid_soluce = get_valid_solution(soluces, nb_soluces);
	if (valid_soluce == -1)
		return (0);
	obj->coeff = valid_soluce;
	return (1);
}
/* valid intersection return 1 ou 0 selon la validite de l intersection rayon objet. aussi, elle assigne une valeur a obj->coeff
quand une solution valide est trouvée.

 -> la solution (dont la valeur est assignee a obj->coeff) correspond au + petit nombre de fois qu on doit multiplier
 le vecteur directeur Ray (vecteur de la cam defini dans build_first_ray_vec) pour arriver a un pt d intersection avec l'obj.

 On obtient tous les points d intersections possibles entre le rayon cam et l objet garce a is_in_shape, qui return le nb de solutions,
 et les stocke dans le tableau de double fourni (ici double[2], car pour une sphere il y a max 2 solutions).

 La plus petite des solution proposees par is_in_shape est retenue, a condition qu elle soit superieure a 0
 (sinon l objet est donc dans le sens inverse du rayon cam, donc derriere elle),
 et on la stocke dans obj->coeff
 si aucune des solutions n'est valide (s < 0), on return 0 (et obj->coeff est non defini), sinon on return 1 */

static int	is_closest(t_object *obj, t_object *to_cmp)
{
	if (obj->coeff < to_cmp->coeff)
		return (1);
	return (0);
}

t_object	*get_closest_object(t_scene *scene, t_ray3 ray, t_vec3 *intersect)
{
	t_list		*obj_lst;
	t_object	*closest;

	obj_lst = *(scene->obj_lst);
	closest = NULL;
	while (obj_lst)
	{
		if (valid_intersection((t_object*)(obj_lst->content), ray) &&
			(!closest || is_closest((t_object*)(obj_lst->content), closest)))
			closest = (t_object*)(obj_lst->content);
		obj_lst = obj_lst->next;
	}
	if (closest && intersect)
		*intersect = add_vec(ray.origin, mult_by_k_vec(ray.vec, closest->coeff));
	return(closest);
}
/* on verifie si chaque objet de notre obj_lst est touche par notre rayon

-> si un objet est touche par le rayon est qu il s agit d une intersection valide (objet devant cam, coeff > 0),
et qu on a pas encore etablit un objet qui soit plus proche que les autres de la cam, on l assigne a closest

si closest est deja defini, on compare les coeff : le plus petit coeff entre l'obj testé et l'objet précédemment
assigné à closest sera le nouveau closest

Aussi, on defini le point d intersection dans l'espace dans t_vec3 *intersect
(comme point dans l'espace, et non comme simple coeff comme dans obj->coeff) */
