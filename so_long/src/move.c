/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:49:32 by antoine           #+#    #+#             */
/*   Updated: 2025/03/31 14:03:36 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    winner(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    printf("Congrats you won!\n");
    free_double_ptr(data);
}
void    ft_collect(t_data *data)
{
    data->collected++;
    data->map->map[data->player.y][data->player.x] = '0';
    mlx_put_image_to_window(data->mlx, data->win, data->pic->background, (data->player.x * WIN_H), (data->player.y * WIN_W));
}

void	ft_move(t_data *data, char pos, int dir)
{
    mlx_put_image_to_window(data->mlx, data->win, data->pic->background, (data->player.x * WIN_W), (data->player.y * WIN_W));
    if (pos == 'y' && data->map->map[data->player.y + dir][data->player.x] != '1' && (data->map->map[data->player.y + dir][data->player.x] != 'E' || data->collected == data->map->collect))
        data->player.y = data->player.y + dir;
    else if (pos == 'x' && data->map->map[data->player.y][data->player.x + dir] != '1' && (data->map->map[data->player.y][data->player.x + dir] != 'E' || data->collected == data->map->collect))
        data->player.x = data->player.x + dir;
    else if (pos == 'y' && data->map->map[data->player.y + dir][data->player.x] == 'E' && data->collected != data->map->collect)
        printf("Collect all collectibles before leaving\n");
    else if (pos == 'x' && data->map->map[data->player.y][data->player.x + dir] == 'E' && data->collected != data->map->collect)
        printf("Collect all collectibles before leaving\n");
    if (data->map->map[data->player.y][data->player.x] == 'C')
        {
            printf("okA");
            ft_collect(data);
        }
    mlx_put_image_to_window(data->mlx, data->win, data->pic->pic_up, (data->player.x * WIN_W), (data->player.y * WIN_W));
    mlx_do_sync(data->mlx);
    printf(" %c \n", data->map->map[data->player.y - 1][data->player.x]);
    printf("%c%c%c\n", data->map->map[data->player.y][data->player.x - 1], data->map->map[data->player.y][data->player.x], data->map->map[data->player.y][data->player.x + 1]);
    printf(" %c \n", data->map->map[data->player.y + 1][data->player.x]);
    printf("You moved %d times. Your position is x:%d y:%d. Items collected: %d, Goal: %d\n", ++data->counter, data->player.x, data->player.y, data->collected, data->map->collect);
}
