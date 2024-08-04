/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:15:48 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/03 21:54:11 by vbarsegh         ###   ########.fr       */
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
	
	// printf("hesaaaaaa=%s\n",trim_res);
	return (res);
}

char **spliting(char *read_line)
{
	char	**map;
	char	*trim_line;

	trim_line = ft_strtrim(read_line, " \n\v\f\r\t");
	if (!trim_line)
		exit_and_free(read_line, "cannot do trim");
	free(read_line);
	map = split(trim_line, '\n');
	if (!map)
		exit_and_free_str(trim_line, "malloc error");
	free(trim_line);
	return (get_end_trim_map(map));
}

char **get_end_trim_map(char **map)
{
	int	i;
	int	row;
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
		trim_map[i] =  ft_strtrim_verjic(map[i]);
		if(!trim_map[i])
			exit_and_free_matrix(map, "cannot do split");
		i++;
	}
	trim_map[i] = NULL;
}


int	validation(int ac, char **av)
{
	int		i;
	char	*read_line;
	char	**map;
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
		map = spliting(read_line);
		printf("hesa=%s\n",read_line);
	}
	return (0);
}
