/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:08:21 by aeminian          #+#    #+#             */
/*   Updated: 2024/11/25 11:51:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	found_what_scene_is_it(char **matrix, t_scene *scene)
{
	// void	*obj;

	if (!ft_strcmp(matrix[0], "A"))
	{
		scene->ambient = parse_ambient(matrix, scene);
		// obj = parse_ambient(matrix, scene);
		// ft_lstadd_back_amb(&scene->ambient, obj);
		
		printf("ambient=%f\n", scene->ambient->ratio_lighting);
		printf("ambient=%d\n", scene->ambient->light.red);
		printf("ambient=%d\n", scene->ambient->light.green);
		printf("ambient=%d\n", scene->ambient->light.blue);
	}
	else if (!ft_strcmp(matrix[0], "C"))
	{
		scene->camera = parse_camera(matrix, scene);
		// printf("Agvan=%f\n",scene->)
		// obj = parse_camera(matrix, scene);
		// ft_lstadd_back_ca(&scene->camera, obj);
		
		// printf("camera=%f\n", scene->camera.coords.x);
		// printf("camera=%f\n", scene->camera.coords.y);
		// printf("camera=%f\n", scene->camera.coords.z);
		// printf("camera=%f\n", scene->camera.orient.x);
		// printf("camera=%f\n", scene->camera.orient.y);
		// printf("camera=%f\n", scene->camera.orient.z);
		// printf("camera=%d\n", scene->camera.fov);
	}
	else if (!ft_strcmp(matrix[0], "L"))
	{
		// scene->light = parse_light(matrix, scene);//sarqel list esi 
		
		ft_lstadd_back_light(&scene->light, lst_create_light(scene, matrix));
		
		// ft_lstadd_back_l(&scene->light, obj);
		
		// printf("light=%f\n", scene->light->coords.x);
		// printf("light=%f\n", scene->light->coords.y);
		// printf("light=%f\n", scene->light->coords.z);
		// printf("light=%f\n", scene->light->brightness);
		// printf("light=%d\n", scene->light->color.red);
		// printf("light=%d\n", scene->light->color.green);```````
		// printf("light=%d\n", scene->light->color.blue);
	}
	else if (!ft_strcmp(matrix[0], "sp"))
	{
		// obj = parse_sphere(matrix, scene);
		// ft_lstadd_back_sp(&scene->sphere, obj);
		ft_lstadd_back_figure(&scene->figure, lst_create_figure(scene, matrix, SPHERE));
	}
	else if (!ft_strcmp(matrix[0], "pl"))
	{
		// obj = parse_plane(matrix, scene);
		// ft_lstadd_back_pl(&scene->plane, obj);
		ft_lstadd_back_figure(&scene->figure, lst_create_figure(scene, matrix, PLANE));
	}
	else if (!ft_strcmp(matrix[0], "cy"))
	{
		// obj = parse_cylinder(matrix, scene);
		// ft_lstadd_back_cy(&scene->cylinder, obj);
		ft_lstadd_back_figure(&scene->figure, lst_create_figure(scene, matrix, CYLINDER));

	}
	else
		exit_and_free_matrix(matrix, "Error: wrong shape", scene);
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


void	*parse_camera(char **matrix, t_scene *scene)
{
	char	**split_2_line = NULL;
	int		i;
	t_camera	*camera;
	camera = malloc(sizeof(t_camera));
	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: wrong qanaki arguments for camera", scene);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments", scene);
	}

	init_coords(&camera->center ,matrix, scene, 1);

	init_orient(&camera->direction, matrix, scene, 2);

	if (if_only_digit(matrix[3]) == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for camera", scene);
	camera->fov = atof(matrix[3]);
	if (!(camera->fov >= 0 && camera->fov <= 180))
		exit_and_free(matrix, "Error: bad value fov", scene, split_2_line);
	// scene->camera.count++;
	// count_check(scene, 'C', matrix, split_2_line);
	// camera->next = NULL;
	printf("exav\n");
	printf("-----%f\n",camera->fov);
	return (camera);
}

void	*parse_ambient(char **matrix, t_scene *scene)
{
	int	i;
	t_ambient	*ambient;

	i = -1;
	ambient = malloc(sizeof (t_ambient));
	if (matrix_row(matrix) != 3)
		exit_and_free_matrix(matrix, "Error: wrong qanaki arguments for ambient", scene);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments", scene);
	}
	if (if_char_and_digit(matrix[1], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simbols for ambient ratio_lighting", scene);
	ambient->ratio_lighting = ft_atof(matrix[1]);
	if (!(ambient->ratio_lighting >= 0.0 && ambient->ratio_lighting <= 1.0))
		exit_and_free_matrix(matrix, "Error: bad value ambient ratio_lighting", scene);

	printf("hres=%f\n",ambient->ratio_lighting);
	init_color(&ambient->light, matrix, scene, 2);
	// ambient->next = NULL;
	return (ambient);
	// count_check(scene, 'a', matrix, NULL);
	// scene->ambient.count++;
}


void	count_check(t_scene *scene, char **map)
{
	(void)scene;
	(void)map;
	// check_cam_count(scene->camera, map, scene);
	// check_ambient_count(scene->ambient, map, scene);

}

// void	check_cam_count(t_camera *cam, char **map, t_scene *scene)
// {
// 	int	count;
// 	count = 0;
// 	printf("hn\n");
// 	printf("hasce=%p\n", cam);
// 	while (cam)
// 	{
// 		count++;
// 		printf("aaaaaaaa\n");
// 		cam = cam->next;
// 	}
// 	if (count != 1)
// 		exit_and_free_matrix(map, "Error: invalid count camera", scene);
// }

// void	check_ambient_count(t_ambient *ambient, char **map, t_scene *scene)
// {
// 	int	count;
// 	count = 0;
// 	printf("hn\n");
// 	while (ambient)
// 	{
// 		count++;
// 		printf("aaaaaaaa\n");
// 		ambient = ambient->next;
// 	}
// 	if (count != 1)
// 		exit_and_free_matrix(map, "Error: invalid count ambient", scene);
// }