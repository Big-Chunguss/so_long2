/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 15:04:45 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/14 16:22:10 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*void destroy_images(t_data *data)
{
    mlx_destroy_image(data->mlx, data->pic->)
}*/

void free_visited(int **visited, t_map *data)
{
    int i;

    i = 0;
    while (i < data->row)
        free(visited[i++]);
    free(visited);
}

int	valid_position(char **map, int x, int y)
{
	if (map[x][y] != '1')
		return (1);
	return (0);
}

void	initialize_directions(int *dx, int *dy)
{
	dx[0] = -1;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = -1;
	dy[3] = 1;
}

