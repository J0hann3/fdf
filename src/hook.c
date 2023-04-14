/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:23:03 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/08 17:25:15 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_hook(t_game *game)
{
	mlx_hook(game->mlx_win, 02, (1L << 0), key, game);
	mlx_hook(game->mlx_win, 03, (1L << 1), key_release, game);
	mlx_hook(game->mlx_win, 04, (1L << 2), mouse, game);
	mlx_hook(game->mlx_win, 17, (1L << 5), ft_close, game);
}
