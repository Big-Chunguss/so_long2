/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:49:32 by antoine           #+#    #+#             */
/*   Updated: 2025/04/16 12:02:43 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	winner(t_data *data)
{
	printf("Congrats\n");
	free_double_ptr(data);
	exit(EXIT_SUCCESS);
}

void	ft_collect(t_data *data)
{
	data->collected++;
	data->map->map[data->player.y][data->player.x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->pic->background,
		(data->player.x * WIN_H), (data->player.y * WIN_W));
}

int	is_wall_or_invalid_exit(t_data *data, int new_x, int new_y)
{
	if (data->map->map[new_y][new_x] == '1')
		return (1);
	if (data->map->map[new_y][new_x] == 'E'
		&& data->collected != data->map->collect)
	{
		printf("Collect all collectibles before leaving\n");
		return (1);
	}
	return (0);
}

void	ft_move(t_data *data, char pos, int dir)
{
	int	new_x;
	int	new_y;

	new_x = data->player.x;
	new_y = data->player.y;
	if (pos == 'x')
		new_x += dir;
	else if (pos == 'y')
		new_y += dir;
	if (is_wall_or_invalid_exit(data, new_x, new_y))
		return ;
	mlx_put_image_to_window(data->mlx, data->win, data->pic->background,
		(data->player.x * WIN_W), (data->player.y * WIN_W));
	data->player.x = new_x;
	data->player.y = new_y;
	printf("You moved %d times\n", ++data->counter);
	if (data->map->map[data->player.y][data->player.x] == 'C')
		ft_collect(data);
	mlx_put_image_to_window(data->mlx, data->win, data->pic->pic_up,
		(data->player.x * WIN_W), (data->player.y * WIN_W));
	mlx_do_sync(data->mlx);
}
