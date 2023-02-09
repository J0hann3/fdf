/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:39:55 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/09 12:49:57 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_projection_iso(t_game *game)
{
	float	zoom;

	rotate_plan_isometrique(game->tab, game->tab_const, game->len);
	rotate_plan_z(game->tab, game->len, -(M_PI / 3.0));
	zoom = center_plan(game->tab, game->len, &game->repere);
	apply_zoom(game, zoom);
	ft_bzero(game->img->addr, HEIGHT * WIDTH * 4);
	link_point(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
	return (0);
}

int	ft_projection_cabinet(t_game *game)
{
	float	zoom;

	rotate_plan_cabinet(game->tab, game->tab_const, game->len);
	zoom = center_plan(game->tab, game->len, &game->repere);
	apply_zoom(game, zoom);
	ft_bzero(game->img->addr, HEIGHT * WIDTH * 4);
	link_point(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->img, 0, 0);
	return (0);
}
