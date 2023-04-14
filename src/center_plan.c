/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_plan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:03:03 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/08 17:46:39 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	center_plan(t_coordonnee_3d *tab, unsigned int len,
		t_coordonnee_3d *origine)
{
	unsigned int	i;
	float			max_x;
	float			max_y;

	i = 0;
	origine->x = tab[i].x;
	max_x = tab[i].x;
	origine->y = tab[i].y;
	max_y = tab[i].y;
	while (++i < len)
	{
		if (tab[i].x < origine->x)
			origine->x = tab[i].x;
		if (tab[i].x > max_x)
			max_x = tab[i].x;
		if (tab[i].y < origine->y)
			origine->y = tab[i].y;
		if (tab[i].y > max_y)
			max_y = tab[i].y;
	}
	max_x = WIDTH / (max_x - origine->x);
	max_y = HEIGHT / (max_y - origine->y);
	if (max_x < max_y)
		return (max_x);
	return (max_y);
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
