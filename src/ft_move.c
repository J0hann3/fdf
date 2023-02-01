/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:11:16 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/01 16:34:11 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_release(int keycode, t_game *game)
{
	// printf("keycode release: %d\n", keycode);
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
	else if (keycode == KEY_ROTATION_A)
		game->interaction.rotate_a = 0;
	else if (keycode == KEY_ROTATION_W)
		game->interaction.rotate_w = 0;
	else if (keycode == KEY_ROTATION_D)
		game->interaction.rotate_d = 0;
	else if (keycode == KEY_ROTATION_S)
		game->interaction.rotate_s = 0;
	return (1);
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
	else if (keycode == KEY_ROTATION_A)
		game->interaction.rotate_a = 1;
	else if (keycode == KEY_ROTATION_W)
		game->interaction.rotate_w = 1;
	else if (keycode == KEY_ROTATION_D)
		game->interaction.rotate_d = 1;
	else if (keycode == KEY_ROTATION_S)
		game->interaction.rotate_s = 1;
	return (1);
}

int	ft_move(t_game *game)
{
	if (game->interaction.translate_up == 1)
		ft_translate(game, (t_coordonnee_3d){0, -TRANSLATION, 0});
	if (game->interaction.translate_down == 1)
		ft_translate(game, (t_coordonnee_3d){0, TRANSLATION, 0});
	if (game->interaction.translate_left == 1)
		ft_translate(game, (t_coordonnee_3d){-TRANSLATION, 0, 0});
	if (game->interaction.translate_right == 1)
		ft_translate(game, (t_coordonnee_3d){TRANSLATION, 0, 0});
	if (game->interaction.zoom_in == 1)
		ft_zoom(game, ZOOM_IN);
	if (game->interaction.zoom_out == 1)
		ft_zoom(game, ZOOM_OUT);
	if (game->interaction.rotate_a == 1)
		ft_rotate(game, -ROTATION, 'y');
	if (game->interaction.rotate_w == 1)
		ft_rotate(game, -ROTATION, 'x');
	if (game->interaction.rotate_d == 1)
		ft_rotate(game, ROTATION, 'y');
	if (game->interaction.rotate_s == 1)
		ft_rotate(game, ROTATION, 'x');
	return (1);
}

int	ft_rotate(t_game *game, float angle, char plan)
{
	if (plan == 'y')
		rotate_plan_y(game->tab, game->len, angle);
	else if (plan == 'z')
		rotate_plan_z(game->tab, game->len, angle);
	else if (plan == 'x')
		rotate_plan_x(game->tab, game->len, angle);
	bzero(game->img.addr, HEIGHT * WIDTH * 4);
	link_point(game, 0xFFFFFF);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	return (0);
}

int	ft_translate(t_game *game, t_coordonnee_3d origine)
{
	translation(game, origine);
	bzero(game->img.addr, HEIGHT * WIDTH * 4);
	link_point(game, 0xFFFFFF);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	return (0);
}

int	ft_zoom(t_game *game, float zoom)
{
	apply_zoom(game, zoom);
	bzero(game->img.addr, HEIGHT * WIDTH * 4);
	link_point(game, 0xFFFFFF);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	return (0);
}

int	ft_close(t_game *mlx)
{
	mlx_do_key_autorepeaton(mlx->mlx);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx->tab);
	exit(EXIT_SUCCESS);
}
