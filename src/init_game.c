/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:57:56 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/31 21:08:42 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_game(t_game *game)
{
	game->interaction.translate_up = 0;
	game->interaction.translate_down = 0;
	game->interaction.translate_left = 0;
	game->interaction.translate_right = 0;
	game->interaction.zoom_in = 0;
	game->interaction.zoom_out = 0;
}