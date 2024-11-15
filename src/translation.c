/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:30:14 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/07 15:27:08 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translation(t_game *game, t_coordonnee_3d origine)
{
	unsigned int	i;

	i = 0;
	while (i < game->len)
	{
		game->tab[i].x = game->tab[i].x + origine.x;
		game->tab[i].y = game->tab[i].y + origine.y;
		game->tab[i].z = game->tab[i].z + origine.z;
		i++;
	}
}

void	translation_repere(t_game *game, t_coordonnee_3d origine)
{
	game->repere.x = game->repere.x + origine.x;
	game->repere.y = game->repere.y + origine.y;
	game->repere.z = game->repere.z + origine.z;
}
