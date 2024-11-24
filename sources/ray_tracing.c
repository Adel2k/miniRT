/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:40:50 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/11/24 21:51:50 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

// struct s_vector
// {
// 	double	x;
// 	double	y;
// 	double	z;
// };


// void	ray_tracing(void *mlx, void *win, t_scene *scene)
// {
// 	(void)mlx;
// 		(void)win;
// 	int	mlx_x;
// 	int	mlx_y;//ay erkusy mlx_put_piexl()funklciayi hamar en,ev dranc arjeqnery popoxvelu en 0-800 ev 0-600,qani vor //mlx_put_pixel()-@ stanuma miayn drakan tver

// 	double	x_ankyan_value;//ugl iqsa s kotoriy mi nachinayem   TES NKARY
// 	double	y_ankyan_value;//y_angle
// 	int	color;//es pahin guyneri het chenq ashxatum,zut ete luchy hatec obyekty nerkum enq spitakov,ete chhatec sevov
// 	double	x_ray;
// 	double	y_ray;//sranq koordinatner mer charagayti
// 	t_vector	*ray;//vory menq uxarkelu enq kamerayic.դիտման պատուհանների միջով կա մի տարածություն, որտեղ գտնվում են պատկերները
// 	t_vplane	*vplane;//i vot sama akno prasmotra
// 	double		dot;
// 	t_hatum		hatum;
	
// 	printf("fov=%f\n",scene->camera->fov);
	
// 	hatum.dot = __FLT_MAX__;
// 	//mez ayjm petqa stananq akno prasmotra-n,vor mez shat kogni,aranc dra menq vochmi dzev chenq kara ispravitsya
// 	vplane = get_view_plane(scene->width, scene->height, scene->camera->fov);//minch es sheshtvela vor vorpisi kap hastatvi pikselya akno prasmotra s pikselyam akno katorim mi risuyem ,petqa shirinu akno prasmotran bajanel shirinu u okna ,dra hamar es funkcian kstana scenai erk. u lenqy 
// 	//ays funckain kveradardzni այն ամենը, ինչ ձեզ անհրաժեշտ է charagayty uxarkelu(krakelu,bac toxelu) hamar
// 	x_ankyan_value = ((scene->width) / 2) * (-1);
// 	y_ankyan_value = (scene->height) / 2;
// 	printf("x_ankyan_value=%f\n", x_ankyan_value);
// 	printf("y_ankyan_value=%f\n", y_ankyan_value);
// 	printf("vplane_x=%f\n", vplane->x_pixel);
// 	printf("vplany=%f\n", vplane->y_pixel);
	
// 	t_sphere *tmp = scene->sphere;
// 	mlx_y = 0;
// 	// while (tmp)
// 	// {
// 	// 	printf("mek\n");
// 	// 	tmp = tmp->next;
// 	// }
// 	while (y_ankyan_value >= (scene->height) / 2 * (-1))
// 	{
// 		y_ray =  y_ankyan_value * vplane->y_pixel;//tetri mej grelem vor mec patuhani -400y hamynknuma poqri -0.5-in(y-i hamar 300 y hamynknuma 0.5-in),es toxov el et tvyal y koordinaty->-300y bazmapatkum enq en akno prasmotri pikseli chapi arjeqi het vor stananaq akno prasmotri vra ayn kety vorov ancnleu e charagayty
// 		x_ankyan_value = ((scene->width) / 2) * (-1);
// 		mlx_x = 0;
// 		while (x_ankyan_value <= (scene->width) / 2)
// 		{
// 			x_ray = x_ankyan_value * vplane->x_pixel;
// 				// printf("VRDS=%f\n", x_ray);
// 			//hima erb menq arden gitenq te amen angam vortexa gtnvum mer charagayti ancnelu kety
// 			ray = new_vector(x_ray, y_ray, -1);//-1 vortev uxxutyun es pahin anelu en -1ov(z-eri arancqi masina xosqy)////x_ray-@ u y_ray-@ meke -1y unenalov menq karanq arden stexcenq charagayt vory petqa zapuskat anenq depi taracutyun
// 			vec_normalize(ray );//menq stanum enq vectori normaly vorpisi inqy sharjvi tochni uxxutyunov 
// 			//hasanq en ketin vor petqa arden krakenq luchy vorpisi tesnenq et charagayty ancav objekti mijov te che
// 			// printf("%f\n", ray->x);
// 			// printf("%f\n", ray->y);
// 			// printf("%f\n", ray->z); 
// 			while (tmp)
// 			{
// 				dot = sphere_intersect(scene->camera, ray, tmp);
// 				if (dot < hatum.dot)
// 				{
// 					hatum.dot = dot;
// 					hatum.sphere = scene->sphere;
// 				}
// 				tmp = tmp->next;
// 			}
// 			if (hatum.dot == __FLT_MAX__)
// 				color = 0;
// 			else
// 				color = get_color(hatum.sphere->color.red, hatum.sphere->color.green, hatum.sphere->color.blue,\
// 					compute_light(hatum.dot, scene, ray));
// 			my_mlx_pixel_put(scene->img, mlx_x, mlx_y, color);
// 			free(ray);
// 			x_ankyan_value++;
// 			mlx_x++;
// 		}
// 		y_ankyan_value--;
// 		mlx_y++;
// 	}
// }

