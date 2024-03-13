/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:27:17 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/13 13:55:02 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(t_game *data)
{
	data->player = malloc(sizeof(t_player));
	data->img_height = 50;
	data->img_width = 50;
	data->exit = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm", &data->img_width, &data->img_height);
	data->enemy = mlx_xpm_file_to_image(data->mlx, "./textures/enemy.xpm", &data->img_width, &data->img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm", &data->img_width, &data->img_height);
	data->player->img_player = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm", &data->img_width, &data->img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &data->img_width, &data->img_height);
	data->colect = mlx_xpm_file_to_image(data->mlx, "./textures/colect.xpm", &data->img_width, &data->img_height);
}

static void	img_put(t_game *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img, x * 50, y * 50);
}

static void	player(t_game *data, void *img, int x, int y)
{
	data->player->x = x;
	data->player->y = y;
	img_put(data, img, x, y);	
}

char	**fill_map(char *path)
{
	int		fd;
	char	*line;
	char	*holder;
	char	*holder_map;
	char	**map;

	fd = open(path, O_RDONLY);
	holder_map = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		holder = holder_map;
		holder_map = ft_strjoin(holder, line);
		free(line);
	}
	map = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
	return (map);
}

int		creat_map(t_game *data)
{
	int		i;
	int		x;
	
	i = 0;
	while (data->map[i])
	{
		x = 0;
		while (data->map[i][x] != '\0')
		{
			if (data->map[i][x] == '0')
				img_put(data, data->floor, x, i);
			else if(data->map[i][x] == '1')
				img_put(data, data->wall, x, i);
			else if (data->map[i][x] ==	'C')
				img_put(data, data->colect, x, i);
			else if (data->map[i][x] == 'P')
				player(data, data->player->img_player, x, i);
			else if (data->map[i][x] == 'K')
				img_put(data, data->enemy, x, i);
			else if (data->map[i][x] == 'E')
				img_put(data, data->exit, x, i);
			x++;	
		}
		i++;
	}
	return (0);
}
