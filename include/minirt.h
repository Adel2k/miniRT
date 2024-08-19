/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:22:05 by aeminian          #+#    #+#             */
/*   Updated: 2024/08/18 20:22:18 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 800
# define HIGHT 600
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
typedef struct n_img
{
	void	*img_ptr;//pixelnerov stacvac yndhanur nkari hascena
	char	*img_pixels_ptr;//pixeli hascena
	int		bits_per_pixel;//mi piqselyb te qani bita zbaxecnum
	int		endian;
	int		line_len;//plangi erkarutyan vra qani pixela texavorvum
}	t_img;

typedef struct s_atof
{
	double	num;
	int		sign;
	int		is_float;
	double	fraction;
}	t_atof;

typedef struct s_mlx_vars
{
	void			*mlx;
	void			*win;
	t_img			img;
}	t_mlx_vars;

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
	int		count;
	struct s_ambient	*next;
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
	t_vector    center;
    float		fov;//size_t,կհաշվարկի տեսադաշտի լայնությունը
	t_vector	direction;//uxxutyun
	int		count;
	struct s_camera	*next;
}	t_camera;
/// //////


typedef struct s_light
{
	// t_obj_id		id;
	t_vector		coords;
	float			brightness;
	t_color			color;
	// int				count;
	struct s_light	*next;
}	t_light;


typedef struct s_sphere
{
	// t_obj_id	id;
	t_vector	center;
	float		diameter;
	// float		r2;
	t_color		color;
	// int			count;
	struct s_sphere	*next;
}	t_sphere;


typedef struct s_plane
{
	// t_obj_id	id;
	t_vector	coords;
	t_color		color;
	t_vector	orient;
	// int			count;
	struct s_plane	*next;
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
	// int			count;
	struct s_cylinder	*next;
}	t_cylinder;

typedef struct s_objects
{
	t_plane		*plane;
	t_sphere 	*sphere;
	t_cylinder	*cylinder;	
}	t_objects;

typedef struct s_minirt
{
	t_color		color;
	t_ambient	*ambient;
	t_objects	objects;
	t_vector	vector;
	t_camera	*camera;
	t_light		*light;
}	t_minirt;

typedef struct s_scene
{
	t_objects	objects;
	t_camera	camera;
	float		width;
	float		hight;
}	t_scene;

typedef struct s_vplane//okna prasmotra
{
	float	width;
	float	hight;
	float	x_pixel;//piksel akna prasmotra
	float	y_pixel;
}	t_vplane;


/////////////////exit_free////////////////////////
int		err(char *str);
void	exit_and_free_str(char *str_free, char *str_err, t_minirt *rt);
void	exit_and_free_matrix(char **map, char *str_err, t_minirt *rt);
void	exit_and_free(char **map, char *str_err, t_minirt *rt, char **matrix);
void	free_matrix(char **matrix);
void	free_vars(t_mlx_vars *vars);

/////////////////parsing//////////////////////////////
void	parsing(char **map, t_minirt *rt);
t_light	*parse_light(char **matrix, t_minirt *rt);
t_sphere	*parse_sphere(char **matrix, t_minirt *rt);
t_cylinder	*parse_cylinder(char **matrix, t_minirt *rt);
t_plane	*parse_plane(char **matrix, t_minirt *rt);

/////////////////parsing_utils////////////////////////
void	found_what_scene_is_it(char **matrix, t_minirt *rt);
void	*parse_camera(char **matrix, t_minirt *rt);
void	*parse_ambient(char **matrix, t_minirt *rt);
int		count_shape(char **matrix, char *shape);

/////////////////init_mlx////////////////////////////
void	init_mlx(t_mlx_vars *vars, t_minirt *rt);
void	init_rt(t_minirt *rt);
/////////////////utils///////////////////////////////
int		malloc_check(char *s);
int		check1(char c, char const *set);
int		is_white_space(char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strstr_alt(char *str, char *to_find);

/////////////////utils2/////////////////////////////
int		ft_atoi(const char *str);
int 	if_char_and_digit(char *line, char c);
int		matrix_row(char **matrix);
double	ft_atof(char *str);
int		if_only_digit(char *line);
int		if_str_and_digit(char *line, char *set);
int		have_this_char_in_set(char c, char *set);

/////////////////validation////////////////////////
int		validation(int ac, char **av, t_minirt *rt);
int		is_rt(char *str);

/////////////////init_func////////////////////////////
void	init_coords(t_vector *coords, char **matrix, t_minirt *rt, int i);
void	init_color(t_color *color, char **matrix, t_minirt *rt, int i);
void	init_orient(t_vector *orient, char **matrix, t_minirt *rt, int i);

/////////////////split_char////////////////////////////
int		foo_sum_tar_(char const *s, char c);
int		func_count_word_(const char *s, char c);
char	**split_char(char const *s, char c);
int		ft_strlen(const char *str);

/////////////////split////////////////////////////
int		check_00(char **arr, const char *s, int count);
char	**split(char const *s);

/////////////////trim////////////////////////////
char	*strtrim_end(char *str);
char	*ft_strtrim(char *s1, char *set);

/////////////////gnl////////////////////////////
char	*ft_strdup(char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *str, int c);

/////////////////key_hooks////////////////////////////
int		handler(int keysym, t_mlx_vars *vars);
int		mouse_close(t_mlx_vars *vars);

/////////////////list_functions////////////////////////////
void	ft_lstadd_back_cy(t_cylinder **lst, t_cylinder *new);
t_cylinder	*ft_lstlast_cy(t_cylinder *lst);
void	ft_lstadd_back_pl(t_plane **lst, t_plane *new);
t_plane	*ft_lstlast_pl(t_plane *lst);
void	ft_lstadd_back_sp(t_sphere **lst, t_sphere *new);
t_sphere	*ft_lstlast_sp(t_sphere *lst);
void	ft_lstadd_back_l(t_light **lst, t_light *new);
t_light	*ft_lstlast_l(t_light *lst);
void	ft_lstadd_back_ca(t_camera **lst, t_camera *new);
t_camera	*ft_lstlast_ca(t_camera *lst);
void	ft_lstadd_back_amb(t_ambient **lst, t_ambient *new);
t_ambient	*ft_lstlast_amb(t_ambient *lst);


t_scene	*new_scene(t_camera *camera, t_objects *object, int width, int hight);

/////////////////vector.c////////////////////////////
t_vector	*new_vector(float x, float y, float z);
t_vector	*vec_subtract(t_vector *vec1, t_vector *vec2);
float	vec_length(t_vector *vec);
float	vec_dot_product(t_vector *vec1, t_vector *vec2);
void	vec_normalize(t_vector *vec);
float	vec_dot_product(t_vector *vec1, t_vector *vec2);

/////////////////ray_tracing.c////////////////////////////
void	ray_tracing(void *mlx, void *win, t_scene *scene);
t_vplane	*get_view_plane(float width, float hight, float fov);
int	sphere_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere); 




void	count_check(t_minirt *rt, char **matrix);
void	check_cam_count(t_camera *cam, char **matrix, t_minirt *rt);
void	check_ambient_count(t_ambient *ambient, char **map, t_minirt *rt);
#endif
