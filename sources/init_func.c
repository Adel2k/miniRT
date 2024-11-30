/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 15:22:00 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/12/01 01:00:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"


// void	vb(char *str, char **matrix)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		while(str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
// 		{
// 			comma_count++;
// 			if (comma_count > 2)
// 				exit_and_free_matrix(matrix,"Error: bad arguments for vb", rt);
// 			i++;
// 		}
// 	}
// }


void	init_coords(t_vector *coords, char **matrix, t_scene *scene, int i)
{
	char	**split_2_line;

	if (if_str_and_digit(matrix[i], ".,") == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for camera", scene);
	split_2_line = split_char(matrix[1], ',');
	if (!split_2_line)
		exit_and_free_matrix(matrix, "Error: malloc" ,scene);
	if (matrix_row(split_2_line) != 3)
		exit_and_free(matrix, "Error: bad arguments for camera", scene, split_2_line);
	coords->x = ft_atof(split_2_line[0]);
	coords->y = ft_atof(split_2_line[1]);
	coords->z = ft_atof(split_2_line[2]);
	coords->w = 1.0;//whyy
	free_matrix(split_2_line);
	system("leaks miniRT");
	
}

void	init_orient(t_vector *orient, char **matrix, t_scene *scene, int i)
{
	char	**split_2_line;

	if (if_str_and_digit(matrix[i], ".,") == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for camera", scene);
	split_2_line = split_char(matrix[i], ',');
	if (!split_2_line)
		exit_and_free_matrix(matrix, "Error: malloc" ,scene);
	if (matrix_row(split_2_line) != 3)
		exit_and_free(matrix, "Error: bad arguments for camera", scene, split_2_line);
	orient->x = ft_atof(split_2_line[0]);
	orient->y = ft_atof(split_2_line[1]);
	orient->z = ft_atof(split_2_line[2]);
	orient->w = 1.0;//whyyy
	// printf("aa%d\n",matrix_row(matrix));
	if (!(orient->x >= -1.0 && orient->x <= 1.0)
		|| !(orient->y >= -1.0 && orient->y <= 1.0)
		|| !(orient->z >= -1.0 && orient->z <= 1.0))
		exit_and_free(matrix, "Error: bad value", scene, split_2_line);
	free_matrix(split_2_line);//erevi
	system("leaks miniRT");
	vec_normalize(orient);////////////////

}

void	init_color(t_color *color, char **matrix, t_scene *scene, int i)
{
	char	**split_2_line;

	if (if_char_and_digit(matrix[i], ',') == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for ambient1", scene);
	split_2_line = split_char(matrix[i], ',');
	if (!split_2_line)
		exit_and_free_matrix(matrix, "Error: malloc" ,scene);
	if (matrix_row(split_2_line) != 3)
		exit_and_free(matrix, "Error: bad arguments for ambient2", scene, split_2_line);
	color->red = ft_atoi(split_2_line[0]);
	color->green = ft_atoi(split_2_line[1]);
	color->blue = ft_atoi(split_2_line[2]);
	if (!(color->red >= 0 && color->red <= 255)
		|| !(color->green >= 0 && color->green <= 255)
		|| !(color->blue >= 0 && color->blue <= 255))
		exit_and_free(matrix, "Error: value of color out is range", scene, split_2_line);
	free_matrix(split_2_line);
	system("leaks miniRT");

}

