/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:49:46 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/02 14:06:10 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_release(int keycode, t_game *game)
{
	// printf("keycode release: %d\n", keycode);
	if (keycode == KEY_UP)
		game->interaction->translate_up = 0;
	else if (keycode == KEY_DOWN)
		game->interaction->translate_down = 0;
	else if (keycode == KEY_LEFT)
		game->interaction->translate_left = 0;
	else if (keycode == KEY_RIGHT)
		game->interaction->translate_right = 0;
	else if (keycode == KEY_ZOOM_IN)
		game->interaction->zoom_in = 0;
	else if (keycode == KEY_ZOOM_OUT)
		game->interaction->zoom_out = 0;
	else if (keycode == KEY_ROTATION_A)
		game->interaction->rotate_a = 0;
	else if (keycode == KEY_ROTATION_W)
		game->interaction->rotate_w = 0;
	else if (keycode == KEY_ROTATION_D)
		game->interaction->rotate_d = 0;
	else if (keycode == KEY_ROTATION_S)
		game->interaction->rotate_s = 0;
	return (1);
}

int	key(int keycode, t_game *game)
{
	// printf("keycode press: %d\n", keycode);
	if (keycode == KEY_ECHAP)
		ft_close(game);
	else if (keycode == KEY_UP)
		game->interaction->translate_up = 1;
	else if (keycode == KEY_DOWN)
		game->interaction->translate_down = 1;
	else if (keycode == KEY_LEFT)
		game->interaction->translate_left = 1;
	else if (keycode == KEY_RIGHT)
		game->interaction->translate_right = 1;
	else if (keycode == KEY_ZOOM_IN)
		game->interaction->zoom_in = 1;
	else if (keycode == KEY_ZOOM_OUT)
		game->interaction->zoom_out = 1;
	else if (keycode == KEY_ROTATION_A)
		game->interaction->rotate_a = 1;
	else if (keycode == KEY_ROTATION_W)
		game->interaction->rotate_w = 1;
	else if (keycode == KEY_ROTATION_D)
		game->interaction->rotate_d = 1;
	else if (keycode == KEY_ROTATION_S)
		game->interaction->rotate_s = 1;
	return (1);
}

int	mouse(int keycode, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	// printf("mouse press: %d\n", keycode);
	if (keycode == KEY_SCROLL_UP)
		ft_zoom(game, ZOOM_IN_SCROLL);
	else if (keycode == KEY_SCROLL_DOWN)
		ft_zoom(game, ZOOM_OUT_SCROLL);
	return (1);
}
