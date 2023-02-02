/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:46:42 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/02 15:23:52 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	link_point(t_game *game)
{
	size_t	i;
	size_t	j;

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