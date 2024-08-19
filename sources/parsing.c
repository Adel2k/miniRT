/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:53:05 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/19 19:08:51 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parsing(char **map, t_minirt *rt)
{
	int	i;
	char	**matrix;
	i = 0;
	while (map[i])
	{
		matrix = split(map[i]);
		printf("a\n");
		found_what_scene_is_it(matrix, rt);
		free_matrix(matrix);//
		i++;
	}
	count_check(rt, map);
	// t_sphere *temp = rt->objects.sphere;
	// while (temp)
	// {
	// 	printf("sphere=%f\n", temp->center.x);
	// 	printf("sphere=%f\n", temp->center.y);
	// 	printf("sphere=%f\n", temp->center.z);
	// 	printf("sphere=%f\n", temp->diameter);
	// 	printf("sphere=%d\n", temp->color.red);
	// 	printf("sphere=%d\n", temp->color.green);
	// 	printf("sphere=%d\n", temp->color.blue);
	// 	temp = temp->next;
	// }
}

t_cylinder	*parse_cylinder(char **matrix, t_minirt *rt)
{
	int	i;
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	i = 0;
	if (matrix_row(matrix) != 6)
		exit_and_free_matrix(matrix, "Error: wrong qanaki arguments for cylinder", rt);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments cy", rt);
	}
	init_coords(&cylinder->coords, matrix, rt, 1);

	init_orient(&cylinder->orient, matrix, rt, 2);

	if (if_char_and_digit(matrix[3], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simbols for cylinder diametr", rt);
	cylinder->diameter = ft_atof(matrix[3]);

	if (if_char_and_digit(matrix[4], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simbols for cylinder height", rt);
	cylinder->height = ft_atof(matrix[4]);

	init_color(&cylinder->color, matrix, rt, 5);
	cylinder->next = NULL;
	// rt->objects.cylinder->count++;
	// count_check(rt, 'c', matrix, NULL);
	return (cylinder);
}


t_plane	*parse_plane(char **matrix, t_minirt *rt)
{
	int	i;
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: wrong qanaki arguments for plane", rt);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments pl", rt);
	}
	init_coords(&plane->coords, matrix, rt, 1);

	init_orient(&plane->orient, matrix, rt, 2);
	
	init_color(&plane->color, matrix, rt, 3);
	plane->next = NULL;
	// rt->objects.plane->count++;
	// count_check(rt, 'p', matrix, NULL);
	return (plane);

}

t_sphere	*parse_sphere(char **matrix, t_minirt *rt)
{
	int	i;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	// sphere->count = 0;
	i = 0;
	if (matrix_row(matrix) != 3)//4pti sarqenq,zut banem porcunm
		exit_and_free_matrix(matrix, "Error: wrong qanaki arguments for sphere", rt);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments sp", rt);
	}
	init_coords(&sphere->center, matrix, rt, 1);

	if (if_char_and_digit(matrix[2], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simbols for sphere", rt);
	sphere->diameter = ft_atof(matrix[2]);
	printf("aaaaa\n");

	// init_color(&sphere->color, matrix, rt, 3);
	sphere->next = NULL;
	return (sphere);
}

t_light		*parse_light(char **matrix, t_minirt *rt)
{
	int	i;
	t_light	*light;

	light = malloc(sizeof(t_light));
	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: wrong qanaki arguments for light coordinates", rt);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments L", rt);
	}
	init_coords(&light->coords, matrix, rt, 1);
	if (if_char_and_digit(matrix[2], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simbols for light brightness", rt);
	light->brightness = ft_atof(matrix[2]);
	if (!(light->brightness >= 0.0 && light->brightness <= 1.0))
		exit_and_free_matrix(matrix,"Error: bad value for light brightness", rt);
	init_color(&light->color, matrix, rt, 3);
	light->next = NULL;
	// rt->light->count++;
	// count_check(rt, 'l', matrix, NULL);
	return (light);
}
