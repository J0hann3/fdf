/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:56:31 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/09 12:37:44 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_color(t_game *game)
{
	unsigned int	i;
	float			dist;
	t_color_f		t_gradient;

	i = 0;
	dist = game->max.z - game->min.z;
	if (dist == 0)
	{
		while (i < game->len)
		{
			game->tab[i].color.color = COLOR_2;
			++i;
		}
		return ;
	}
	t_gradient = gradient((t_color){COLOR_2}, (t_color){COLOR_1}, game->min.z,
			game->max.z);
	while (i < game->len)
	{
		game->tab[i].color.color = c_color((t_color){COLOR_2}, t_gradient,
				game->tab[i].z, game->min.z);
		++i;
	}
}
