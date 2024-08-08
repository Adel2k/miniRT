/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:07:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/08 15:21:07 by aeminian         ###   ########.fr       */
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
		init_mlx(vars);
		// system("leaks miniRT");
		return 0;
	}
	// system("leaks miniRT");
	return 1;
}