/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbarsegh <vbarsegh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 19:40:50 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/08/26 14:43:19 by vbarsegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

// struct s_vector
// {
// 	float	x;
// 	float	y;
// 	float	z;
// };


// void	ray_tracing(void *mlx, void *win, t_scene *scene)
// {
// 	(void)mlx;
// 		(void)win;
// 	int	mlx_x;
// 	int	mlx_y;//ay erkusy mlx_put_piexl()funklciayi hamar en,ev dranc arjeqnery popoxvelu en 0-800 ev 0-600,qani vor //mlx_put_pixel()-@ stanuma miayn drakan tver

// 	float	x_ankyan_value;//ugl iqsa s kotoriy mi nachinayem   TES NKARY
// 	float	y_ankyan_value;//y_angle
// 	int	color;//es pahin guyneri het chenq ashxatum,zut ete luchy hatec obyekty nerkum enq spitakov,ete chhatec sevov
// 	float	x_ray;
// 	float	y_ray;//sranq koordinatner mer charagayti
// 	t_vector	*ray;//vory menq uxarkelu enq kamerayic.դիտման պատուհանների միջով կա մի տարածություն, որտեղ գտնվում են պատկերները
// 	t_vplane	*vplane;//i vot sama akno prasmotra
// 	float		dot;
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
	t_vector	v;

	// v = malloc(sizeof(t_vector));
	// if (!v)
	// 	exit(EXIT_FAILURE);
	v.x = vplane->pixel_00.x + (vplane->x_pixel.x * j);
	v.y = vplane->pixel_00.y + (vplane->y_pixel.y * i);
	v.z = -1;
	return (v);
}


void	ray_tracing(t_scene *scene)
{
	t_vplane	*vplane;
	// t_vector	ray;
	// t_figure	*tmp;
	// int			color;
	int			i;
	int			j;

	i = 0;
	j = 0;
	scene->hatum.dot = __FLT_MAX__;
	vplane = get_view_plane(scene->width, scene->height, scene->camera->fov);
	while (i < scene->height)
	{
		j = 0;
		while (j < scene->width)
		{
			scene->ray = get_ray(vplane, i, j);
			scene->ray = vec_normalize(scene->ray);
			// color_in_current_pixdel(scene);
			
			// tmp = scene->figure;
			// closest_inter(scene->figure, scene, &hatum, scene->ray, tmp);
			// if (hatum.dot == __FLT_MAX__)
			// 	color = get_color(0, 0, 0, 1);
			// else
			// 	color = get_color(hatum.sphere->color.red, hatum.sphere->color.green, hatum.sphere->color.blue, compute_light(hatum.dot, scene, scene->ray, hatum.sphere));
			// hatum.dot = __FLT_MAX__;
			// hatum.sphere = NULL;
			my_mlx_pixel_put(scene->img, j, i, color_in_current_pixdel(scene));
			// free(ray);
			j++;
		}
		i++;
	}
	free(vplane);
}

int	color_in_current_pixdel(t_scene *scene)
{
	int			color;
	t_figure	*tmp;

	tmp = scene->figure;
	// closest_inter(scene->figure, scene, scene->ray, tmp);
	closest_inter(scene->camera->center, scene->ray, tmp, scene);
	if (scene->hatum.dot == __FLT_MAX__)
		color = get_color(0, 0, 0, 1);
	else
		color = get_color(scene->hatum.figure->color->red, scene->hatum.figure->color->green, scene->hatum.figure->color->blue, 1);
	scene->hatum.dot = __FLT_MAX__;
	scene->hatum.figure = NULL;
	return (color);
}

void	closest_inter(t_vector pos, t_vector ray, t_figure *tmp, t_scene *scene)
{
	float		dot;

	while (tmp)
	{
		// printf("Vrdoi type=%d\n",tmp->type);
		// usleep(100);
		if (tmp->type == SPHERE)
			dot = sphere_intersect(pos, ray, tmp->sphere);
		if (dot > 0.0 && dot < scene->hatum.dot)
		{
			scene->hatum.dot = dot;
			scene->hatum.figure = tmp;
		}
		tmp = tmp->next;
	}
}



