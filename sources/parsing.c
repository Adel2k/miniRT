/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 14:53:05 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/31 18:26:52 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parsing(char **map, t_scene *scene)
{
	int	i;
	char	**matrix;
	i = 0;
	while (map[i])
	{
		matrix = split(map[i]);
		printf("a\n");
		found_what_scene_is_it(matrix, scene);
		free_matrix(matrix);//
		i++;
	}
	// count_check(scene, map);
	// t_figure *temp = scene->figure;
	// printf("::::%f\n",temp->next->sphere->radius);
	// while (temp)
	// {
	// 	printf("type=%d\n",temp->type);
	// 	if (temp->type == SPHERE)
	// 	{
	// printf("pahooo\n");
	// 		printf("sphere=%f\n", temp->sphere->center.x);
	// 		printf("sphere=%f\n", temp->sphere->center.y);
	// 		printf("sphere=%f\n", temp->sphere->center.z);
	// 		printf("sphere=%f\n", temp->sphere->radius * 2);
	// 		printf("sphere=%d\n", temp->sphere->color.red);
	// 		printf("sphere=%d\n", temp->sphere->color.green);
	// 		printf("sphere=%d\n", temp->sphere->color.blue);
	// 	}
	// 	temp = temp->next;
	// }
}

t_cylinder	*parse_cylinder(char **matrix, t_scene *scene)
{
	int	i;
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	i = 0;
	if (matrix_row(matrix) != 6)
		exit_and_free_matrix(matrix, "Error: wrong qanaki arguments for cylinder", scene);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments cy", scene);
	}
	init_coords(&cylinder->center, matrix, scene, 1);

	init_orient(&cylinder->orient, matrix, scene, 2);

	if (if_char_and_digit(matrix[3], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simbols for cylinder diametr", scene);
	cylinder->radius = ft_atof(matrix[3]) / 2;

	if (if_char_and_digit(matrix[4], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simbols for cylinder height", scene);
	cylinder->height = ft_atof(matrix[4]);

	init_color(&cylinder->color, matrix, scene, 5);
	// cylinder->next = NULL;
	// scene->cylinder->count++;
	// count_check(scene, 'c', matrix, NULL);
	return (cylinder);
}


t_plane	*parse_plane(char **matrix, t_scene *scene)
{
	int	i;
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: wrong qanaki arguments for plane", scene);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments pl", scene);
	}
	init_coords(&plane->coords, matrix, scene, 1);

	init_orient(&plane->orient, matrix, scene, 2);
	
	init_color(&plane->color, matrix, scene, 3);
	// plane->next = NULL;
	// scene->plane->count++;
	// count_check(scene, 'p', matrix, NULL);
	return (plane);

}

t_sphere	*parse_sphere(char **matrix, t_scene *scene)
{
	int	i;
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	// sphere->count = 0;
	i = 0;
	// sphere->specular = 50;///////////////////////////////////////////
	if (matrix_row(matrix) != 4)//4pti sarqenq,zut banem porcunm
		exit_and_free_matrix(matrix, "Error: wrong qanaki arguments for sphere", scene);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments sp", scene);
	}
	init_coords(&sphere->center, matrix, scene, 1);

	if (if_char_and_digit(matrix[2], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simbols for sphere", scene);
	sphere->radius = ft_atof(matrix[2]) / 2;
	printf("aaaaa\n");
	init_color(&sphere->color, matrix, scene, 3);
	// sphere->next = NULL;
	return (sphere);
}

t_light		*parse_light(char **matrix, t_scene *scene)
{
	int	i;
	t_light	*light;

	light = malloc(sizeof(t_light));
	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: wrong qanaki arguments for light coordinates", scene);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments L", scene);
	}
	init_coords(&light->coords, matrix, scene, 1);
	if (if_char_and_digit(matrix[2], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simbols for light brightness", scene);
	light->brightness = ft_atof(matrix[2]);
	if (!(light->brightness >= 0.0 && light->brightness <= 1.0))
		exit_and_free_matrix(matrix,"Error: bad value for light brightness", scene);
	init_color(&light->color, matrix, scene, 3);
	// light->next = NULL;
	// scene->light->count++;
	// count_check(scene, 'l', matrix, NULL);
	return (light);
}
