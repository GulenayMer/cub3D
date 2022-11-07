/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:12:36 by jrocha            #+#    #+#             */
/*   Updated: 2022/11/07 16:21:17 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define WRNG_NUM_ARGS1 "cub3D: Incorrect number of arguments: \
You must provide a .cub file.\n"

# define WRNG_NUM_ARGS2 "cub3D: Incorrect number of arguments: \
cub3D takes only one argument.\n"

# define NO_ACCESS "cub3D: Unable to open file: \
%s\n"

# define WRNG_TYPE "cub3D: Incorrect file type: \
You must provide a .cub file.\n"

# define ERROR_INVALID_MAP "Error\ncub3D: %s contains invalid characters.\n"

# define INVALID_VALUES "Error\ncub3D: %s contains invalid values.\n"

# define INVALID_PATH "Error\ncub3D: %s could not open file.\n"

# define TEXTURE_PROBLEM "Error\ncub3D: There was a problem loading\
 the textures\n"

# define WALL_ERR "Error\ncub3D: Floor must be surrounded by the walls!\n"

# define SPACE_ERR "Error\ncub3D: There are empty spaces inside the map!\n"

# define NO_PLAYER "Error\ncub3D: There are no players inside the map!\n"
#endif
