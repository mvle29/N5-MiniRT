/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 14:51:11 by marvin            #+#    #+#             */
/*   Updated: 2026/11/09 14:15:15 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fn_mlx.h"
#include "fn_init.h"
#include "fn_end.h"
#include "fn_errors.h"
#include "cste_errors.h"
#include "libft.h"

/*
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
*/

int	main(int argc, char **argv)
{
	t_engine	engine;
	int			len;

	if (argc != 2)
		return (puterror(ERR_ARGS), 1);
	len = ft_strlen(argv[1]);
	if (len < 3 || ft_strcmp(argv[1] + len - 3, ".rt") != 0)
		return (puterror(ERR_ARGS), 1);
	if (!init_engine(&engine, argv[1]))
		return (1);
	mlx_signals(&engine);
	mlx_loop(engine.mlx.mlx);
	end_program(&engine);
	return (0);
}