// t_vector	*get_ray(t_vplane *vplane, int i, int j)
// {
// 	t_vector	*v;

// 	v = malloc(sizeof(t_vector));
// 	if (!v)
// 		exit(EXIT_FAILURE);
// 	v->x = vplane->pixel_00.x + (vplane->x_pixel.x * j);
// 	v->y = vplane->pixel_00.y + (vplane->y_pixel.y * i);
// 	v->z = -1;
// 	return (v);
// }




t_vector	get_ray(t_vplane *vplane, int i, int j)
{
	// t_vector	v;

	// v.x = vplane->pixel_00.x + (vplane->x_pixel.x * j);
	// v.y = vplane->pixel_00.y + (vplane->y_pixel.y * i);
	// v.z = -1;
	// return (v);
	t_vector pixel_point;

	// Вычисление точки на виртуальной плоскости
	pixel_point = sum_vect(vplane->pixel_00, sum_vect(num_product_vect(vplane->x_pixel, j),num_product_vect(vplane->y_pixel, i)));
	// Направление луча: из центра камеры в точку на плоскости
	return vec_normalize(vec_subtract(pixel_point, vplane->camera.center));
}


// void	ray_tracing(t_scene *scene)
// {

// 	scene->i = 0;     
// 	scene->hatum.dot = __FLT_MAX__;
// 	scene->vplane = get_view_plane(scene->camera, scene->width, scene->height, scene->camera->fov);
// 	// printf("right-> %f %f %f",  scene->camera->direction.x, scene->camera->direction.y,  scene->camera->direction.z);
	
// 	while (scene->i < scene->height)
// 	{
// 		scene->j = 0;
// 		while (scene->j < scene->width)
// 		{
// 			scene->ray = get_ray(scene->vplane, scene->i, scene->j);
// 			scene->ray = vec_normalize(scene->ray);
// 			my_mlx_pixel_put(scene->img, scene->j, scene->i, color_in_current_pixel(scene));
// 			scene->j++;
// 		}
// 		scene->i++;
// 	}
// 	free(scene->vplane);
// }

// int	color_in_current_pixel(t_scene *scene)
// {
// 	int			color;
// 	t_figure	*tmp;
// 	double		closest_dot;

// 	closest_dot = __FLT_MAX__;
// 	tmp = scene->figure;
// 	closest_dot = closest_inter(scene->camera->center, scene->ray, scene->figure, &tmp);
// 	if (closest_dot == __FLT_MAX__)
// 	{
// 		color = 0;
// 	}
// 	else
// 	{
// 		// printf("ray->x=%f  ", scene->ray.x);
// 		color = get_color(tmp, scene, closest_dot);
// 	}
// 	return (color);
// }

// double	closest_inter(t_vector pos, t_vector ray, t_figure *figure, t_figure **tmp)
// {
// 	double		dot;
// 	double		closest_dot;

