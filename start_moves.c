/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:03:41 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/11 16:07:10 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_events(int keycode, t_game *data)
{
	if (keycode == 119 || keycode == 65362)
	{	
		data->player->y--;
		move_w(data);
	}
	else if (keycode == 115 || keycode == 65364)
	{
		data->player->y += 1;
		move_s(data);
	}
	else if (keycode == 100 || keycode == 65363)
	{
		data->player->x += 1;
		move_d(data);
	}
	else if (keycode == 97 || keycode == 65361)
	{
		data->player->x -= 1;
		move_a(data);
	}
}

static int	keypress(int keycode, t_game *data)
{
	if (keycode == 65307 || keycode == 113)
		exit_game(data);
	else if (!data->endgame)
		game_events(keycode, data);
}

void start_moves(t_game *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, keypress, data);
    mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, exit_game, data);
    mlx_hook(data->mlx_win, FocusIn, FocusChangeMask, creat_map, data);
	mlx_loop(data->mlx);
}
