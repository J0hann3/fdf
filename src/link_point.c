/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:46:42 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/08 11:37:17 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	link_point_vertical(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (j * game->len_split < game->len - game->len_split)
	{
		i = 0;
		while (i < game->len_split)
		{
			draw_line(sub(game->tab[game->len_split * j + i], game->repere),
				sub(game->tab[game->len_split * (j + 1) + i], game->repere),
				game->img);
			i++;
		}
		j++;
	}
}

void	link_point(t_game *game)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (j * game->len_split < game->len)
	{
		i = 0;
		while (i < game->len_split - 1)
		{
			draw_line(sub((game->tab[game->len_split * j + i]), game->repere),
				sub(game->tab[game->len_split * j + i + 1], game->repere),
				game->img);
			i++;
		}
		j++;
	}
	link_point_vertical(game);
}