// 	dot = __FLT_MAX__;
// 	closest_dot = __FLT_MAX__;
// 	while (figure)
// 	{
// 		// printf("Vrdoi type=%d\n",tmp->type);
// 		// usleep(100);
// 		if (figure->type == SPHERE)
// 			dot = sphere_intersect(pos, ray, figure->sphere);
// 		else if (figure->type == PLANE)
// 			dot = plane_inter(pos, ray, figure->plane->orient, figure->plane->coords);
// 		else if (figure->type == CYLINDER)
// 			dot = cylinder_intersect(pos, ray, figure->cylinder);
// 		if (dot > 0.0 && dot < closest_dot)
// 		{
// 			closest_dot = dot;
// 			*tmp = figure;
// 		}
// 		figure = figure->next;
// 	}
// 	return (closest_dot);
// }



// t_vector	vector(double x, double y, double z)
// {
// 	t_vector	v;

// 	v.x = x;
// 	v.y = y;
// 	v.z = z;
// 	return (v);
// }

// t_vplane	*get_view_plane(t_camera *camera, double width, double hight, double fov)
// {
// 	t_vplane	*vplane;
// 	double		aspect_ratio;


// 	aspect_ratio = width / hight;
// 	//
// 	//
// 	vplane = malloc(sizeof(t_vplane));
// 	if (!vplane)
// 		exit(EXIT_FAILURE);

// 	///
// 	vplane->camera = *camera;
// 	vplane->plane_half_width = tanf((fov / 2.0) * (M_PI / 180));
// 	vplane->plane_half_height = vplane->plane_half_width / aspect_ratio;
// 	vplane->up = new_vector(0, -1, 0); // Ось "вверх" — Y
//     vplane->right = vec_cross_product(vplane->camera.direction, vplane->up); // Перпендикуляр

// 	vplane->right = vec_normalize(vplane->right); // Нормализуем
//     vplane->up = vec_cross_product(vplane->right, vplane->camera.direction); // Перпендикуляр
//     vplane->up = vec_normalize(vplane->up);//чтобы его длина стала равной 1.

// 	printf("camera direction-> %f %f %f\n",  vplane->camera.direction.x, vplane->camera.direction.y,  vplane->camera.direction.z);
// 	printf("camera center-> %f %f %f\n",  vplane->camera.center.x, vplane->camera.center.y,  vplane->camera.center.z);
	
	// printf("up-> %f %f %f\n",  vplane->up.x, vplane->up.y,  vplane->up.z);
// 	printf("right-> %f %f %f\n",  vplane->right.x, vplane->right.y,  vplane->right.z);
	
// 	///
// 	// vplane->width = vector(tmp, 0, 0);
// 	// vplane->hight = vector(0, -tmp, 0);
// 	// vplane->x_pixel = vector(vplane->width.x / WIDTH, 0, 0);
// 	// vplane->y_pixel = vector(0, vplane->hight.y / HEIGHT, 0);

// 	vplane->width = num_product_vect(vplane->right, vplane->plane_half_width * 2);
//     vplane->hight = num_product_vect(vplane->up, vplane->plane_half_height * 2);
//     vplane->x_pixel = num_product_vect(vplane->right, (vplane->plane_half_width * 2) / width);
//     vplane->y_pixel = num_product_vect(vplane->up, (vplane->plane_half_height * 2) / hight);

// 	vplane->plane_center = sum_vect(vplane->camera.center, num_product_vect(vplane->camera.direction, 1)); // Перед камерой
// 	printf("plane_center-> %f %f %f\n",  vplane->plane_center.x, vplane->plane_center.y,  vplane->plane_center.z);
    
