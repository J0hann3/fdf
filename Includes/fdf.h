/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvigny <jvigny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:32:17 by jvigny            #+#    #+#             */
/*   Updated: 2023/02/21 14:32:29 by jvigny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
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

# ifndef COLOR_1
#  define COLOR_1 0xFF00FF
# endif

# ifndef COLOR_2
#  define COLOR_2 0x6666FF
# endif

# ifndef M_PI
#  define M_PI 3.1415926535897932384626433832795028841
# endif

# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_LEFT 65361

# define KEY_ECHAP 65307

# define KEY_ZOOM_IN 65451
# define KEY_ZOOM_OUT 65453
# define KEY_SCROLL_UP 4
# define KEY_SCROLL_DOWN 5

# define KEY_ROTATION_A 97
# define KEY_ROTATION_W 119
# define KEY_ROTATION_D 100
# define KEY_ROTATION_S 115

# define KEY_I 105
# define KEY_P 112

# define TRANSLATION 0.45
# define ZOOM_IN_SCROLL 1.01
# define ZOOM_OUT_SCROLL 0.99
# define ZOOM_IN 1.001
# define ZOOM_OUT 0.999
# define ROTATION 0.001

typedef struct s_trigo
{
	double	sin;
	double	cos;
}	t_trigo;

typedef union u_color
{
	unsigned int	color;
	struct
	{
		unsigned char	blue;
		unsigned char	green;
		unsigned char	red;
		unsigned char	alpha;
	};
}	t_color;

typedef struct u_color_f
{
	float	blue;
	float	green;
	float	red;
}	t_color_f;

typedef struct s_line_draw
{
	int			dx;
	int			dy;
	int			x;
	int			y;
	int			add;
	double		a;
	double		error;
	t_color_f	e_color;
}	t_line_draw;

typedef struct s_coordonnee_3d
{
	float			x;
	float			y;
	float			z;
	t_color			color;
}	t_coordonnee_3d;

typedef struct s_move
{
	short	zoom_in;
	short	zoom_out;
	short	translate_up;
	short	translate_down;
	short	translate_left;
	short	translate_right;
	short	rotate_a;
	short	rotate_w;
	short	rotate_d;
	short	rotate_s;
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
	t_coordonnee_3d	*tab;
	t_coordonnee_3d	*tab_const;
	t_move			*interaction;
	t_data			*img;
	void			*mlx;
	void			*mlx_win;
	unsigned int	len;
	unsigned int	len_split;
	t_coordonnee_3d	repere;
	t_coordonnee_3d	min;
	t_coordonnee_3d	max;
}	t_game;

// ------ Utils ------
void			ft_bzero(void *s, unsigned int n);
double			ft_abs(double a);
int				ft_atoi(const char *str);
unsigned int	ft_strlen(const char *s);
char			**ft_split(char const *s, char c);
void			free_split(char **res);
char			*get_next_line(int fd);
t_coordonnee_3d	sub(t_coordonnee_3d a, t_coordonnee_3d b);
t_coordonnee_3d	*ft_strdup(const t_coordonnee_3d *s, unsigned int len,
					t_game *game);
int				error(t_game *mlx, int boolean);
t_trigo			fill_trigo(double angle);
size_t			ft_strlcpy(char *dest, const char *src, size_t n);

// ------ Init ------
void			init_null_game(t_game *game, t_data *img);
void			init_game(t_game *game);
void			init_move(t_game *game, t_move *move);
void			find_min_max(t_game *game);

void			fill_color(t_game *game);

// ------ Draw ------
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			line_diagonale_haut(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
					t_data *data);
void			line_diagonale_bas(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
					t_data *data);
void			draw_line(t_coordonnee_3d pt1, t_coordonnee_3d pt2,
					t_data *data);
void			link_point(t_game *game);
t_color_f		gradient(t_color color1, t_color color2, float y1, float y2);
int				c_color(t_color color1, t_color_f gradient, int x, int x1);

// ------ Rotate ------
void			rotate_plan_x(t_coordonnee_3d *tab_3d, unsigned int len,
					double rotation);
void			rotate_plan_y(t_coordonnee_3d *tab_3d, unsigned int len,
					double rotation);
void			rotate_plan_z(t_coordonnee_3d *tab_3d, unsigned int len,
					double rotation);
void			rotate_plan_isometrique(t_coordonnee_3d *tab_3d,
					t_coordonnee_3d *tab_const, unsigned int len);
void			rotate_plan_cabinet(t_coordonnee_3d *tab_3d,
					t_coordonnee_3d *tab_const, unsigned int len);

// ----- Keycode -----
void			ft_hook(t_game *game);
int				key(int keycode, t_game *mlx);
int				key_release(int keycode, t_game *game);
int				mouse(int keycode, int x, int y, t_game *game);
int				ft_translate(t_game *game, t_coordonnee_3d origine);
int				ft_move(t_game *mlx);
int				ft_close(t_game *mlx);
int				ft_zoom(t_game *game, float zoom);
int				ft_rotate(t_game *game, float angle, char plan);
int				ft_projection_iso(t_game *game);
int				ft_projection_cabinet(t_game *game);

// ------ Parsing -----
unsigned int	ft_fdflen(char *str, t_game *game);
void			ft_fill_tab(char *str, t_game *game);
void			test_error(char *path, t_game *game);
int				parsing(int argc, char **argv, t_game *game);

// ------ Zoom ------
float			center_plan(t_coordonnee_3d *tab, unsigned int len,
					t_coordonnee_3d *origine);
void			apply_zoom(t_game *game, float zoom);

// ------ Translation ------
void			translation(t_game *game, t_coordonnee_3d origine);
void			translation_repere(t_game *game, t_coordonnee_3d origine);

// ------ Not use -------
void			add_z(t_coordonnee_3d *tab, unsigned int len);

// ------ Affichage -------
void			ft_print(t_coordonnee_3d *tab, unsigned int len);
void			ft_printf_point_of_tab(t_coordonnee_3d *tab_3d,
					unsigned int len, t_data *data);

#endif