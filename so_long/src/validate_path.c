/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:41:35 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/14 16:20:00 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	int_valid_path(char **map, t_map *data)
{
	t_xy	player;
	int		**visited;
	int		**visited2;

	player = position_item(map, 'P');
	visited = map_visited(map);
	visited2 = map_visited(map);
	if (!valid_path(map, player.y, player.x, visited))
	{
		free_visited(visited, data);
        free_visited(visited2, data);
		return (printf("Path exit not valid!\n"), 0);
	}
	if (!valid_path_c(map, player.y, player.x, visited2))
	{
		free_visited(visited, data);
        free_visited(visited2, data);
		return (printf("Path collectibles not valid!\n"), 0);
	}
	
	return (free_visited(visited, data), free_visited(visited2, data), 1);
}


void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("[%d] %s", i, map[i]);
		i++;
	}
	printf("\n");
}

int	valid_path(char **map, int pX, int pY, int **visited)
{
	int	next_x;
	int	next_y;
	int	dx[4];
	int	dy[4];
	int	i;

	initialize_directions(dx, dy);
	printf("Player exit = x: %d y: %d\n", pX, pY);
	if (map[pX][pY] == 'E')
		return (printf("Valid path player!\n"), 1);
	if (!valid_position(map, pX, pY) || visited[pX][pY])
		return (0);
	visited[pX][pY] = 1;
	i = 0;
	while (i < 4)
	{
		next_x = pX + dx[i];
		next_y = pY + dy[i];
		if (valid_path(map, next_x, next_y, visited))
			return (printf("Yes it works c!"), 1);
		i++;
	}
	return (printf("No path exit!\n"), 0);
}

int	valid_path_c(char **map, int pX, int pY, int **visited)
{
	int	next_x;
	int	next_y;
	int	dx[4];
	int	dy[4];
	int	i;

	initialize_directions(dx, dy);
	printf("Player collectibles = x: %d y: %d\n", pX, pY);
	if (map[pX][pY] == 'C')
		return (printf("Valid path collectibles!\n"), 1);
	if (!valid_position(map, pX, pY) || visited[pX][pY])
		return (0);
	visited[pX][pY] = 1;
	i = 0;
	while (i < 4)
	{
		next_x = pX + dx[i];
		next_y = pY + dy[i];
		if (valid_path_c(map, next_x, next_y, visited))
			return (printf("Yes it works c!"), 1);
		i++;
	}
	return (printf("No path collectible!\n"), 0);
}
