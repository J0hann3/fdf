/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:32:17 by jvigny            #+#    #+#             */
/*   Updated: 2023/01/31 21:56:53 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"

# ifndef WIDTH
#  define WIDTH 1000
# endif

# ifndef HEIGHT
#  define HEIGHT 1000
# endif

# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_LEFT 65361

# define KEY_ECHAP 65307

# define KEY_ZOOM_IN 65451
# define KEY_ZOOM_OUT 65453

# define TRANSLATION 5
# define ZOOM_IN 1.1
# define ZOOM_OUT 0.9

typedef struct s_coordonnee_3d
{
	float	x;
	float	y;
	float	z;
}	t_coordonnee_3d;

typedef struct s_move
{
	int	zoom_in;
	int	zoom_out;
	int	translate_up;
	int	translate_down;
	int	translate_left;
	int	translate_right;
	int	rotate_z;
	int	rotate_x;
	int	rotate_y;
}	t_move;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		octets_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	t_coordonnee_3d	*tab;
	size_t			len;
	size_t			len_split;
	t_move			interaction;
	t_data			img;
}	t_game;

// ------ Utils ------
double	ft_abs(double a);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	free_split(char **res);
char	*get_next_line(int fd);

void	init_game(t_game *game);

// ------ Draw ------
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_coordonnee_3d pt1, t_coordonnee_3d pt2, t_data *data,
			int color);
void	link_point(t_coordonnee_3d *tab, size_t len_split, size_t len,
			t_data *data, int color);

// ------ Rotate ------
void	rotate_plan_x(t_coordonnee_3d *tab_3d, size_t len, double rotation);
void	rotate_plan_y(t_coordonnee_3d *tab_3d, size_t len, double rotation);
void	rotate_plan_z(t_coordonnee_3d *tab_3d, size_t len, double rotation);
void	rotate_plan_isometrique(t_coordonnee_3d *tab_3d, size_t len);

// ----- Keycode -----
int		key(int keycode, t_game *mlx);
int		key_release(int keycode, t_game *game);
int		ft_translate(t_game *game, t_coordonnee_3d origine);
int		ft_move(t_game *mlx);
int		ft_close(t_game *mlx);
int		ft_zoom(t_game *game, float zoom);

// ------ Parsing -----
size_t	ft_fdflen(char *str, size_t *len_line);
void	ft_fill_tab(char *str, t_coordonnee_3d	*tab, int len_line);

// ------ Zoom ------
float	center_plan(t_coordonnee_3d *tab, size_t len, t_coordonnee_3d *origine);
void	apply_zoom(t_coordonnee_3d *tab_3d, size_t len, float zoom, t_coordonnee_3d origine);

// ------ Translation ------
void	translation(t_coordonnee_3d *tab, size_t len, t_coordonnee_3d origine);

// ------ Not use -------
void	add_z(t_coordonnee_3d *tab, size_t len);

// ------ Affichage -------
void	ft_print(t_coordonnee_3d *tab, size_t len);
void	ft_printf_point_of_tab(t_coordonnee_3d *tab_3d, size_t len, t_data *data);

#endif