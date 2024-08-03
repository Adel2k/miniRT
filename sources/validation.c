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
		exit(err("Error: cannot open the file"));
	res = NULL;
	temp = ft_strdup("");
	gnl = get_next_line(fd);
	while (gnl)
	{
		res = ft_strjoin(temp, gnl);
		free(temp);
		temp = res;
		free(gnl);
		gnl = get_next_line(fd);
		if (!gnl)
			break ;
	}
	trim_res = ft_strtrim(res, " \n\v\f\r\t");
	free(res);
	return (trim_res);
}

int	is_rt(char *str)
{
	size_t	len;

	if (!str || !*str)
		return (1);
	len = ft_strlen(str) - 1;
	if (len > 3)
	{
		if (str[len--] != 't')
			return (1);
		if (str[len--] != 'r')
			return (1);
		if (str[len--] != '.')
			return (1);
		return (0);
	}
	return (1);
}

int	validation(int ac, char **av)
{
	char	*read_line;

	if (ac > 2)
		return (err("Error: Too much arguments!"));
	if (ac <= 1)
		return (err("Error: Few arguments! Enter the '.rt' file name"));
	if (ac == 2)
	{
		if (is_rt(av[1]))
			return(err("Error: Wrong argument: Try this way: ./rt filename.rt"));
		read_line = get_line(av[1]);
		printf("hesa=%s\n",read_line);
	}
	return (0);
}
