/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:43:00 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/20 17:54:07 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define WIN_H 32
#define WIN_W 32
#define CENTER_X 500
#define CENTER_Y 400
#define RADIUS 100

#include "../lib/mlx/mlx_int.h"
#include "../lib/mlx/mlx.h"
#include "../lib/get_next_line/get_next_line.h"
#include "../lib/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct s_coordinates {
    int x;
    int y;
} t_xy;

typedef struct	s_key_state {
    int keysym;
    clock_t press_time;
    int is_pressed;
}				t_key_state;

typedef struct s_map
{
	char	**map;
	void	*object;
	t_xy    coordinates;
	int		collect;
}				t_map;

typedef struct s_texture {
    void    *texture;
    void    *img;
    char    *addr;
    int     height;
    int     width;
} t_texture;

typedef struct s_pic
{
	void	*pic_up;
	void	*pic_left;
	void	*pic_right;
	void	*pic_down;
	void	*background;
}				t_pic;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_xy    size;
	t_xy    player;
	int		counter;
	int		collected;
	t_map	*map;
	t_pic	*pic;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

//cc main.c -I -L.mlx -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

//main
void free_double_ptr(t_data *data);
int ft_exit(t_data *data);
int ft_render_next_frame(t_data *data);
void handle_error(t_data *data, char *str, int num);
void init(t_data *data, t_map *map);
void window_size(char **tab, t_data *data);
int	main(int argc, char **argv);

//map
void put_object(t_data *data, char *path, int x, int y);
void create_map(t_data *data);

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

//images
void replicate_texture(t_data data);

//read_ber_file
int rectangle_map(char **map);
int duplicate_map(char **map);
t_xy    position_item(char **map, char c);
int validate_map(char **map);
int read_ber_file(const char *filename, t_map *map);

//validate_path
int int_valid_path(char **map);
void print_map(char **map);
int valid_position(char **map, int x, int y);
int valid_path(char **map, int pX, int pY, int **visited);
int **map_visited(char **map);


#endif

