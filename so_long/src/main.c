/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:38:52 by agaroux          #+#    #+#             */
/*   Updated: 2025/03/19 11:20:29 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "../includes/so_long.h"

void free_double_ptr(t_data *data)
{
	int i;

	i = 0;
	while(data->map->map[i])
		i++;
	while(i >= 0)
		free(data->map->map[i--]);
	free(data->map->map);
	free(data->pic);

}
int ft_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
    printf("Looser\n");
	free_double_ptr(data);
	exit(EXIT_SUCCESS);
}
int ft_render_next_frame(t_data *data)
{
	//put_background(data);
	create_map(data);
	mlx_hook(data->win, 17, 1L << 2, ft_exit, data);
	mlx_key_hook(data->win, ft_key_hook, data);
	return (0);
}

void handle_error(t_data *data, char *str, int num)
{
	if (num)
		free_double_ptr(data);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
void init(t_data *data, t_map *map)
{
	int		img_w;
	int		img_h;
	t_pic	*img;
	t_xy player;

	data->map = map;
	img = malloc(sizeof(t_pic));
	if (!img)
		return;
	data->pic = img;
	data->pic->pic_up = mlx_xpm_file_to_image(data->mlx, "src/files/player/player.xpm", &img_w, &img_h);
	if (!data->pic->pic_up)
		handle_error(data, "Player file not found\n", 1);
	data->pic->background = mlx_xpm_file_to_image(data->mlx, "src/files/tiles/ground32.xpm", &img_w, &img_h);
	if (!data->pic->background)
		handle_error(data, "Background file not found\n", 1);
	data->counter = 0;
	data->collected = 0;
	player = position_item(data->map->map, 'P');
	data->player.x = player.x;
	data->player.y = player.y;
	printf("Your position is x:%d y:%d", data->player.x, data->player.y);

}
void window_size(char **tab, t_data *data)
{
	int count;

	count = 0;
	while (tab[count])
		count++;
	data->size.x = ((ft_strlen(tab[0]) - 1) * WIN_W);
	data->size.y = (count * WIN_H);
}

int	main(int argc, char **argv)
{
	t_data data;
	t_map map;

	if (argc != 2)
		return(printf("Not the right # of Inputs!\n"), 0);
	if (!read_ber_file(argv[1], &map))
		return (printf("Map Error!\n"), 0);
	window_size(map.map, &data);
	//print_map(map.map);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (printf("Initialization Error\n"),0);
	init(&data, &map);
	printf("WIN_X: %d, WIN_Y: %d", data.size.x, data.size.y);
	data.win = mlx_new_window(data.mlx, data.size.x, data.size.y, "Wassup");
	ft_render_next_frame(&data);
	printf("Position player main: %d %d\n", data.player.x, data.player.y);
	mlx_loop(data.mlx);
	return (printf("Map valid!\n"), 1);
}
