/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:31:32 by aeminian          #+#    #+#             */
/*   Updated: 2024/12/10 19:15:16 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_mlx(t_scene *scene)
{
	scene->mlx = (t_mlx_vars *)malloc(sizeof(t_mlx_vars));
	scene->img = (t_img *)malloc(sizeof(t_img));
	scene->mlx->mlx = mlx_init();
	if (scene->mlx->mlx == NULL)
		err("MLX initialization failed!\n");
	scene->mlx->win = mlx_new_window(scene->mlx->mlx,
			scene->width, scene->height, "miniRT");
	if (scene->mlx->win == NULL)
		err("MLX connection failed!\n");
	scene->img->img_ptr = mlx_new_image(scene->mlx->mlx, WIDTH, HEIGHT);
	scene->img->img_pixels_ptr = mlx_get_data_addr(scene->img->img_ptr, \
		&scene->img->bits_per_pixel,
			&scene->img->line_len, &scene->img->endian);
	scene->img->width = scene->width;
	scene->img->height = scene->height;
	geting_texture(scene);
	ray_tracing(scene);
	mlx_put_image_to_window(scene->mlx->mlx,
		scene->mlx->win, scene->img->img_ptr, 0, 0);
	mlx_hook(scene->mlx->win, 2, 0, &handler, scene);
	mlx_hook(scene->mlx->win, 17, 0, &mouse_close, scene);
	mlx_loop_hook(scene->mlx->mlx, &draw, scene);
	//system("leaks miniRT");	
	mlx_loop(scene->mlx->mlx);
	////system("leaks miniRT");
}

int	init_texture(char *xpm, t_sphere *sphere)
{
	char	**line;

	line = split_char(xpm, ':');
	if (!(ft_strcmp(line[0], "txm")))
	{
		sphere->has_texture = true;
		if (open(line[1], O_RDONLY) <= 0)
		{
			free_matrix(line);//
			return (1);
		}
		sphere->path = ft_strdup(line[1]);//
		free_matrix(line);//
		return (0);
	}
	free_matrix(line);//
	line = split(xpm);
	if (!(ft_strcmp(line[0], "check")))
	{
		free_matrix(line);//
		sphere->has_check = true;
		return (0);
	}
	else
	{
		free_matrix(line);//
		return (1);
	}
}

int	init_bump(char *bmp, t_sphere *sphere)
{
	char	**line;

	line = split_char(bmp, ':');
	if (!(ft_strcmp(line[0], "bmp")))
	{
		sphere->has_bump = true;
		if (open(line[1], O_RDONLY) <= 0)
		{
			free_matrix(line);//
			return (1);
		}
		sphere->bmp_map = ft_strdup(line[1]);//
		free_matrix(line);//
		return (0);
	}
	else
	{
		free_matrix(line);//
		return (1);
	}
}

void	init_sphere(t_sphere *sphere)
{
	sphere->has_texture = false;
	sphere->has_bump = false;
	sphere->has_check = false;
	sphere->path = NULL;
	sphere->bmp_map = NULL;
}
