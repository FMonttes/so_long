/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:27:09 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/11 16:03:16 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *data)
{
	if ((data->map[data->player->y][data->player->x] == 'E'
	 && data->n_colects == 0) || 
	 (data->map[data->player->y][data->player->x] == 'K'))
	{
		data->map[data->player->y + 1][data->player->x] = '0';
		data->moves++;
		data->endgame = 1;
		exit_game(data);
	}
	else if (data->map[data->player->y][data->player->x] == '1' ||
		data->map[data->player->y][data->player->x] == 'E')
		data->player->y += 1;
	else
	{
		if (data->map[data->player->y][data->player->x] == 'C')
			data->n_colects -= 1;
		data->map[data->player->y][data->player->x] = 'P';
		data->map[data->player->y + 1][data->player->x] = '0';
		data->moves++;
		creat_map(data);
	}
}

void	move_s(t_game *data)
{
	if ((data->map[data->player->y][data->player->x] == 'E' 
	&& data->n_colects == 0) ||
	(data->map[data->player->y][data->player->x] == 'K'))
	{
		data->map[data->player->y - 1][data->player->x] = '0';
		data->moves++;
		data->endgame = 1;
		exit_game(data);
	}
	else if (data->map[data->player->y][data->player->x] == '1' ||
		data->map[data->player->y][data->player->x] == 'E')
		data->player->y -= 1;
	else
	{
		if (data->map[data->player->y][data->player->x] == 'C')
			data->n_colects -= 1;
		data->map[data->player->y][data->player->x] = 'P';
		data->map[data->player->y - 1][data->player->x] = '0';
		data->moves++;
		creat_map(data);
	}
}

void	move_d(t_game *data)
{
	if ((data->map[data->player->y][data->player->x] == 'E' 
	&& data->n_colects == 0) ||
	(data->map[data->player->y][data->player->x] == 'K'))
	{
		data->map[data->player->y][data->player->x - 1] = '0';
		data->moves++;
		data->endgame = 1;
		exit_game(data);
	}
	else if (data->map[data->player->y][data->player->x] == '1' ||
		data->map[data->player->y][data->player->x] == 'E')
		data->player->x -= 1;
	else
	{
		if (data->map[data->player->y][data->player->x] == 'C')
			data->n_colects -= 1;
		data->map[data->player->y][data->player->x] = 'P';
		data->map[data->player->y][data->player->x - 1] = '0';
		data->moves++;
		creat_map(data);
	}
}

void	move_a(t_game *data)
{
	if ((data->map[data->player->y][data->player->x] == 'E' 
	&& data->n_colects == 0) ||
	(data->map[data->player->y][data->player->x] == 'K'))
	{
		data->map[data->player->y][data->player->x + 1] = '0';
		data->moves++;
		data->endgame = 1;
		exit_game(data);
	}
	else if (data->map[data->player->y][data->player->x] == '1' ||
		data->map[data->player->y][data->player->x] == 'E')
		data->player->x += 1;
	else
	{
		if (data->map[data->player->y][data->player->x] == 'C')
			data->n_colects -= 1;
		data->map[data->player->y][data->player->x] = 'P';
		data->map[data->player->y][data->player->x + 1] = '0';
		data->moves++;
		creat_map(data);
	}
}