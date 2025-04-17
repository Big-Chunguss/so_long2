/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:43:00 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/17 14:57:24 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WIN_H 32
# define WIN_W 32
# define CENTER_X 500
# define CENTER_Y 400
# define RADIUS 100
# define UPKEY 126
# define LEFTKEY 123
# define DOWNKEY 125
# define RIGHTKEY 124
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/ftprintf/ft_printf.h"
# include "../lib/mlx/mlx.h"
# include "../lib/mlx/mlx_int.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct s_coordinates
{
	int		x;
	int		y;
}			t_xy;

typedef struct s_key_state
{
	int		keysym;
	clock_t	press_time;
	int		is_pressed;
}			t_key_state;

typedef struct s_map
{
	char	**map;
	void	*object;
	t_xy	coordinates;
	int		collect;
	int		row;
}			t_map;

typedef struct s_texture
{
	void	*texture;
	void	*img;
	char	*addr;
	int		height;
	int		width;
}			t_texture;

typedef struct s_pic
{
	void	*pic_up;
	void	*pic_left;
	void	*pic_right;
	void	*pic_down;
	void	*background;
}			t_pic;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_xy	size;
	t_xy	player;
	t_xy	w_size;
	int		counter;
	int		collected;
	t_map	*map;
	t_map	*map_flood;
	t_pic	*pic;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

void		free_double_ptr(t_data *data);
int			ft_exit(t_data *data);
int			ft_render_next_frame(t_data *data);
void		handle_error(t_data *data, char *str, int num);
void		init(t_data *data, t_map *map);
int			main(int argc, char **argv);
int			ft_key_hook(int keysym, t_data *data);
void		put_object(t_data *data, char *path, int x, int y);
void		create_map(t_data *data);
void		window_size(char **tab, t_data *data);
int			rectangle_map(char **map, t_data *data);
int			duplicate_map(char **map, t_map *data);
int			validate_map(char **map, t_data *data);
int			valid_cases(char **map);
void		initalize(int *a, int *b, int *c, int *d);
void		ft_move(t_data *data, char pos, int dir);
void		winner(t_data *data);
int			read_ber_file(const char *filename, t_data *data);
t_xy		position_item(char **map, char c);
int			free_tab_on_error(char **tab, int count);
int			read_lines(int fd, char ***tab, t_map *map);
int			check_filename(char *str);
int			int_valid_path(char **map, t_data *data);
void		print_map(char **map);
int			valid_position(char **map, int x, int y);
int			valid_path(char **map, int pX, int pY, int **visited);
int			valid_path_c(char **map, int pX, int pY, int **visited);
int			**allocate_visited_map(int row_count);
int			allocate_visited_row(int **visited_map, char **map, int x);
int			**map_visited(char **map);
void		initialize_directions(int *dx, int *dy);
void		free_visited(int **visited, t_map *data);
void		free_tab(char **tab);
char		**copy_tab(char **tab);
void		fill(t_data *data, char target, int col, int row);
int			flood_fill(char **tab, t_data *data, t_xy begin);
int			check_c(char **tab);
t_xy		limit_tab(char **tab);

#endif
