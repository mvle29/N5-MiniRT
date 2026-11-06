/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cste_parsing_errors.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grivault <grivault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:20:52 by grivault          #+#    #+#             */
/*   Updated: 2026/11/06 17:59:27 by grivault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSTE_PARSING_ERRORS_H
# define CSTE_PARSING_ERRORS_H

# define ERR_ID "Unknown identifier found in .rt file"
# define ERR_DUP_AMB "Duplicate Ambient light (A) detected. Only one is allowed."
# define ERR_DUP_CAM "Duplicate Camera (C) detected. Only one is allowed."
# define ERR_DUP_LIG "Duplicate Light (L) detected. Only one is allowed."
# define ERR_PARAMS "Invalid number of parameters for element"
# define ERR_RATIO "Lighting ratio must be in range [0.0, 1.0]"
# define ERR_FOV "Camera FOV must be in range [0, 180]"
# define ERR_COLOR "Color RGB values must be in range [0, 255]"
# define ERR_VEC "Invalid 3D coordinates format"
# define ERR_NORM_VEC "Normalized vector components must be in range [-1.0, 1.0]"
# define ERR_FORMAT "Invalid format or value in shape parameters"

#endif