// 	vplane->half_width = num_product_vect(vplane->right, vplane->plane_half_width);
//     vplane->half_height = num_product_vect(vplane->up, vplane->plane_half_height);
// 	vplane->pixel_00 = vector((vplane->plane_center.x - (vplane->width.x / 2)) + vplane->x_pixel.x / 2, \
// 							vplane->plane_center.y - (vplane->hight.y / 2) + vplane->y_pixel.y / 2, \
// 							-1);
//     // vplane->pixel_00 = vec_subtract(vec_subtract(vplane->plane_center, vplane->half_width), vplane->half_height);
//    vplane->pixel_00 = vec_subtract(vplane->plane_center, sum_vect(vplane->half_width, vplane->half_height));
    
	
// 	// vplane->pixel_00 = sum_vect(vec_subtract(vplane->plane_center, vplane->half_width), vplane->half_height);	printf("vplane->width.x = %f\n", vplane->width.x);
// 	printf("vplane->width.x = %f\n", vplane->width.x);
// 	printf("vplane->width.y = %f\n", vplane->width.y);
// 	printf("vplane->width.z = %f\n", vplane->width.z);
// 	printf("vplane->hight.x = %f\n", vplane->hight.x);
// 	printf("vplane->hight.y = %f\n", vplane->hight.y);
// 	printf("vplane->hight.z = %f\n", vplane->hight.z);
// 	printf("vplane->x_pixel.x = %f\n", vplane->x_pixel.x);
// 	printf("vplane->x_pixel.y = %f\n", vplane->x_pixel.y);
// 	printf("vplane->x_pixel.z = %f\n", vplane->x_pixel.z);
// 	printf("vplane->y_pixel.x = %f\n", vplane->y_pixel.x);
// 	printf("vplane->y_pixel.y = %f\n", vplane->y_pixel.y);
// 	printf("vplane->y_pixel.z = %f\n", vplane->y_pixel.z);
// 	printf("vplane->pixel_00.x = %f\n", vplane->pixel_00.x);
// 	printf("vplane->pixel_00.y = %f\n", vplane->pixel_00.y);
// 	printf("vplane->pixel_00.z = %f\n", vplane->pixel_00.z);
// 	return (vplane);
// }


// // double	sphere_intersect(t_camera *cam, t_vector ray, t_sphere *sphere)
// double	sphere_intersect(t_vector center, t_vector ray, t_sphere *sphere)
// {
// 	t_vector	cam_sphere;
// 	// double		b;
// 	// double		c;
// 	// double		d;
// 	// double		a;////
// 	t_math		math;

// 	math.a = vec_dot_product(ray, ray);/////ray=ray_direction 
// 	cam_sphere = vec_subtract(sphere->center, center);
// 	math.b = -2.0 * vec_dot_product(ray, cam_sphere);
// 	math.c = vec_dot_product(cam_sphere, cam_sphere) - sphere->radius * sphere->radius;
// 	math.disc = math.b * math.b - 4 * math.c * math.a;
// 	if (math.disc < 0)
// 		return (-1.0);
// 	// else
// 	// 	return ((-(math.b) - sqrt(math.disc)) / (2.0 * math.a));
// 	math.x1 = ((-math.b) - sqrt(math.disc)) / (2 * math.a);
// 	if (math.x1 > 0)
// 		return (math.x1);
// 	return (0);
// }

// int	get_color(t_figure *figure, t_scene *scene, double closest_dot)
// {
// 	int	r;
// 	int	g;
// 	int	b;
// 	double	bright;
// //  Если bright меньше 1, цвета будут затемнены, если больше 1 — осветлены.
// 	bright = compute_light(closest_dot, scene, figure);
// 	r = figure->color->red * bright;
// 	g = figure->color->green * bright;
// 	b = figure->color->blue * bright;
// 	if (r > 255)
// 		r = 255;
// 	if (g > 255)
// 		g = 255;
// 	if (b > 255)
// 		b = 255;
// 	return (r << 16 | g << 8 | b);//mekel es masy harcnel
// }

// t_vplane	*get_view_plane(double width, double hight, double fov)
// {
// 	t_vplane	*vplane;
// 	double	aspect_ratio = 0.0;

