/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 17:14:42 by grivault          #+#    #+#             */
/*   Updated: 2026/10/31 22:06:09 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type_engine.h"
#include "libft.h"
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
		return (NULL); //print error
	bytes_read = read(fd, buffer, 1024);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = content;
		content = ft_strjoin(temp, buffer); // Requires free of old content
		free(temp);
		if (!content)
			return (NULL); //print error
		bytes_read = read(fd, buffer, 1024);
	}
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
		return (1); // Empty line, safely ignore
	if (ft_strcmp(tokens[0], "A") == 0)
		return (1); // TODO: return parse_ambient(scene, tokens);
	else if (ft_strcmp(tokens[0], "C") == 0)
		return (1); // TODO: return parse_camera(scene, tokens);
	else if (ft_strcmp(tokens[0], "L") == 0)
		return (1); // TODO: return parse_light(scene, tokens);
	else if (ft_strcmp(tokens[0], "sp") == 0)
		return (1); // TODO: return parse_sphere(scene, tokens);
	else if (ft_strcmp(tokens[0], "pl") == 0)
		return (1); // TODO: return parse_plane(scene, tokens);
	else if (ft_strcmp(tokens[0], "cy") == 0)
		return (1); // TODO: return parse_cylinder(scene, tokens);
	// If the identifier doesn't match any known types
	return (0);
}

int	parse_rt_file(t_scene *scene, char *filename)
{
	int		fd;
	char	**lines;
	char	**tokens;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0); //print error
	lines = read_whole_file(fd);
	close(fd);
	if (!lines)
		return (0); //print error
	i = 0;
	while (lines[i])
	{
		replace_whitespaces(lines[i]);
		tokens = ft_split(lines[i], ' ');
		if (!router(scene, tokens)) //if true means id is not one of the expected ids
		{
			(ptrptr_free((void **)tokens), ptrptr_free((void **)lines));
			return (0); // Clean up and exit on first syntax error
		}
		ptrptr_free((void **)tokens);
		i++;
	}
	ptrptr_free((void **)lines);
	return (1); // Parsing successful
}
