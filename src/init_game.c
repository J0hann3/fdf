/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 20:57:56 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/02 13:01:48 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_game(t_game *game, t_data *img)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (0);
	game->mlx_win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "FdF");
	if (game->mlx_win == NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		return (0);
	}
	game->img = img;
	game->img->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (game->img->img == NULL)
		return (0);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->octets_per_pixel, &game->img->line_length,
			&game->img->endian);
	game->img->octets_per_pixel = game->img->octets_per_pixel / 8;
	return (1);
}

void	init_move(t_game *game, t_move *move)
{
	move->translate_up = 0;
	move->translate_down = 0;
	move->translate_left = 0;
	move->translate_right = 0;
	move->zoom_in = 0;
	move->zoom_out = 0;
	move->rotate_a = 0;
	move->rotate_w = 0;
	move->rotate_d = 0;
	move->rotate_s = 0;
	game->interaction = move;
}
