/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:11:16 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/02 15:24:24 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_move(t_game *game)
{
	if (game->interaction->translate_up == 1)
		ft_translate(game, (t_coordonnee_3d){0, TRANSLATION, 0, 0});
	if (game->interaction->translate_down == 1)
		ft_translate(game, (t_coordonnee_3d){0, -TRANSLATION, 0, 0});
	if (game->interaction->translate_left == 1)
		ft_translate(game, (t_coordonnee_3d){TRANSLATION, 0, 0, 0});
	if (game->interaction->translate_right == 1)
		ft_translate(game, (t_coordonnee_3d){-TRANSLATION, 0, 0, 0});
	if (game->interaction->zoom_in == 1)
		ft_zoom(game, ZOOM_IN);
	if (game->interaction->zoom_out == 1)
		ft_zoom(game, ZOOM_OUT);
	if (game->interaction->rotate_a == 1)
		ft_rotate(game, -ROTATION, 'y');
	if (game->interaction->rotate_w == 1)
		ft_rotate(game, -ROTATION, 'x');
	if (game->interaction->rotate_d == 1)
		ft_rotate(game, ROTATION, 'y');
	if (game->interaction->rotate_s == 1)
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
	bzero(game->img->addr, HEIGHT * WIDTH * 4);
	link_point(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
	return (0);
}

int	ft_translate(t_game *game, t_coordonnee_3d origine)
{
	translation_repere(game, origine);
	bzero(game->img->addr, HEIGHT * WIDTH * 4);
	link_point(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
	return (0);
}

int	ft_zoom(t_game *game, float zoom)
{
	apply_zoom(game, zoom);
	bzero(game->img->addr, HEIGHT * WIDTH * 4);
	link_point(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
	return (0);
}

int	ft_close(t_game *mlx)
{
	mlx_do_key_autorepeaton(mlx->mlx);
	mlx_destroy_image(mlx->mlx, mlx->img->img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx->tab);
	exit(EXIT_SUCCESS);
}
