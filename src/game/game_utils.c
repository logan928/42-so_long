/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:45:57 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/13 12:46:01 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keyrelease(int keycode, void *param)
{
	t_game	*tg;
	int		start_count;

	tg = (t_game *)param;
	start_count = tg->path_count;
	if (keycode == 100)
		move_right(tg);
	if (keycode == 97)
		move_left(tg);
	if (keycode == 119)
		move_up(tg);
	if (keycode == 115)
		move_down(tg);
	if (keycode == 65307)
	{
		end_game(tg, 3);
		free(tg->mlx);
		exit(EXIT_SUCCESS);
	}
	if (keycode == 100 || keycode == 97 || keycode == 119 || keycode == 115)
	{
		if (tg->path_count != start_count)
			ft_printf("Moves: %d\n", tg->path_count);
	}
	return (0);
}

int	handle_destroy(void *param)
{
	t_game	*tg;

	tg = (t_game *)param;
	end_game(tg, 3);
	free(tg->mlx);
	exit(EXIT_SUCCESS);
}

void	end_success(t_game *tg)
{
	end_game(tg, 3);
	ft_printf("Congrats!! you ended the game in %d moves\n", ++(tg->path_count));
	free(tg->mlx);
	exit(EXIT_SUCCESS);
}

void	initialize_game(t_game *tg, char ***map, t_map_size mz, \
	t_map_details *md)
{
	tg->mlx = NULL;
	tg->win = NULL;
	tg->width = 0;
	tg->height = 0;
	tg->path_count = 0;
	tg->game_state = started;
	tg->map = *map;
	tg->mz = mz;
	tg->player_cur.x = md->p_x;
	tg->player_cur.y = md->p_y;
	tg->player_next.x = 0;
	tg->player_next.y = 0;
	tg->start_coins = md->collects;
	tg->collected_coins = 0;
}

void	end_game(t_game *tg, int game_state)
{
	if (game_state == 0)
	{
		free_map(tg->map, tg->mz.rows);
		return ;
	}
	else if (game_state == 1)
		mlx_destroy_display(tg->mlx);
	else if (game_state == 2)
		mlx_destroy_window(tg->mlx, tg->win);
	else if (game_state == 3)
		free_images(tg->mlx, tg, 8);
	end_game(tg, --game_state);
}
