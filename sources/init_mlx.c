/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:31:32 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/08 16:39:38 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	init_mlx(t_mlx_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		err("MLX initialization failed!\n");
	vars->win = mlx_new_window(vars->mlx, 1000, 1000, "miniRT");
	if (vars->win == NULL)
		err("MLX connection failed!\n");
	vars->img.img_ptr = mlx_new_image(vars->mlx, 1000 - 150, 1000);
	vars->img.img_pixels_ptr = mlx_get_data_addr(vars->img.img_ptr, \
	&vars->img.bits_per_pixel, &vars->img.line_len, &vars->img.endian);
	mlx_loop(vars->mlx);
}