#include "../includes/so_long.h"

int on_destroy(int keysym, t_data *img)
{
    printf("%d\n", keysym);
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(img->mlx,img->win);
        mlx_destroy_display(img->mlx);
        free(img->mlx);
        exit(0);
    }
	return (0);
}

int on_keypress(int keysym, t_data *img)
{
    int move_distance = 5; // Adjust this value to change movement speed

	printf("%x\n", keysym);
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(img->mlx, img->win);
        exit(0);
    }
    else if (keysym == XK_1)
    {
        mlx_destroy_window(img->mlx,img->win);
        img->win = mlx_new_window(img->mlx, 360, 540, "Hello world!v2");
    }
    if (keysym == 65362 || keysym == 119) // Up arrow or 'w'
        img->circle_y -= move_distance;
    else if (keysym == 65364 || keysym == 115) // Down arrow or 's'
        img->circle_y += move_distance;
    else if (keysym == 65361 || keysym == 97) // Left arrow or 'a'
        img->circle_x -= move_distance;
    else if (keysym == 65363 || keysym == 100) // Right arrow or 'd'
        img->circle_x += move_distance;
    mlx_clear_window(img->mlx, img->win);
    draw_circle(img->mlx, img->win, img->circle_x, img->circle_y, img->radius, img->circle_color);
    printf("%x\n", img->circle_x);
        return (0);
}

void key_press_handler(int keysym, t_key_state *param) {
    t_key_state *state = (t_key_state *)param;
    state->keysym = keysym;
    state->press_time = clock();
    state->is_pressed = 1;
}

void key_release_handler(int keysym, t_key_state *param) {
    t_key_state *state = (t_key_state *)param;
    if (state->keysym == keysym) {
        state->is_pressed = 0;
    }
}

void check_key_hold(t_key_state *param) {
    t_key_state *state = (t_key_state *)param;
    if (state->is_pressed) {
        clock_t current_time = clock();
        double elapsed = (double)(current_time - state->press_time) / CLOCKS_PER_SEC;
        if (elapsed >= 2.0) { // 2 seconds threshold
            printf("Key %d held for 2 seconds\n", state->keysym);
            state->is_pressed = 0; // Reset state
        }
    }
}
