/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:22:00 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/06 20:42:40 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_coords(t_vector *coords, char **matrix, t_minirt *rt, int i)
{
	char	**split_2_line;

	if (if_line_contain_only_digit_and_str(matrix[i], ".,") == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for camera", rt);
	split_2_line = split_char(matrix[1], ',');
	if (!split_2_line)
		exit_and_free_matrix(matrix, "Error: malloc" ,rt);
	if (matrix_row(split_2_line) != 3)
		exit_and_free(matrix, "Error: bad arguments for camera", rt, split_2_line);
	coords->x = atof(split_2_line[0]);
	coords->y = atof(split_2_line[1]);
	coords->z = ft_atof(split_2_line[2]);
	free_matrix(split_2_line);
}

void	init_orient(t_vector *orient, char **matrix, t_minirt *rt, int i)
{
	char	**split_2_line;

	if (if_line_contain_only_digit_and_str(matrix[i], ".,") == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for camera", rt);
	split_2_line = split_char(matrix[i], ',');
	if (!split_2_line)
		exit_and_free_matrix(matrix, "Error: malloc" ,rt);
	if (matrix_row(split_2_line) != 3)
		exit_and_free(matrix, "Error: bad arguments for camera", rt, split_2_line);
	orient->x = ft_atof(split_2_line[0]);
	orient->y = ft_atof(split_2_line[1]);
	orient->z = ft_atof(split_2_line[2]);
	// printf("aa%d\n",matrix_row(matrix));
	

	if (!(orient->x >= -1.0 && orient->x <= 1.0)
		|| !(orient->y >= -1.0 && orient->y <= 1.0)
		|| !(orient->z >= -1.0 &&orient->z <= 1.0))
		exit_and_free(matrix, "Error: bad value", rt, split_2_line);
	free_matrix(split_2_line);//erevi	
}

void	init_color(t_color *color, char **matrix, t_minirt *rt, int i)
{
	char	**split_2_line;

	if (if_line_contain_only_digit_and_char(matrix[i], ',') == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for ambient1", rt);
	split_2_line = split_char(matrix[i], ',');
	if (!split_2_line)
		exit_and_free_matrix(matrix, "Error: malloc" ,rt);
	if (matrix_row(split_2_line) != 3)
		exit_and_free(matrix, "Error: bad arguments for ambient2", rt, split_2_line);
	color->red = ft_atoi(split_2_line[0]);
	color->green = ft_atoi(split_2_line[1]);
	color->blue = ft_atoi(split_2_line[2]);
	if (!(color->red >= 0 && color->red <= 255)
		|| !(color->green >= 0 && color->green <= 255)
		|| !(color->blue >= 0 && color->blue <= 255))
		exit_and_free(matrix, "Error: bad value", rt, split_2_line);
	free_matrix(split_2_line);//erevi
}

