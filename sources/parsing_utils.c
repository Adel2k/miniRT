/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:08:21 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/16 16:29:22 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	found_what_scene_is_it(char **matrix, t_minirt *rt)
{
	void	*obj;

	if (!ft_strcmp(matrix[0], "A"))
	{
		parse_ambient(matrix, rt);
		printf("ambient=%f\n", rt->ambient.ratio_lighting);
		printf("ambient=%d\n", rt->color.red);
		printf("ambient=%d\n", rt->color.green);
		printf("ambient=%d\n", rt->color.blue);
	}
	else if (!ft_strcmp(matrix[0], "C"))
	{
		parse_camera(matrix, rt);
		// printf("camera=%f\n", rt->camera.coords.x);
		// printf("camera=%f\n", rt->camera.coords.y);
		// printf("camera=%f\n", rt->camera.coords.z);
		// printf("camera=%f\n", rt->camera.orient.x);
		// printf("camera=%f\n", rt->camera.orient.y);
		// printf("camera=%f\n", rt->camera.orient.z);
		// printf("camera=%d\n", rt->camera.fov);
	}
	else if (!ft_strcmp(matrix[0], "L"))
	{
		obj = parse_light(matrix, rt);
		ft_lstadd_back_l(&rt->light, obj);
		printf("light=%f\n", rt->light->coords.x);
		printf("light=%f\n", rt->light->coords.y);
		printf("light=%f\n", rt->light->coords.z);
		printf("light=%f\n", rt->light->brightness);
		printf("light=%d\n", rt->light->color.red);
		printf("light=%d\n", rt->light->color.green);
		printf("light=%d\n", rt->light->color.blue);
	}
	else if (!ft_strcmp(matrix[0], "sp"))
	{
		obj = parse_sphere(matrix, rt);
		ft_lstadd_back_sp(&rt->objects.sphere, obj);
	}
	else if (!ft_strcmp(matrix[0], "pl"))
	{
		obj = parse_plane(matrix, rt);
		ft_lstadd_back_pl(&rt->objects.plane, obj);
	}
	else if (!ft_strcmp(matrix[0], "cy"))
	{
		obj = parse_cylinder(matrix, rt);
		ft_lstadd_back_cy(&rt->objects.cylinder, obj);
	}
	else
		exit_and_free_matrix(matrix, "Error: wrong shape", rt);
}

// int	count_shape(char **matrix, char *shape)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (matrix[i])
// 	{
// 		if (!ft_strcmp(matrix[i], shape))
// 		{
// 			count++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }el petq chi


void	parse_camera(char **matrix, t_minirt *rt)
{
	char	**split_2_line = NULL;
	int		i;

	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: bad arguments for camera", rt);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments", rt);
	}

	init_coords(&rt->camera.center ,matrix, rt, 1);

	init_orient(&rt->camera.direction, matrix, rt, 2);

	if (if_only_digit(matrix[3]) == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for camera", rt);
	rt->camera.fov = atof(matrix[3]);
	if (!(rt->camera.fov >= 0 && rt->camera.fov <= 180))
		exit_and_free(matrix, "Error: bad value", rt, split_2_line);
	printf("func=%f\n", rt->camera.fov);
}

void	parse_ambient(char **matrix, t_minirt *rt)
{
	// char	**split_2_line=NULL;
	if (matrix_row(matrix) != 3)
		exit_and_free_matrix(matrix, "Error: bad arguments for ambient3", rt);
	if (if_char_and_digit(matrix[1], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad arguments for ambient4", rt);
	if (atof(matrix[1]) >= 0.0 && atof(matrix[1]) <= 1.0)
		rt->ambient.ratio_lighting = atof(matrix[1]);

	init_color(&rt->color, matrix, rt, 2);	
}
