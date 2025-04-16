/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ber_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:09:59 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/16 12:10:44 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../lib/get_next_line/get_next_line.h"

t_xy	position_item(char **map, char c)
{
	t_xy	res;
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				res.x = j;
				res.y = i;
				return (res);
			}
			j++;
		}
		i++;
	}
	res.x = -1;
	res.y = -1;
	return (res);
}

int	free_tab_on_error(char **tab, int count)
{
	while (count--)
		free(tab[count]);
	free(tab);
	return (0);
}

int	read_lines(int fd, char ***tab, t_map *map)
{
	char	*line;
	char	**tmp;
	int		count;

	count = 0;
	*tab = NULL;
	line = get_next_line(fd);
	if (!line)
		return (printf("Empty file!\n"), 0);
	while (line)
	{
		tmp = realloc(*tab, sizeof(char *) * (count + 2));
		if (!tmp)
			return (free_tab_on_error(*tab, count));
		*tab = tmp;
		(*tab)[count++] = line;
		line = get_next_line(fd);
	}
	if (*tab)
		(*tab)[count] = NULL;
	map->row = count;
	return (1);
}

int	check_filename(char *str)
{
	char	*new_str;

	new_str = ft_strrchr(str, '.');
	return (ft_strncmp(".ber", new_str, 5));
}

int	read_ber_file(const char *filename, t_data *data)
{
	int		fd;
	char	**tab;

	if (check_filename((char *)filename))
		return (free(data), 0);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (printf("Error with the map path!\n"), 0);
	if (!read_lines(fd, &tab, data->map))
		return (close(fd), 0);
	close(fd);
	data->map->map = tab;
	if (!validate_map(tab, data))
	{
		free_tab_on_error(tab, data->map->row);
		free(data->map);
		data->map = NULL;
		free(data);
		return (0);
	}
	return (1);
}
