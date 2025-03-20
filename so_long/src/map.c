/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:39:56 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/20 15:16:22 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void put_object(t_data *data, char *path)
{
    int img_w;
    int img_h;

    data->map->object = mlx_xpm_file_to_image(data->mlx, path, &img_w, &img_h);
    if (!data->map->object)
        handle_error(data, "File object not found", 1);
    mlx_put_image_to_window(data->mlx, data->win, data->map->object, (data->map->coordinates.x * img_w), (data->map->coordinates.y *img_h));
    free(data->map->object);
}
void create_map(t_data *data)
{
    int x, y;
    printf("ok2");
    x = 0;
    while (data->map->map[x])
    {
        y = 0;
        while (data->map->map[x][y])
        {
            printf("ok3");
            if (data->map->map[x][y] == 'P')
                put_object(data, "src/files/player/player000.xpm");
            else if (data->map->map[x][y] == '0')
            put_object(data, "src/files/tiles/ground.xpm");
            else if (data->map->map[x][y] == 'E')
            put_object(data, "src/files/tiles/exit.xpm");
            else if (data->map->map[x][y] == '1')
            put_object(data, "src/files/tiles/lava.xpm");
            else if (data->map->map[x][y] == 'C')
            put_object(data, "src/files/tiles/diamond.xpm");
            y++;
        }
        x++;
    }
    printf("ok");
}
