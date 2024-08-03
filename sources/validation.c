/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:15:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/03 19:25:29 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	*get_line(char *av)
{
	int		fd;
	char	*gnl;
	char	*res;
	char	*temp;
	char	*trim_res;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit(err("Error: cannot open file"));
	res = NULL;
	temp = ft_strdup("");
	gnl = get_next_line(fd);
	while (gnl)
	{
		res = ft_strjoin(temp, gnl);
		// printf("stacvav=%s\n", res);
		free(temp);
		temp = res;
		free(gnl);
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
	}
	printf("aaaaaa=%s\n",res);
	trim_res = ft_strtrim(res, " \n\v\f\r\t");
	free(res);
	// printf("hesaaaaaa=%s\n",trim_res);
	return (trim_res);
}

int	validation(int ac, char **av)
{
	int		i;
	char	*read_line;
	if (ac > 2)
		return (err("Too much arguments!"));
	if (ac <= 1)
		return (err("Too few arguments!"));
	i = 0;
	if (ac == 2)
	{
		if (!strstr(av[1],".rt"))
			return(err("Wrong argument: Try this way: ./rt filename.rt"));
		read_line = get_line(av[1]);
		printf("hesa=%s\n",read_line);
	}
	return (0);
}
