/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felipe <felipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:21:28 by felipe            #+#    #+#             */
/*   Updated: 2024/03/15 16:21:39 by felipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_events(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->player->y -= 1;
		player_w(game);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		game->player->y += 1;
		player_s(game);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player->x += 1;
		player_d(game);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->player->x -= 1;
		player_a(game);
	}
}

static int	keypress(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == KEY_Q)
		exit_game(game);
	else if (!game->endgame)
	{
		game_events(keycode, game);
		ft_printf("Moves: %d\n", game->moves);
	}
	return (0);
}

void	start_moves(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, keypress, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, exit_game, game);
	mlx_hook(game->win, FocusIn, FocusChangeMask, generate_map, game);
	mlx_loop(game->mlx);
}