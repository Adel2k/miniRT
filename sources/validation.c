/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:15:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/04 17:57:43 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	*get_line(char *av)
{
	int		fd;
	char	*gnl;
	char	*res;
	char	*temp;

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
	return (res);
}

char **get_end_trim_map(char **map)
{
	int		i;
	int		row;
	char	**trim_map;

	row = 0;
	while (map[row])
		row++;
	trim_map = malloc(sizeof(char *) * (row + 1));
	if (!trim_map)
		exit_and_free_matrix(map, "cannot do split");
	i = 0;
	while (map[i])
	{
		trim_map[i] =  strtrim_end(map[i]);
		if(!trim_map[i])
			exit_and_free_matrix(map, "cannot do split");
		i++;
	}
	trim_map[i] = NULL;
	return(trim_map);
}

char **spliting(char *read_line)
{
	char	**map;
	char	*trim_line;

	trim_line = ft_strtrim(read_line, " \n\v\f\r\t");
	// if (!trim_line)
	// 	exit_and_free_str(read_line, "cannot do trim"); //demic exit_and_free a exel
	free(read_line);
	map = split(trim_line, '\n');
	if (!map)
		exit_and_free_str(trim_line, "malloc error");
	free(trim_line);
	return (get_end_trim_map(map));
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
	char	**map;
	if (ac > 2)
		return (err("Error: Too much arguments!"));
	if (ac <= 1)
		return (err("Error: Few arguments! Enter the '.rt' file name"));
	if (ac == 2)
	{
		if (is_rt(av[1]))
			return(err("Error: Wrong argument: Try this way: ./rt filename.rt"));
		read_line = get_line(av[1]);
		map = spliting(read_line);
		int i = 0;
		while (**map && map[i])
		{
			printf("hesa=%s\n", map[i]);
			i++;
		}
	}
	return (0);
}
