/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:31:32 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/13 11:47:36 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_mlx(t_mlx_vars *vars, t_minirt *rt)
{
	t_scene	*scene;

	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		err("MLX initialization failed!\n");
	scene = new_scene(&rt->camera, &rt->objects, WIDTH, HIGHT);	
	vars->win = mlx_new_window(vars->mlx, scene->width, scene->hight, "miniRT");
	if (vars->win == NULL)
		err("MLX connection failed!\n");
	ray_tracing(vars->mlx, vars->win, scene);
	// free_scene(scene);
	vars->img.img_ptr = mlx_new_image(vars->mlx, 1000 - 150, 1000);
	vars->img.img_pixels_ptr = mlx_get_data_addr(vars->img.img_ptr, \
	&vars->img.bits_per_pixel, &vars->img.line_len, &vars->img.endian);
	mlx_hook(vars->win, 2, 0, handler, vars);
	mlx_hook(vars->win, 17, 0, mouse_close, vars);
	mlx_loop(vars->mlx);
}