// 	// printf("stex=%f\n",fov);
// 	vplane = malloc(sizeof(t_vplane));
// 	if (!vplane)
// 		exit(7777777); // ErRRRRRRRRRrrOR
// 	//sovorabar nenca linumm,vor aknoi erkarutyuny aveli meca kinum qan laynutyuny,fdra hamar petqa unenanq mihat popoxakan vori mej kunenanq te erkariutyuny qani angama mec 
// 	// printf("WIDTH=%f: HEIGHT: %f\n", width, hight);
// 	aspect_ratio = (double)(width / hight);
// 	vplane->width = 2.0 * tan((fov / 2.0) * (M_PI / 180));//skzbi hamar chenq ogtagorcum fov-@ dra hamar 1 enq veragrum,heto yst fov-i veragrummy kanenq
// 	// vplane->width *= 2.0;
// 	vplane->hight = vplane->width / aspect_ratio;
// 	printf("vplanei weeeeight=%f\n",vplane->width);
// 	printf("vplanei hight=%f\n",vplane->hight);
// 	//arden karanq stananq mer pikselnery v akne prasmotra
// 	vplane->x_pixel = vplane->width / width;//chem jokum te xien x u y nuyn arjeqnery unenum??????????????????????????
// 	vplane->y_pixel = vplane->hight / hight;//ayjm menq unenq pikselnery poqr patuhani voroncov ancneluya charagaytnery
// 	printf("funkciayi mej vplane-x=%f\n",vplane->x_pixel);
// 	printf("funkciayi mej vplane-y=%f\n",vplane->y_pixel);
// 	//(M_PI / 180)=1radiani arjeqna
// 	return (vplane);
// }

// double	sphere_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere)
// {
// 	//a-n misht = 1 vortev nashi rastayanii do akna prasmotra edinica(erachap hartutyan mej)
// 	double	b;
// 	double	c;
// 	double	discr;
// 	double	dist_1;//arajin hatumna charagayti u gndi,aveli mota sa=>erevacoxna
// 	double	dist_2;//sa ayn distancian e vortex charagayty durs kga gndic=>sa heru distancian e vory menq chenq tesnelu
// 	t_vector	*cam_sphere;//sphere-to_ray
// 	// printf("diametr=%f\n",sphere->diameter);
// 	dist_1 = 0;//TES_NKARY2 
// 	dist_2 = 0;
// 	// if (sphere)
// 	// printf("exxx=%p\n",sphere);
// 		cam_sphere = vec_subtract(&cam->center, &sphere->center);
// 	// else
// 		// exit(777);
// 	b = 2 * (vec_dot_product(cam_sphere, ray));
// 	c = vec_dot_product(cam_sphere, cam_sphere) - ((sphere->radius * sphere->radius));
// 	// printf("cam_sphere->x=%f\n", cam_sphere->x);
// 	// printf("cam_sphere->y=%f\n", cam_sphere->y);
// 	// printf("cam_sphere->z=%f\n", cam_sphere->z);
// 	// printf("ray->x=%f\n", ray->x);
// 	// printf("ray->y=%f\n", ray->y);
// 	// printf("ray->z=%f\n", ray->z);

// 	// printf("for what\n");
// 	free(cam_sphere);
// 	// printf("b=%f\n", b);
// 	// printf("c=%f\n", c);
// 	discr = (b * b) - (4 * 1 * c);//a = 1;
// 	if (discr < 0)
// 	{
// 	// printf("alo ==== %f\n", discr);
// 	// {printf("hmm\n");
// 		return (0);//nshanakuma charagayty chi hatel gundy
// 	}
// 	// printf("ste4\n");
// 	dist_1 = ((b * (-1)) - sqrt(discr)) / (2 * 1);//a=1
// 	dist_2 = ((b * (-1)) + sqrt(discr)) / (2 * 1);//a=1
// 	if (dist_1 > 0)//ete gundy gtnvuma kamerayi hetevy,apa distancian klini bacasakan,isk et depqum bnakanabar gundy chi ereva dra hamar en taki if-@ grum enq > 0 
// 		return (dist_1);//menq heto pti 1i texy veradardznenq et distancian,tipne poxelu enq double funkciayi,heto et sax distancianery hamematelu enq u vory amena moty exav dra guynov nerkenq
// 	// printf("hmm\n");
// 	return (dist_2);
// 	//karoxa mez funkciaye petq ga vor vectory kbajani inchvor trvac tvi vra
// }
