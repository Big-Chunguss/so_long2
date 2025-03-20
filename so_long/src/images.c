/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:02:51 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/19 16:35:54 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

/*void replicate_texture(t_data data)
{
int bpp, line_length, endian;
char *texture_data = mlx_get_data_addr(data.floor.texture, &bpp, &line_length, &endian);

for (int y = 0; y < data.img_height; y++) {
for (int x = 0; x < data.img_width; x++) {
// Calculate the corresponding pixel in the texture
int tex_x = x % data.floor.width;
int tex_y = y % data.floor.height;

// Get the color from the texture
int color = *(int *)(texture_data + (tex_y * line_length + tex_x * (bpp / 8)));

// Write the color to the image
*(int *)(data.floor.addr + (y * data.floor.width * (bpp / 8) + x * (bpp / 8))) = color;
}
}
}*/
