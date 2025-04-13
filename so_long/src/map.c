/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:39:56 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/30 12:47:34 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int ft_key_hook(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
        ft_exit(data);
    else if (keysym == XK_z || keysym == XK_Up)
        ft_move(data, 'y', UP);
    else if (keysym == XK_s || keysym == XK_Down)
        ft_move(data, 'y', DOWN);
    else if (keysym == XK_q || keysym == XK_Left)
        ft_move(data, 'x', LEFT);
    else if (keysym == XK_d || keysym == XK_Right)
        ft_move(data, 'x', RIGHT);
    if (data->map->map[data->player.y][data->player.x] == 'E')
        {
            printf("Ok32");
            winner(data);
        }
    return (0);
}
/*void put_background(t_data *data)
{
    int y;
    int x;
    
    y = 0;
    if (!data->pic->background)
        printf("No background\n");
    while (y < data->size.y)
    {
        x = 0;
        while (x < data->size.x)
        {
            mlx_put_image_to_window(data->mlx, data->win, data->pic->background, x, y);
            x += WIN_W;
        }
        y += WIN_H;
    }
}*/
void put_object(t_data *data, char *path, int x, int y)
{
    int img_w;
    int img_h;

    data->map->object = mlx_xpm_file_to_image(data->mlx, path, &img_h, &img_w);
    //printf("image_width: %d, image_height: %d\n", img_w, img_h);
    if (!data->map->object)
        handle_error(data, "File object not found", 1);
    mlx_put_image_to_window(data->mlx, data->win, data->map->object, (x * img_h), (y *img_w));
    //printf("%c x:%d y:%d\n", data->map->map[x][y], x, y);
    free(data->map->object);
}
void create_map(t_data *data)
{
    int x, y;

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
    printf("ok");
}
