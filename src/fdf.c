/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:17:53 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/07 17:07:18 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	float	zoom;
	t_move	interaction;
	t_data	img;
	t_game	game;

	init_null_game(&game, &img);
	init_game(&game);
	init_move(&game, &interaction);
	parsing(argc, argv, &game);
	if (game.len <= 0)
		ft_close(&game);
	find_min_max(&game);
	game.repere.x = - ((game.max.x - game.min.x) / 2.);
	game.repere.y = - ((game.max.y - game.min.y) / 2.);
	game.repere.z = - ((game.max.z - game.min.z) / 2.);
	fill_color(&game);		//div par 0
	translation(&game, game.repere);
	game.tab_const = ft_strdup(game.tab, game.len, &game);
	rotate_plan_isometrique(game.tab, NULL, game.len);
	rotate_plan_z(game.tab, game.len, -(M_PI / 3.0));
	zoom = center_plan(game.tab, game.len, &game.repere);
	apply_zoom(&game, zoom);
	link_point(&game);
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img->img, 0, 0);
	mlx_do_key_autorepeatoff(game.mlx);
	mlx_hook(game.mlx_win, 02, (1L<<0), key, &game);
	mlx_hook(game.mlx_win, 03, (1L<<1), key_release, &game);
	mlx_hook(game.mlx_win, 04, (1L<<2), mouse, &game);
	mlx_hook(game.mlx_win, 17, (1L<<5), ft_close, &game);
	mlx_loop_hook(game.mlx, &ft_move, &game);
	mlx_loop(game.mlx);
	return (0);
}

	//test octave
	// draw_line((t_coordonnee_2d){700, 700}, (t_coordonnee_2d){1000, 800}, &img, 0x11FF);
	// printf("--------------------------\n");
	// draw_line((t_coordonnee_2d){700, 700}, (t_coordonnee_2d){800, 1000}, &img, 0x00FF);
	// printf("--------------------------\n");
	// draw_line((t_coordonnee_2d){700, 700}, (t_coordonnee_2d){600, 1000}, &img, 0xFFFF);
	// printf("--------------------------\n");
	// draw_line((t_coordonnee_2d){700, 700}, (t_coordonnee_2d){400, 800}, &img, 0xEEFF);
	// printf("--------------------------\n");
	// draw_line((t_coordonnee_2d){700, 700}, (t_coordonnee_2d){400, 600}, &img, 0xDDFF);
	// printf("--------------------------\n");
	// draw_line((t_coordonnee_2d){700, 700}, (t_coordonnee_2d){600, 400}, &img, 0xCCFF);
	// printf("--------------------------\n");
	// draw_line((t_coordonnee_2d){700, 700}, (t_coordonnee_2d){800, 400}, &img, 0xBBFF);
	// printf("--------------------------\n");
	// draw_line((t_coordonnee_2d){0, 51}, (t_coordonnee_2d){501, 45}, &img, 0xff00);

	// printf(" %d %s\n", __LINE__, __FILE__);
	