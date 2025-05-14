/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:45:20 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/13 12:45:24 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *tg)
{
	int	x;
	int	y;

	x = tg->player_cur.x;
	y = tg->player_cur.y;
	if (is_wall(tg, x + 1, y))
		return ;
	else if (is_exit (tg, x + 1, y) && to_collect(tg) != 0)
		return ;
	else if (is_exit (tg, x + 1, y) && to_collect(tg) == 0)
		end_success(tg);
	else 
	{
		update_coin_count(tg, x + 1, y);
		tg->player_cur.x += 1;
		tg->path_count += 1;
		mlx_put_image_to_window(tg->mlx, tg->win, tg->floor.img_ptr, \
						x * TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(tg->mlx, tg->win, tg->player_right.img_ptr, \
						(x + 1) * TILE_SIZE, y * TILE_SIZE);
	}
}

void	move_left(t_game *tg)
{
	int	x;
	int	y;

	x = tg->player_cur.x;
	y = tg->player_cur.y;
	if (is_wall(tg, x - 1, y))
		return ;
	else if (is_exit (tg, x - 1, y) && to_collect(tg) != 0)
		return ;
	else if (is_exit (tg, x - 1, y) && to_collect(tg) == 0)
		end_success(tg);
	else 
	{
		update_coin_count(tg, x - 1, y);
		tg->player_cur.x -= 1;
		tg->path_count += 1;
		mlx_put_image_to_window(tg->mlx, tg->win, tg->floor.img_ptr, \
						x * TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(tg->mlx, tg->win, tg->player_left.img_ptr, \
						(x - 1) * TILE_SIZE, y * TILE_SIZE);
	}
}

void	move_up(t_game *tg)
{
	int	x;
	int	y;

	x = tg->player_cur.x;
	y = tg->player_cur.y;
	if (is_wall(tg, x, y - 1))
		return ;
	else if (is_exit (tg, x, y - 1) && to_collect(tg) != 0)
		return ;
	else if (is_exit (tg, x, y - 1) && to_collect(tg) == 0)
		end_success(tg);
	else 
	{
		update_coin_count(tg, x, y - 1);
		tg->player_cur.y -= 1;
		tg->path_count += 1;
		mlx_put_image_to_window(tg->mlx, tg->win, tg->floor.img_ptr, \
						x * TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(tg->mlx, tg->win, tg->player_up.img_ptr, \
						(x) * TILE_SIZE, (y - 1) * TILE_SIZE);
	}
}

void	move_down(t_game *tg)
{
	int	x;
	int	y;

	x = tg->player_cur.x;
	y = tg->player_cur.y;
	if (is_wall(tg, x, y + 1))
		return ;
	else if (is_exit (tg, x, y + 1) && to_collect(tg) != 0)
		return ;
	else if (is_exit (tg, x, y + 1) && to_collect(tg) == 0)
		end_success(tg);
	else 
	{
		update_coin_count(tg, x, y + 1);
		tg->player_cur.y += 1;
		tg->path_count += 1;
		mlx_put_image_to_window(tg->mlx, tg->win, tg->floor.img_ptr, \
						x * TILE_SIZE, y * TILE_SIZE);
		mlx_put_image_to_window(tg->mlx, tg->win, tg->player_down.img_ptr, \
						(x) * TILE_SIZE, (y + 1) * TILE_SIZE);
	}
}
