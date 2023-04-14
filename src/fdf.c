/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:17:53 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/21 14:21:58 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_move	interaction;
	t_data	img;
	t_game	game;

	init_null_game(&game, &img);
	parsing(argc, argv, &game);
	if (game.len <= 0)
		ft_close(&game);
	init_game(&game);
	init_move(&game, &interaction);
	find_min_max(&game);
	game.repere.x = - ((game.max.x - game.min.x) / 2.);
	game.repere.y = - ((game.max.y - game.min.y) / 2.);
	game.repere.z = - ((game.max.z - game.min.z) / 2.);
	fill_color(&game);
	translation(&game, game.repere);
	game.tab_const = ft_strdup(game.tab, game.len, &game);
	ft_projection_iso(&game);
	mlx_do_key_autorepeatoff(game.mlx);
	ft_hook(&game);
	mlx_loop_hook(game.mlx, &ft_move, &game);
	mlx_loop(game.mlx);
	return (0);
}
