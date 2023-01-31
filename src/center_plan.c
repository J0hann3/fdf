/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_plan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:03:03 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/30 11:58:59 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	center_plan(t_coordonnee_3d *tab, size_t len, t_coordonnee_3d *origine)
{
	size_t	i;
	float		min_x;
	float		max_x;
	float		min_y;
	float		max_y;
	float		y;
	float		x;

	i = 0;
	min_x = tab[i].x;
	max_x = tab[i].x;
	min_y = tab[i].y;
	max_y = tab[i].y;
	while (i < len)
	{
		if (tab[i].x < min_x)
			min_x = tab[i].x;
		if (tab[i].x > max_x)
			max_x = tab[i].x;
		if (tab[i].y < min_y)
			min_y = tab[i].y;
		if (tab[i].y > max_y)
			max_y = tab[i].y;
		i++;
	}
	origine->x = min_x;
	origine->y = min_y;
	x = WIDTH / (max_x - min_x);
	y = HEIGHT / (max_y - min_y);
	// printf("min : %d	max : %d	X : %d	Y : %d min : %d	max : %d\n",min_x, max_x, x, y, min_y, max_y);
	if (x < y)
		return (x);
	return (y);
}

void	apply_zoom(t_coordonnee_3d *tab_3d, size_t len, float zoom, t_coordonnee_3d origine)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		tab_3d[i].x = (tab_3d[i].x + ft_abs(origine.x)) * zoom;
		tab_3d[i].y = (tab_3d[i].y + ft_abs(origine.y)) * zoom;
		i++;
	}
}
