/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:11:16 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/31 21:28:20 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_release(int keycode, t_game *game)
{
	printf("keycode release: %d\n", keycode);
	if (keycode == KEY_UP)
		game->interaction.translate_up = 0;
	else if (keycode == KEY_DOWN)
		game->interaction.translate_down = 0;
	else if (keycode == KEY_LEFT)
		game->interaction.translate_left = 0;
	else if (keycode == KEY_RIGHT)
		game->interaction.translate_right = 0;
	else if (keycode == KEY_ZOOM_IN)
		game->interaction.zoom_in = 0;
	else if (keycode == KEY_ZOOM_OUT)
		game->interaction.zoom_out = 0;
	return (0);
}

int	key(int keycode, t_game *game)
{
	printf("keycode press: %d\n", keycode);
	if (keycode == KEY_ECHAP)
		ft_close(game);
	else if (keycode == KEY_UP)
		game->interaction.translate_up = 1;
	else if (keycode == KEY_DOWN)
		game->interaction.translate_down = 1;
	else if (keycode == KEY_LEFT)
		game->interaction.translate_left = 1;
	else if (keycode == KEY_RIGHT)
		game->interaction.translate_right = 1;
	else if (keycode == KEY_ZOOM_IN)
		game->interaction.zoom_in = 1;
	else if (keycode == KEY_ZOOM_OUT)
		game->interaction.zoom_out = 1;
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

int	ft_move(t_game *game)
{
	if (game->interaction.translate_up == 1)
		ft_translate(game, (t_coordonnee_3d){0, TRANSLATION, 0});
	if (game->interaction.translate_down == 1)
		ft_translate(game, (t_coordonnee_3d){0, -TRANSLATION, 0});
	if (game->interaction.translate_left == 1)
		ft_translate(game, (t_coordonnee_3d){-TRANSLATION, 0, 0});
	if (game->interaction.translate_right == 1)
		ft_translate(game, (t_coordonnee_3d){TRANSLATION, 0, 0});
	if (game->interaction.zoom_in == 1)
		ft_zoom(game, ZOOM_IN);
	if (game->interaction.zoom_out == 1)
		ft_zoom(game, ZOOM_OUT);
	return (1);
}

int	ft_translate(t_game *game, t_coordonnee_3d origine)
{
	translation(game->tab, game->len, origine);
	bzero(game->img.addr, HEIGHT * WIDTH * 4);
	link_point(game->tab, game->len_split, game->len, &game->img, 0xFFFFFF);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	return (0);
}

int	ft_zoom(t_game *game, float zoom)
{
	apply_zoom(game->tab, game->len, zoom, (t_coordonnee_3d){0, 0, 0});
	bzero(game->img.addr, HEIGHT * WIDTH * 4);
	link_point(game->tab, game->len_split, game->len, &game->img, 0xFFFFFF);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	return (0);
}
