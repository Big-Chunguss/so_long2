/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:03:40 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/19 16:35:09 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <../includes/so_long.h>

/*void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

unsigned int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(unsigned int *)(unsigned char [4]){b, g, r, t});
}


unsigned int add_shade(double shade, unsigned int color)
{
    unsigned char components[4];
    for(int i = 0; i < 4; i++)
    {
        components[i] = (color >> (8*i)) & 0xFF;
        components[i] *= (1 - shade);
    }
    int i = 0;
    while (i < 4)
        printf("%d\n", components[i++]);
    return (create_trgb(components[3], components[2], components[1], components[0]));
}

unsigned int get_opposite(unsigned int color)
{
    unsigned char components[4];
    for(int i = 0; i < 4; i++)
    {
        components[i] = 255 - ((color >> (8*i)) & 0xFF);
    }
    int i = 0;
    while (i < 4)
        printf("%d\n", components[i++]);
    return (create_trgb(components[3], components[2], components[1], components[0]));
}*/