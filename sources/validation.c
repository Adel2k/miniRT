/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:15:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/03 18:03:12 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	validation(int ac, char **av)
{
	int	i;
	
	if (ac > 2)
		return (err("Too much arguments!"));
	if (ac <= 1)
		return (err("Too few arguments!"));
	i = 0;
	if (ac == 2)
	{
		if (!strstr(av[1],".rt"))
			return(err("Wrong argument: Try this way: ./rt filename.rt"));
	}
	return (0);
}
