/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:11:16 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/30 16:55:08 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key(int keycode, t_game *game)
{
	// printf("keycode : %d\n", keycode);
	if (keycode == KEY_ECHAP)
		ft_close(game);
	else if (keycode == KEY_UP)
		ft_move(game, (t_coordonnee_3d){0, -TRANSLATION, 0});
	else if (keycode == KEY_DOWN)
		ft_move(game, (t_coordonnee_3d){0, TRANSLATION, 0});
	else if (keycode == KEY_LEFT)
		ft_move(game, (t_coordonnee_3d){-TRANSLATION, 0, 0});
	else if (keycode == KEY_RIGHT)
		ft_move(game, (t_coordonnee_3d){TRANSLATION, 0, 0});
	else if (keycode == KEY_ZOOM_IN)
		ft_zoom(game, ZOOM_IN);
	else if (keycode == KEY_ZOOM_OUT)
		ft_zoom(game, ZOOM_OUT);
		
	// else if (keycode == KEY_ZOOM_OUT)
	// 	ft_rotate(game, ZOOM_OUT);
	// else if (keycode == KEY_ZOOM_OUT)
	// 	ft_rotate(game, ZOOM_OUT);
	// else if (keycode == KEY_ZOOM_OUT)
	// 	ft_rotate(game, ZOOM_OUT);
	// else if (keycode == KEY_ZOOM_OUT)
	// 	ft_rotate(game, ZOOM_OUT);
	return (0);
}

int	ft_move(t_game *game, t_coordonnee_3d origine)
{
	translation(game->tab, game->len, origine);
	bzero(game->img.addr, HEIGHT * WIDTH * 4);
	link_point(game->tab, game->len_split, game->len, &game->img, 0xFFFFFF);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, game->x, game->y);
	return (0);
}

int	ft_zoom(t_game *game, float zoom)
{
	apply_zoom(game->tab, game->len, zoom, (t_coordonnee_3d){0, 0, 0});
	bzero(game->img.addr, HEIGHT * WIDTH * 4);
	link_point(game->tab, game->len_split, game->len, &game->img, 0xFFFFFF);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, game->x, game->y);
	return (0);
}
