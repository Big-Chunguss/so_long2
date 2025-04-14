/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:39:56 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/14 14:56:42 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_hook(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
		ft_exit(data);
	else if (keysym == 119 || keysym == XK_Up)
		ft_move(data, 'y', UP);
	else if (keysym == 115 || keysym == XK_Down)
		ft_move(data, 'y', DOWN);
	else if (keysym == 97 || keysym == XK_Left)
		ft_move(data, 'x', LEFT);
	else if (keysym == 100 || keysym == XK_Right)
		ft_move(data, 'x', RIGHT);
	if (data->map->map[data->player.y][data->player.x] == 'E')
		winner(data);
	return (0);
}

void	put_object(t_data *data, char *path, int x, int y)
{
	int	img_w;
	int	img_h;

	data->map->object = mlx_xpm_file_to_image(data->mlx, path, &img_h, &img_w);
	if (!data->map->object)
		handle_error(data, "File object not found", 1);
	mlx_put_image_to_window(data->mlx, data->win, data->map->object, (x
			* img_h), (y * img_w));
	mlx_destroy_image(data->mlx, data->map->object);
}

void	create_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->map[y])
	{
		x = 0;
		while (data->map->map[y][x])
		{
			printf("%c y:%d x:%d\n", data->map->map[y][x], y, x);
			if (data->map->map[y][x] == 'P')
				put_object(data, "src/files/player/player.xpm", x, y);
			else if (data->map->map[y][x] == '0')
				put_object(data, "src/files/tiles/ground32.xpm", x, y);
			else if (data->map->map[y][x] == 'E')
				put_object(data, "src/files/tiles/exit32.xpm", x, y);
			else if (data->map->map[y][x] == '1')
				put_object(data, "src/files/tiles/lava32.xpm", x, y);
			else if (data->map->map[y][x] == 'C')
				put_object(data, "src/files/tiles/diamond32.xpm", x, y);
			x++;
		}
		y++;
	}
}

void	window_size(char **tab, t_data *data)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	data->size.x = ((ft_strlen(tab[0]) - 1) * WIN_W);
	data->size.y = (count * WIN_H);
}

int	ft_render_next_frame(t_data *data)
{
	create_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}
