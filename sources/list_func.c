/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adel <adel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:27:57 by vbarsegh          #+#    #+#             */
/*   Updated: 2024/12/11 13:26:36 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_light	*lst_create_light(t_scene *scene, char **matrix)
{
	t_light	*light;

	light = parse_light(matrix, scene);
	light->next = NULL;
	return (light);
}

void	ft_lstadd_back_light(t_light **lst, t_light *new)
{
	t_light	*ptr;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = ft_lstlast_light(*lst);
	ptr -> next = new;
}

t_light	*ft_lstlast_light(t_light *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_figure	*ft_lstlast_figure(t_figure *figure)
{
	if (figure == NULL)
		return (NULL);
	while (figure && figure->next)
		figure = figure->next;
	return (figure);
}

void	ft_lstadd_back_figure(t_figure **figure, t_figure *new)
{
	t_figure	*ptr;

	if (!*figure)
	{
		*figure = new;
		return ;
	}
	ptr = ft_lstlast_figure(*figure);
	ptr -> next = new;
}
