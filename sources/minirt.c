/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 20:07:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/05 19:16:12 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int main(int ac, char **av)
{
	t_minirt *rt;

	rt = malloc(sizeof(t_minirt));
	if (!rt)
		return (1);
	if (!(validation(ac, av, rt)))
	{
		return 0;
	}
	return 1;
	// system("leaks miniRT");
}