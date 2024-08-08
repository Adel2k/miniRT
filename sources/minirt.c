/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:07:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/07 21:10:29 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int main(int ac, char **av)
{
	t_minirt 	*rt;
	t_mlx_vars	*vars;

	rt = malloc(sizeof(t_minirt));
	vars = malloc(sizeof(t_mlx_vars));
	if (!rt)
		return (1);
	if (!(validation(ac, av, rt)))
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
		// system("leaks miniRT");

		return 0;
	}
	// system("leaks miniRT");
	return 1;
}