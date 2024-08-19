/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:08:21 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/19 18:39:22 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	found_what_scene_is_it(char **matrix, t_minirt *rt)
{
	void	*obj;

	if (!ft_strcmp(matrix[0], "A"))
	{
		obj = parse_ambient(matrix, rt);
		ft_lstadd_back_amb(&rt->ambient, obj);
		// printf("ambient=%f\n", rt->ambient->ratio_lighting);
		// printf("ambient=%d\n", rt->ambient->color.red);
		// printf("ambient=%d\n", rt->ambient->color.green);
		// printf("ambient=%d\n", rt->ambient->color.blue);
	}
	else if (!ft_strcmp(matrix[0], "C"))
	{
		
		obj = parse_camera(matrix, rt);
		ft_lstadd_back_ca(&rt->camera, obj);
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
		// printf("light=%f\n", rt->light->coords.x);
		// printf("light=%f\n", rt->light->coords.y);
		// printf("light=%f\n", rt->light->coords.z);
		// printf("light=%f\n", rt->light->brightness);
		// printf("light=%d\n", rt->light->color.red);
		// printf("light=%d\n", rt->light->color.green);
		// printf("light=%d\n", rt->light->color.blue);
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


void	*parse_camera(char **matrix, t_minirt *rt)
{
	char	**split_2_line = NULL;
	int		i;
	t_camera	*camera;
	camera = malloc(sizeof(t_camera));
	i = 0;
	if (matrix_row(matrix) != 4)
		exit_and_free_matrix(matrix, "Error: wrong qanaki arguments for camera", rt);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments", rt);
	}

	init_coords(&camera->center ,matrix, rt, 1);

	init_orient(&camera->direction, matrix, rt, 2);

	if (if_only_digit(matrix[3]) == -1)
		exit_and_free_matrix(matrix,"Error: bad arguments for camera", rt);
	camera->fov = atof(matrix[3]);
	if (!(camera->fov >= 0 && camera->fov <= 180))
		exit_and_free(matrix, "Error: bad value fov", rt, split_2_line);
	// rt->camera.count++;
	// count_check(rt, 'C', matrix, split_2_line);
	camera->next = NULL;
	printf("exav\n");
	return (camera);
}

void	*parse_ambient(char **matrix, t_minirt *rt)
{
	int	i;
	t_ambient	*ambient;

	i = -1;
	ambient = malloc(sizeof (t_ambient));
	if (matrix_row(matrix) != 3)
		exit_and_free_matrix(matrix, "Error: wrong qanaki arguments for ambient", rt);
	while (matrix[++i])
	{
		if (matrix[i][0] == ',' || matrix[i][ft_strlen(matrix[i]) - 1] == ','
			|| (ft_strstr_alt(matrix[i], ",,")))
			exit_and_free_matrix(matrix,"Error: bad arguments", rt);
	}
	if (if_char_and_digit(matrix[1], '.') == -1)
		exit_and_free_matrix(matrix, "Error: bad simbols for ambient ratio_lighting", rt);
	ambient->ratio_lighting = ft_atof(matrix[1]);
	if (!(ambient->ratio_lighting >= 0.0 && ambient->ratio_lighting <= 1.0))
		exit_and_free_matrix(matrix, "Error: bad value ambient ratio_lighting", rt);

	printf("hres=%f\n",ambient->ratio_lighting);
	init_color(&ambient->color, matrix, rt, 2);
	ambient->next = NULL;
	return (ambient);
	// count_check(rt, 'a', matrix, NULL);
	// rt->ambient.count++;
}


void	count_check(t_minirt *rt, char **map)
{
	check_cam_count(rt->camera, map, rt);
	check_ambient_count(rt->ambient, map, rt);

}

void	check_cam_count(t_camera *cam, char **map, t_minirt *rt)
{
	int	count;
	count = 0;
	printf("hn\n");
	printf("hasce=%p\n", cam);
	while (cam)
	{
		count++;
		printf("aaaaaaaa\n");
		cam = cam->next;
	}
	if (count != 1)
		exit_and_free_matrix(map, "Error: invalid count camera", rt);
}

void	check_ambient_count(t_ambient *ambient, char **map, t_minirt *rt)
{
	int	count;
	count = 0;
	printf("hn\n");
	while (ambient)
	{
		count++;
		printf("aaaaaaaa\n");
		ambient = ambient->next;
	}
	if (count != 1)
		exit_and_free_matrix(map, "Error: invalid count ambient", rt);
}