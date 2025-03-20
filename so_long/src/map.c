/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:39:56 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/20 18:21:49 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void put_object(t_data *data, char *path, int x, int y)
{
    int img_w;
    int img_h;

    data->map->object = mlx_xpm_file_to_image(data->mlx, path, &img_w, &img_h);
    printf("image_width: %d, image_height: %d\n", img_w, img_h);
    if (!data->map->object)
        handle_error(data, "File object not found", 1);
    mlx_put_image_to_window(data->mlx, data->win, data->map->object, (y * img_h), (x *img_w));
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
            printf("ok3: %c\n", data->map->map[x][y]);
            if (data->map->map[x][y] == 'P')
                put_object(data, "src/files/player/player.xpm", x, y);
            else if (data->map->map[x][y] == '0')
                put_object(data, "src/files/tiles/ground32.xpm", x, y);
            else if (data->map->map[x][y] == 'E')
                put_object(data, "src/files/tiles/exit32.xpm", x, y);
            else if (data->map->map[x][y] == '1')
                put_object(data, "src/files/tiles/lava32.xpm", x, y);
            else if (data->map->map[x][y] == 'C')
                put_object(data, "src/files/tiles/diamond32.xpm", x, y);
            y++;
        }
        x++;
    }
    printf("ok");
}
