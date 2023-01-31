/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:17:53 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/31 19:21:12 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*\*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * data->octets_per_pixel);
	*(unsigned int*)dst = color;
}

int	ft_close(t_game *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	// mlx_destroy_image(mlx->mlx, mlx->background.img);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free(mlx->tab);
	exit(EXIT_SUCCESS);
}

double	ft_abs(double a)
{
	if (a < 0)
		a = -a;
	return (a);
}

void	draw_grille(t_data *img)
{
	int	i = 0;
	int j;
	while (i < HEIGHT)
	{
		j = 0; 
		while(j < WIDTH)
		{
			my_mlx_pixel_put(img, j, i, 0xFFFFFF);
			j++;
		}
		i = i + 50;
	}
	i = 0;
	while (i < WIDTH)
	{
		j = 0; 
		while(j < HEIGHT)
		{
			my_mlx_pixel_put(img, i, j, 0xFFFFFF);
			j++;
		}
		i = i + 50;
	}
}

int	main(int argc, char **argv)
{
	float				zoom;
	t_coordonnee_3d	origine;
	t_game			game;


	printf(" %d %s\n", __LINE__, __FILE__);

	// ------DRAW------
	game.mlx = mlx_init();
	if (game.mlx == NULL)
		return (1);
	game.mlx_win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "FdF");
	if (game.mlx_win == NULL)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return (1);
	}
	//background
	// game.background.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	// game.background.addr = mlx_get_data_addr(game.background.img,
	// 		&game.background.octets_per_pixel, &game.background.line_length, &game.background.endian);
	// game.background.octets_per_pixel = game.background.octets_per_pixel / 8;
	// if (game.background.img == NULL)
	// 	return (1);
	// -------Parsing--------
	if (argc != 2)
	{
		write(1, "Nombre d'arguments incorrect\n", 29);
		return (1);
	}
	game.len = ft_fdflen(argv[1], &game.len_split);
	game.tab = malloc(sizeof(t_coordonnee_3d) * game.len);
	if (game.tab == NULL)
	{
		free(game.tab);
		return (1);
	}
	ft_fill_tab(argv[1], game.tab, game.len_split);
	// -----ROTATE------
	rotate_plan_isometrique(game.tab, game.len);
	rotate_plan_z(game.tab, game.len, -(M_PI / 3));
	zoom = center_plan(game.tab, game.len, &origine);
	apply_zoom(game.tab, game.len, zoom, origine);
	//image
	game.img.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	if (game.img.img == NULL)
		return (1);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.octets_per_pixel, &game.img.line_length,
			&game.img.endian);
	game.img.octets_per_pixel = game.img.octets_per_pixel / 8;
	//Dessine
	link_point(game.tab, game.len_split, game.len, &game.img, 0xFF0000);
	game.x = 0;
	game.y = 0;
	mlx_put_image_to_window(game.mlx, game.mlx_win, game.img.img, game.x, game.y);
	mlx_key_hook(game.mlx_win, &key, &game);
	mlx_hook(game.mlx_win, 17, 0, &ft_close, &game);
	mlx_loop(game.mlx);
	return (0);
}



// //test octave
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

/**/
