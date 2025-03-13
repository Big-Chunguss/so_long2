/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:43:00 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/13 18:30:57 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define WIN_H 1080
#define WIN_W 720
#define CENTER_X 500
#define CENTER_Y 400
#define RADIUS 100

#include "../lib/mlx/mlx_int.h"
#include "../lib/mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include "time.h"

typedef struct	s_key_state {
    int keysym;
    clock_t press_time;
    int is_pressed;
}				t_key_state;

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bpp;
    int     line_len;
    int     endian;
    int     hue;
	int		circle_x;
	int 	circle_y;
	int		radius;
	int		circle_color;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		cursor_x;
	int		cursor_y;
} t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

//cc main.c -I -L.mlx -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

// colors
unsigned int add_shade(double shade, unsigned int color);
unsigned int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b);
unsigned int get_opposite(unsigned int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// events
int on_destroy(int keysym, t_data *img);
int on_keypress(int keysym, t_data *img);
void key_press_handler(int keysym, t_key_state *param);
void key_release_handler(int keysym, t_key_state *param);
void check_key_hold(t_key_state *param);

//hooks
int	key_hook(int keycode);
int	mouse_hook(int keycode);
int mouse_move(int x, int y, t_data *data);

//loops
int render_next_frame(t_data *data);
void draw_circle(void *mlx_ptr, void *win_ptr, int center_x, int center_y, int radius, int color);

#endif

