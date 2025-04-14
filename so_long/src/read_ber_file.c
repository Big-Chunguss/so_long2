/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ber_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:09:59 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/14 16:46:50 by agaroux          ###   ########.fr       */
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

	*tab = NULL;
	count = 0;
	line = get_next_line(fd);
	if (!line)
		return (printf("Empty file!\n"),0);
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
int check_filename(char *str)
{
	char *new_str;
	
	new_str = ft_strrchr(str, '.');
	printf("%s\n", new_str);
	return(ft_strncmp(".ber", new_str, 5));
}
int	read_ber_file(const char *filename, t_map *map)
{
	int		fd;
	char	**tab;

	if (check_filename((char *)filename))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (printf("Error with the map path!\n"), 0);
	if (!read_lines(fd, &tab, map))
		return (close(fd), 0);
	close(fd);
	if (!validate_map(tab, map))
		return (free_tab_on_error(tab, map->row));
	map->map = tab;
	return (1);
}
