/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:27:17 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/06 14:38:10 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	images(t_game *data, int img_width, int img_height)
{
	data->enemy = mlx_xpm_file_to_image(data->mlx, "enemy.xpm", &img_width, &img_height);
	data->floor = mlx_xpm_file_to_image(data->mlx, "floor.xpm", &img_width, &img_height);
	data->player = mlx_xpm_file_to_image(data->mlx, "player.xpm", &img_width, &img_height);
	data->wall = mlx_xpm_file_to_image(data->mlx, "wall.xpm", &img_width, &img_height);
	data->colect = mlx_xpm_file_to_image(data->mlx, "colect.xpm", &img_width, &img_height);
}

char	**fill_map(t_game *data)
{
	int		fd;
	char	*line;
	char	*holder;
	char	*holder_map;

	fd = open("./maps/map1.ber", O_RDONLY);
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
	data->map = ft_split(holder_map, '\n');
	free(holder_map);
	close(fd);
	return (data->map);
}

void	creat_map(t_game *data)
{
	int		i;
	int		x;
	int		img_width;
	int		img_height;

	data->map = fill_map(data);
	img_width = 50;
	img_height = 50;
	images(data, img_width, img_height);
	i = 0;
	while (data->map[i])
	{
		x = 0;
		while (data->map[i][x])
		{
			if (data->map[i][x] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor, x * 50, i * 50);
			else if(data->map[i][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, x * 50, i * 50);
			else if (data->map[i][x] ==	'C')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->colect, x * 50, i * 50);
			else if (data->map[i][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->player, x * 50, i * 50);
			else if (data->map[i][x] == 'K')
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->enemy, x * 50, i * 50);
			x++;	
		}
		i++;
	}
}
