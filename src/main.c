/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 14:51:11 by marvin            #+#    #+#             */
/*   Updated: 2026/10/10 14:51:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_mlx.h"
#include "fn_init.h"
#include "fn_end.h"

int	main(void)
{
	t_engine	engine;

	if (!init_engine(&engine))
		return (1);
	mlx_signals(&engine); // render est dedans
	mlx_loop(engine.mlx.mlx);
	end_program(&engine);
	return (0);
}
