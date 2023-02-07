/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:30:13 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/07 15:01:13 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	error(t_game *mlx)
{
	perror("Error");
	if (mlx->mlx != NULL)
	{
		if (mlx->img->img != NULL)
			mlx_destroy_image(mlx->mlx, mlx->img->img);
		if (mlx->mlx_win != NULL)
			mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		mlx_do_key_autorepeaton(mlx->mlx);
		mlx_destroy_display(mlx->mlx);
	}
	free(mlx->mlx);
	free(mlx->tab);
	free(mlx->tab_const);
	exit(EXIT_FAILURE);
}
