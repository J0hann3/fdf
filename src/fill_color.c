/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:56:31 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/02 17:51:06 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_color(t_game *game)
{
	size_t	i;
	float	dist;

	i = 0;
	dist = game->max.z - game->min.z;
	while (i < game->len)
	{
		game->tab[i].color = 0xFFFFFF - ((float)game->tab[i].z / (float)dist) * COLOR;
		// printf("Color : %d, z : %f, Dist:%f\n", game->tab[i].color, game->tab[i].z, dist);
		i++;
	}
}