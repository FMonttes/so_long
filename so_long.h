/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmontes <fmontes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:57:36 by fmontes           #+#    #+#             */
/*   Updated: 2024/03/13 12:42:40 by fmontes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/libftprintf.h"
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_player
{
	void	*img_player;
	int		x;
	int		y;
}	t_player;

typedef struct	s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*floor;
	void	*enemy;
	void	*wall;
	void	*colect;
	void	*exit;
	t_player	*player;
	int		width;
	int		img_width;
	int		img_height;
	int		height;
	int		moves;
	int		n_player;
	int		n_exit;
	int		n_colects;
	int		endgame;
	char	**map;
}				t_game;

int		map_size(t_game *data);
void	start_game(t_game *data);
void	malloc_map(t_game *data);
int    check_map(t_game *data);
char	**fill_map(char *path);
char	**ft_split(char const *s, char c);
int		creat_map(t_game *data);
void	start_map(t_game *data);
void    get_size(t_game *data);
void	images(t_game *data, int img_width, int img_height);
void    free_map(char **map);
void	move_w(t_game *data);
void	move_s(t_game *data);
void	move_d(t_game *data);
void	move_a(t_game *data);
void    start_stack(t_game *data);
int     char_check(t_game *data);
int     is_retangular(t_game *data);
int     wall_check(t_game *data);
int		exit_game(t_game *data);
void	start_moves(t_game *data);

#endif
