
#include "../includes/so_long.h"

int	key_hook(int keycode)
{
	printf("Hello from key_hook! : %d\n", keycode);
	return (0);
}

int	mouse_hook(int keycode)
{
	printf("Hello from mouse_hook! : %d\n", keycode);
	return (0);
}

int mouse_move(int x, int y, t_data *data)
{
	data->cursor_x = x;
	data->cursor_y = y;
    mlx_mouse_get_pos(data->mlx, data->win, &data->cursor_x, &data->cursor_y);
	mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->img, data->cursor_x, data->cursor_y);
	printf("Mouse position: x = %d, y = %d\n", data->cursor_x, data->cursor_x);
    return (0);
}