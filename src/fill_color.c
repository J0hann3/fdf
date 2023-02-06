/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:56:31 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/06 13:05:57 by jvigny           ###   ########.fr       */
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
		game->tab[i].color.color = 0x00FFFFFF - (((float)game->tab[i].z / (float)dist)
				* (0x00FFFFFF - COLOR));
		// if (game->tab[i].color.color == 0x00FFFFFF)
		// 	game->tab[i].color.color = 0x000000ff;
		// printf("Color : %x\n", game->tab[i].color.color);
		i++;
	}
}
