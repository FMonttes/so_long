/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:09:50 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/13 13:55:05 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    start_stack(t_game *data)
{
    data->n_exit = 0;
    data->n_player = 0;
    data->n_colects = 0;
}

void	start_game(t_game *data)
{
	int		i; 
	
	i = check_map(data);
	data->endgame = 0;
	data->moves = 0;
	data->mlx = mlx_init();
	if (i == 1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	get_size(data);
	if (is_retangular(data) == 1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	if (wall_check(data) == 1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	if (char_check(data) == 1)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	data->mlx_win = mlx_new_window(data->mlx, data->width, data->height, "so_long");
	images(data);
	creat_map(data);
}

