/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:38:52 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 12:06:49 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../lib/mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

void	free_double_ptr(t_data *data)
{
	int	i;

	if (data->map && data->map->map)
	{
		i = 0;
		while (data->map->map[i])
			free(data->map->map[i++]);
		free(data->map->map);
	}
	if (data->pic)
	{
		if (data->pic->pic_up)
			mlx_destroy_image(data->mlx, data->pic->pic_up);
		if (data->pic->background)
			mlx_destroy_image(data->mlx, data->pic->background);
		free(data->pic);
	}
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	data->mlx = NULL;
	free(data->map);
	free(data->map_flood);
	free(data);
}

int	ft_exit(t_data *data)
{
	free_double_ptr(data);
	printf("Looser\n");
	exit(EXIT_SUCCESS);
}

void	handle_error(t_data *data, char *str, int num)
{
	if (num)
		free_double_ptr(data);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	init(t_data *data, t_map *map)
{
	int		img_w;
	int		img_h;
	t_pic	*img;

	data->map = map;
	img = malloc(sizeof(t_pic));
	if (!img)
		return ;
	data->pic = img;
	data->pic->pic_up = mlx_xpm_file_to_image(data->mlx,
			"src/files/player/player.xpm", &img_w, &img_h);
	if (!data->pic->pic_up)
		handle_error(data, "Player file not found\n", 1);
	data->pic->background = mlx_xpm_file_to_image(data->mlx,
			"src/files/tiles/ground32.xpm", &img_w, &img_h);
	if (!data->pic->background)
		handle_error(data, "Background file not found\n", 1);
	data->counter = 0;
	data->collected = 0;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (printf("Memory allocation failed!\n"), 0);
	if (argc != 2)
		return (printf("Not the right # of Inputs!\n"), 0);
	data->map = NULL;
	data->map_flood = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->pic = NULL;
	if (!read_ber_file(argv[1], data))
		return (printf("Map Error!\n"), 0);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (printf("Initialization Error\n"), 0);
	init(data, data->map);
	window_size(data->map->map, data);
	data->win = mlx_new_window(data->mlx, data->size.x, data->size.y, "Wassup");
	ft_render_next_frame(data);
	mlx_loop(data->mlx);
	return (1);
}
