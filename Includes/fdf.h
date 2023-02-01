/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:32:17 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/01 16:12:34 by jvigny           ###   ########.fr       */
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

# define KEY_ROTATION_A 97
# define KEY_ROTATION_W 119
# define KEY_ROTATION_D 100
# define KEY_ROTATION_S 115

# define TRANSLATION 0.25
# define ZOOM_IN 1.0001
# define ZOOM_OUT 0.9999
# define ROTATION 0.0001

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
	int	rotate_a;
	int	rotate_w;
	int	rotate_d;
	int	rotate_s;
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
	t_data			img;
	t_coordonnee_3d	*tab;
	void			*mlx;
	void			*mlx_win;
	t_move			interaction;
	size_t			len;
	size_t			len_split;
	t_coordonnee_3d	repere;
}	t_game;

// ------ Utils ------
double	ft_abs(double a);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
void	free_split(char **res);
char	*get_next_line(int fd);
t_coordonnee_3d	sub(t_coordonnee_3d a, t_coordonnee_3d b);

int		init_game(t_game *game);
void	init_move(t_game *game);

// ------ Draw ------
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_coordonnee_3d pt1, t_coordonnee_3d pt2, t_data *data,
			int color);
void	link_point(t_game *game, int color);

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
int		ft_rotate(t_game *game, float angle, char plan);

// ------ Parsing -----
size_t	ft_fdflen(char *str, size_t *len_line);
void	ft_fill_tab(char *str, t_coordonnee_3d	*tab, int len_line);

// ------ Zoom ------
float	center_plan(t_coordonnee_3d *tab, size_t len, t_coordonnee_3d *origine);
void	apply_zoom(t_game *game, float zoom);

// ------ Translation ------
void	translation(t_game *game, t_coordonnee_3d origine);

// ------ Not use -------
void	add_z(t_coordonnee_3d *tab, size_t len);

// ------ Affichage -------
void	ft_print(t_coordonnee_3d *tab, size_t len);
void	ft_printf_point_of_tab(t_coordonnee_3d *tab_3d, size_t len, t_data *data);

#endif