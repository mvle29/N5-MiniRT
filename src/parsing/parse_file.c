/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:14:42 by grivault          #+#    #+#             */
/*   Updated: 2026/11/12 19:09:59 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_engine.h"
#include "libft.h"
#include "fn_parsing.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static char	**read_whole_file(int fd)
{
	char	buffer[1025];
	int		bytes_read;
	char	*content;
	char	*temp;
	char	**lines;

	content = ft_strdup("");
	if (!content)
		return (puterror(ERR_MALLOC), NULL);
	bytes_read = read(fd, buffer, 1024);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = content;
		content = ft_strjoin(temp, buffer);
		free(temp);
		if (!content)
			return (puterror(ERR_MALLOC), NULL);
		bytes_read = read(fd, buffer, 1024);
	}
	if (bytes_read < 0)
		return (puterror(ERR_READ), free(content), NULL);
	lines = ft_split(content, '\n');
	return (free(content), lines);
}

static void	replace_whitespaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
			line[i] = ' ';
		i++;
	}
}

static int	router(t_scene *scene, char **tokens)
{
	(void)scene;
	if (!tokens || !tokens[0])
		return (1);
	if (ft_strcmp(tokens[0], "A") == 0)
		return (parse_ambient(scene, tokens));
	else if (ft_strcmp(tokens[0], "C") == 0)
		return (parse_camera(scene, tokens));
	else if (ft_strcmp(tokens[0], "L") == 0)
		return (parse_light(scene, tokens));
	else if (ft_strcmp(tokens[0], "sp") == 0)
		return (parse_sphere(scene, tokens));
	else if (ft_strcmp(tokens[0], "pl") == 0)
		return (parse_plane(scene, tokens));
	else if (ft_strcmp(tokens[0], "cy") == 0)
		return (parse_cylinder(scene, tokens));
	return (puterror(ERR_ID), 0);
}

static int	process_lines(t_scene *scene, char **lines)
{
	char	**tokens;
	int		i;

	i = 0;
	while (lines[i])
	{
		replace_whitespaces(lines[i]);
		tokens = ft_split(lines[i], ' ');
		if (!router(scene, tokens))
		{
			ptrptr_free((void **)tokens);
			ptrptr_free((void **)lines);
			return (0);
		}
		ptrptr_free((void **)tokens);
		i++;
	}
	return (1);
}

int	parse_rt_file(t_scene *scene, char *filename)
{
	int		fd;
	char	**lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (puterror(ERR_OPEN), 0);
	lines = read_whole_file(fd);
	close(fd);
	if (!lines)
		return (0);
	if (!process_lines(scene, lines))
		return (0);
	ptrptr_free((void **)lines);
	if (scene->ambient_color.r == -1.0 || (scene->cam.fwd.x == 0.0
			&& scene->cam.fwd.y == 0.0 && scene->cam.fwd.z == 0.0))
		return (puterror(ERR_MISSING), 0);
	return (1);
}

/*
int	parse_rt_file(t_scene *scene, char *filename)
{
	int		fd;
	char	**lines;
	char	**tokens;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (puterror(ERR_OPEN), 0);
	lines = read_whole_file(fd);
	close(fd);
	if (!lines)
		return (0);
	i = 0;
	while (lines[i])
	{
		replace_whitespaces(lines[i]);
		tokens = ft_split(lines[i], ' ');
		if (!router(scene, tokens))
		{
			(ptrptr_free((void **)tokens), ptrptr_free((void **)lines));
			return (0);
		}
		ptrptr_free((void **)tokens);
		i++;
	}
	ptrptr_free((void **)lines);
	if (scene->ambient_color.r == -1.0 || (scene->cam.fwd.x == 0.0
			&& scene->cam.fwd.y == 0.0 && scene->cam.fwd.z == 0.0))
		return (puterror("Missing Camera or Ambient light in scene"), 0);
	return (1);
}
*/
