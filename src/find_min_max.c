/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:06:03 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/02 13:11:57 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_min_max(t_game *game)
{
	size_t	i;

	i = 0;
	game->min.x = game->tab[0].x;
	game->min.y = game->tab[0].y;
	game->min.z = game->tab[0].z;
	game->max.x = game->tab[0].x;
	game->max.y = game->tab[0].y;
	game->max.z = game->tab[0].z;
	while (i < game->len)
	{
		if (game->tab[i].x < game->min.x)
			game->min.x = game->tab[i].x;
		if (game->tab[i].x > game->max.x)
			game->max.x = game->tab[i].x;
		if (game->tab[i].y < game->min.y)
			game->min.y = game->tab[i].y;
		if (game->tab[i].y > game->max.y)
			game->max.y = game->tab[i].y;
		if (game->tab[i].z < game->min.z)
			game->min.z = game->tab[i].z;
		if (game->tab[i].z > game->max.z)
			game->max.z = game->tab[i].z;
		i++;
	}
}
