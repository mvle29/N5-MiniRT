/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_libft.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 15:39:50 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 15:39:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_LIBFT_H
# define TYPE_LIBFT_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

#endif
