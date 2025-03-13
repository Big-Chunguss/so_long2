/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:38:52 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/13 18:34:58 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "../includes/so_long.h"

void init_var(t_data *img)
{
	img->circle_color = 123234;
	img->circle_x = CENTER_X;
	img->circle_y = CENTER_Y;
	img->radius = RADIUS;
	img->relative_path = "./src/files/pic2.xpm";
}

int	main(void)
{
	t_data	img;	

	
	init_var(&img);
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, WIN_H, WIN_W, "Hello world!");
	printf("ok\n");
	img.img = mlx_xpm_file_to_image(img.mlx, img.relative_path, &img.img_width, &img.img_height);
	if (!img.img)
{
    printf("Error: Failed to load image from %s\n", img.relative_path);
    exit(1);
}
	printf("ok2\n");
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	printf("ok3\n");
	draw_circle(img.mlx, img.win, img.circle_x, img.circle_y, img.radius, img.circle_color);
	printf("ok4\n");
	//mlx_hook(img.win, DestroyNotify, StructureNotifyMask, &on_destroy, &img);
	mlx_hook(img.win, 2, 1L<<0, on_keypress, &img);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_mouse_hook(img.win, mouse_hook, &img);
	mlx_hook(img.win, 6, 1L<<6, mouse_move, &img);
	printf("ok5\n");
	//mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_loop(img.mlx);
}
