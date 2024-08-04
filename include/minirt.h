/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <aeminian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:22:05 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/04 17:21:33 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../include/mlx.h"
# include "../include/get_next_line.h"

///////
typedef struct s_color
{
	int red;
    int green;
    int blue;
}	t_color;

typedef struct s_ambient
{
	float   ratio_lighting;
    t_color color;
}	t_ambient;
//////


/// ///
typedef struct s_vector
{
	float	x;
    float	y;
    float	z;
}	t_vector;

typedef struct s_camera
{
	t_vector    coordinates;
    int			fov;//size_t
	// t_vector	orient;//3d normalized orientation vector. In range [-1,1] for each x,y,z axis:0.0,0.0,1.0
}	t_camera;
/// //////


typedef struct s_light
{
	// t_obj_id		id;
	t_vector		coords;
	float			brightness;
	t_color			color;
	// struct s_light	*next;
}	t_light;


typedef struct s_sphere
{
	// t_obj_id	id;
	t_vector	coords;
	float		diameter;
	// float		r2;
	t_color		color;
}	t_sphere;


typedef struct s_plane
{
	// t_obj_id	id;
	t_vector	coords;
	t_color		color;
	t_vector	orient;
}	t_plane;

typedef struct s_cylinder
{
	// t_obj_id	id;
	t_vector	coords;
	t_vector	orient;
	float		diameter;
	float		height;
	// float		r2;
	// t_vect		p1;
	// t_vect		p2;
	// t_vect		delta_p;
	t_color		color;
}	t_cylinder;


size_t	ft_strlen(const char *str);
int		validation(int ac, char **av);
int		malloc_check(char *s);
int		err(char *str);
char	*ft_strdup(char *s);
int		check1(char c, char const *set);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strchr(const char *str, int c);
void	exit_and_free_str(char *str_free, char *str_err);
char	**split(char const *s, char c);
void	exit_and_free_matrix(char **map, char *str_err);
int		is_rt(char *str);
char	*strtrim_end(char *str);
#endif