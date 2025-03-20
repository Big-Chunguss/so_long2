/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:41:35 by agaroux           #+#    #+#             */
/*   Updated: 2025/03/20 17:06:31 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	int_valid_path(char **map)
{
	t_xy	player;
	int		**visited;

	printf("ok");
	// t_xy exit;
	player = position_item(map, 'P');
	// exit = position_item(map, 'E');
	visited = map_visited(map);
	if (!valid_path(map, player.x, player.y, visited))
		return (printf("Path not valid!\n"), 0);
	else
		return (1);
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

int	valid_position(char **map, int x, int y)
{
	if (map[x][y] != '1')
		return (1);
	return (0);
}
int	valid_path(char **map, int pX, int pY, int **visited)
{
	int	nextX;
	int	nextY;
	int	dx[] = {-1, 1, 0, 0};
	int	dy[] = {0, 0, -1, 1};
	
	printf("x: %d y: %d\n", pX, pY);
	if (map[pX][pY] == 'E')
		return (printf("Valid path!\n"), 1);
	if (!valid_position(map, pX, pY) || visited[pX][pY])
		return (0);
	visited[pX][pY] = 1;
	for (int i = 0; i < 4; i++)
	{
		nextX = pX + dx[i];
		nextY = pY + dy[i];
		if (valid_path(map, nextX, nextY, visited))
			return (printf("Yes it works!"), 1);
	}
	return (printf("No path!\n"), 0);
}
int	**map_visited(char **map)
{
	int	**visited_map;
    int x, y, row_count;
	
    row_count = 0;
	while (map[row_count])
		row_count++;
	visited_map = malloc(sizeof(int *) * row_count);
	if (!visited_map)
		return (NULL);
	for (x = 0; x < row_count; x++)
	{
		int col_count = ft_strlen(map[x]); // or another appropriate length
		visited_map[x] = malloc(sizeof(int) * col_count);
		if (!visited_map[x])
		{
			// free previously allocated rows
			for (int k = 0; k < x; k++)
				free(visited_map[k]);
			free(visited_map);
			return (NULL);
		}
		for (y = 0; y < col_count; y++)
			visited_map[x][y] = 0;
	}
	return (visited_map);
}
