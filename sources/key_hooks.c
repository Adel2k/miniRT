/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:13:51 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/20 16:24:56 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	handler(int keysym, t_scene *scene)
{
	if (keysym == 53)
	{
		mlx_destroy_image(scene->mlx->mlx, scene->img->img_ptr);
		mlx_clear_window(scene->mlx->mlx, scene->mlx->win);
		mlx_destroy_window(scene->mlx->mlx, scene->mlx->win);
		exit(0);
	}
	return (0);
}

int	mouse_close(t_scene *scene)
{
	mlx_destroy_image(scene->mlx->mlx, scene->img->img_ptr);
	mlx_clear_window(scene->mlx->mlx, scene->mlx->win);
	mlx_destroy_window(scene->mlx->mlx, scene->mlx->win);
	exit(0);
	return (0);
}