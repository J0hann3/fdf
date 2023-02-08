/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_plan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:03:03 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/08 11:33:20 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	center_plan(t_coordonnee_3d *tab, unsigned int len,
		t_coordonnee_3d *origine)
{
	unsigned int	i;
	float			min_x;
	float			max_x;
	float			min_y;
	float			max_y;
	float			y;
	float			x;

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
	if (x < y)
		return (x);
	return (y);
}

void	apply_zoom(t_game *game, float zoom)
{
	unsigned int	i;

	i = 0;
	while (i < game->len)
	{
		game->tab[i].x = game->tab[i].x * zoom;
		game->tab[i].y = game->tab[i].y * zoom;
		game->tab[i].z = game->tab[i].z * zoom;
		i++;
	}
	game->repere.x = game->repere.x * zoom;
	game->repere.y = game->repere.y * zoom;
	game->repere.z = game->repere.z * zoom;
}