t_vector	vector(float x, float y, float z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vplane	*get_view_plane(float width, float hight, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;
	float		tmp;

	printf("vates\n");
	aspect_ratio = width / hight;
	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		exit(EXIT_FAILURE);
	tmp = 2.0 * tanf((fov / 2.0) * (M_PI / 180));
	vplane->width = vector(tmp, 0, 0);
	tmp = tmp / aspect_ratio;
	vplane->hight = vector(0, -tmp, 0);
	vplane->x_pixel = vector(vplane->width.x / WIDTH, 0, 0);
	vplane->y_pixel = vector(0, vplane->hight.y / HEIGHT, 0);
	vplane->pixel_00 = vector((0.0 - (vplane->width.x / 2)) + vplane->x_pixel.x / 2, \
							0.0 - (vplane->hight.y / 2) + vplane->y_pixel.y / 2, \
							-1);
	return (vplane);
}


// float	sphere_intersect(t_camera *cam, t_vector ray, t_sphere *sphere)
float	sphere_intersect(t_vector center, t_vector ray, t_sphere *sphere)
{
	t_vector	cam_sphere;
	float		b;
	float		c;
	float		d;
	float		a;////

	a = vec_dot_product(ray, ray);/////
	cam_sphere = vec_subtract(sphere->center, center);
	b = -2.0 * vec_dot_product(ray, cam_sphere);
	c = vec_dot_product(cam_sphere, cam_sphere) - sphere->radius * sphere->radius;
	d = b * b - 4 * c * a;
	if (d < 0)
		return (-1.0);
	else
		return ((-b - sqrt(d)) / (2.0 * a));
}

int	get_color(int red, int green, int blue, float bright)
{
	int	r;
	int	g;
	int	b;
//  Если bright меньше 1, цвета будут затемнены, если больше 1 — осветлены.
	r = red * bright;
	g = green * bright;
	b = blue * bright;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (r << 16 | g << 8 | b);//mekel es masy harcnel
}

// t_vplane	*get_view_plane(float width, float hight, float fov)
// {
// 	t_vplane	*vplane;
// 	float	aspect_ratio = 0.0;

// 	// printf("stex=%f\n",fov);
// 	vplane = malloc(sizeof(t_vplane));
// 	if (!vplane)
// 		exit(7777777); // ErRRRRRRRRRrrOR
// 	//sovorabar nenca linumm,vor aknoi erkarutyuny aveli meca kinum qan laynutyuny,fdra hamar petqa unenanq mihat popoxakan vori mej kunenanq te erkariutyuny qani angama mec 
// 	// printf("WIDTH=%f: HEIGHT: %f\n", width, hight);
// 	aspect_ratio = (float)(width / hight);
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

// float	sphere_intersect(t_camera *cam, t_vector *ray, t_sphere *sphere)
// {
// 	//a-n misht = 1 vortev nashi rastayanii do akna prasmotra edinica(erachap hartutyan mej)
// 	float	b;
// 	float	c;
// 	float	discr;
// 	float	dist_1;//arajin hatumna charagayti u gndi,aveli mota sa=>erevacoxna
// 	float	dist_2;//sa ayn distancian e vortex charagayty durs kga gndic=>sa heru distancian e vory menq chenq tesnelu
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
// 		return (dist_1);//menq heto pti 1i texy veradardznenq et distancian,tipne poxelu enq float funkciayi,heto et sax distancianery hamematelu enq u vory amena moty exav dra guynov nerkenq
// 	// printf("hmm\n");
// 	return (dist_2);
// 	//karoxa mez funkciaye petq ga vor vectory kbajani inchvor trvac tvi vra
// }
