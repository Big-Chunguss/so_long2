#include "../includes/so_long.h"

int render_next_frame(t_data *data)
{
    printf("ok\n");
    static int a = 0;
    int color;
    if (a % 3 == 0)
        color = 255;
    if (a % 3 == 1)
        color = 65280;
    if (a % 3 == 2)
        color = 16711680;
    printf("color: %d\n", color);
    for (int y = 0; y < WIN_W; y++)
        {
            for (int x = 0; x < WIN_H; x++)
                my_mlx_pixel_put(data, x, y, color);
        }
    printf("ok2\n");
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
    a++;
    return (0);
}

void draw_circle(void *mlx_ptr, void *win_ptr, int center_x, int center_y, int radius, int color)
{
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y)
    {
        mlx_pixel_put(mlx_ptr, win_ptr, center_x + x, center_y + y, color);
        mlx_pixel_put(mlx_ptr, win_ptr, center_x + y, center_y + x, color);
        mlx_pixel_put(mlx_ptr, win_ptr, center_x - y, center_y + x, color);
        mlx_pixel_put(mlx_ptr, win_ptr, center_x - x, center_y + y, color);
        mlx_pixel_put(mlx_ptr, win_ptr, center_x - x, center_y - y, color);
        mlx_pixel_put(mlx_ptr, win_ptr, center_x - y, center_y - x, color);
        mlx_pixel_put(mlx_ptr, win_ptr, center_x + y, center_y - x, color);
        mlx_pixel_put(mlx_ptr, win_ptr, center_x + x, center_y - y, color);
        if (err <= 0)
        {
            y += 1;
            err += 2*y + 1;
        }
        if (err > 0)
        {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}
