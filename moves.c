/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:20:37 by felipe            #+#    #+#             */
/*   Updated: 2024/03/18 10:39:48 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_w(t_game *game)
{
	if ((game->map[game->player->y][game->player->x] == 'E'
		&& game->n_colects == 0)
		|| (game->map[game->player->y][game->player->x] == 'K'))
	{
		game->map[game->player->y + 1][game->player->x] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
	}
	else if (game->map[game->player->y][game->player->x] == '1'
		|| game->map[game->player->y][game->player->x] == 'E')
		game->player->y += 1;
	else
	{
		if (game->map[game->player->y][game->player->x] == 'C')
			game->n_colects -= 1;
		game->map[game->player->y][game->player->x] = 'P';
		game->map[game->player->y + 1][game->player->x] = '0';
		game->moves++;
		generate_map(game);
	}
}

void	player_s(t_game *game)
{
	if ((game->map[game->player->y][game->player->x] == 'E'
		&& game->n_colects == 0)
		|| (game->map[game->player->y][game->player->x] == 'K'))
	{
		game->map[game->player->y - 1][game->player->x] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
	}
	else if (game->map[game->player->y][game->player->x] == '1'
		|| game->map[game->player->y][game->player->x] == 'E')
		game->player->y -= 1;
	else
	{
		if (game->map[game->player->y][game->player->x] == 'C')
			game->n_colects -= 1;
		game->map[game->player->y][game->player->x] = 'P';
		game->map[game->player->y - 1][game->player->x] = '0';
		game->moves++;
		generate_map(game);
	}
}

void	player_d(t_game *game)
{
	if ((game->map[game->player->y][game->player->x] == 'E'
		&& game->n_colects == 0)
		|| (game->map[game->player->y][game->player->x] == 'K'))
	{
		game->map[game->player->y][game->player->x - 1] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
	}
	else if (game->map[game->player->y][game->player->x] == '1'
		|| game->map[game->player->y][game->player->x] == 'E')
		game->player->x -= 1;
	else
	{
		if (game->map[game->player->y][game->player->x] == 'C')
			game->n_colects -= 1;
		game->map[game->player->y][game->player->x] = 'P';
		game->map[game->player->y][game->player->x - 1] = '0';
		game->moves++;
		generate_map(game);
	}
}

void	player_a(t_game *game)
{
	if ((game->map[game->player->y][game->player->x] == 'E'
		&& game->n_colects == 0)
		|| (game->map[game->player->y][game->player->x] == 'K'))
	{
		game->map[game->player->y][game->player->x + 1] = '0';
		game->moves++;
		game->endgame = 1;
		exit_game(game);
	}
	else if (game->map[game->player->y][game->player->x] == '1'
		|| game->map[game->player->y][game->player->x] == 'E')
		game->player->x += 1;
	else
	{
		if (game->map[game->player->y][game->player->x] == 'C')
			game->n_colects -= 1;
		game->map[game->player->y][game->player->x] = 'P';
		game->map[game->player->y][game->player->x + 1] = '0';
		game->moves++;
		generate_map(game);
	}
}
