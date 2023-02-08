/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:56:31 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/08 11:38:51 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_color(t_game *game)
{
	unsigned int	i;
	float			dist;

	i = 0;
	dist = game->max.z - game->min.z;
	if (dist == 0)
	{
		while (i < game->len)
		{
			game->tab[i].color.color = 0xFFFFFF;
			++i;
		}
	}
	while (i < game->len)
	{
		game->tab[i].color.color = 0xFFFFFF - (((float)game->tab[i].z
					/ (float)dist) * (0xFFFFFF - COLOR));
		++i;
	}
}
