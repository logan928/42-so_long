/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:16:48 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/12 14:16:51 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image_to_win(t_game *tg, char element, t_point mp)
{
	if (element == '0')
		mlx_put_image_to_window(tg->mlx, tg->win, tg->floor.img_ptr, \
			mp.x * TILE_SIZE, mp.y * TILE_SIZE);
	else if (element == '1')
		mlx_put_image_to_window(tg->mlx, tg->win, tg->wall.img_ptr, \
			mp.x * TILE_SIZE, mp.y * TILE_SIZE);
	else if (element == 'C')
		mlx_put_image_to_window(tg->mlx, tg->win, tg->coin.img_ptr, \
			mp.x * TILE_SIZE, mp.y * TILE_SIZE);
	else if (element == 'E')
		mlx_put_image_to_window(tg->mlx, tg->win, tg->exit.img_ptr, \
			mp.x * TILE_SIZE, mp.y * TILE_SIZE);
	else if (element == 'P')
		mlx_put_image_to_window(tg->mlx, tg->win, tg->player_down.img_ptr, \
			mp.x * TILE_SIZE, mp.y * TILE_SIZE);
}

void	render_tiles(t_game *tg)
{
	int		i;
	int		j;
	t_point	mp;

	i = 0;
	while (i < tg->mz.rows)
	{
		j = 0;
		while (j < tg-> mz.cols)
		{
			mp.x = j;
			mp.y = i;
			if (ft_toupper((tg->map)[i][j]) == 'C' \
				|| ft_toupper((tg->map)[i][j]) == 'E' \
				|| ft_toupper((tg->map)[i][j]) == 'P' \
				|| ft_toupper((tg->map)[i][j]) == '0' )
				put_image_to_win(tg, '0', mp);
			else if (ft_toupper((tg->map)[i][j]) == '1')
				put_image_to_win(tg, '1', mp);
			j++;
		}
		i++;
	}
}

void	render_sprites(t_game *tg)
{
	int		i;
	int		j;
	t_point	mp;

	mp.x = 0;
	mp.y = 0;
	i = 0;
	while (i < tg->mz.rows)
	{
		j = 0;
		while (j < tg-> mz.cols)
		{
			mp.x = j;
			mp.y = i;
			if (ft_toupper((tg->map)[i][j]) == 'C')
				put_image_to_win(tg, 'C', mp);
			else if (ft_toupper((tg->map)[i][j]) == 'E')
				put_image_to_win(tg, 'E', mp);
			else if (ft_toupper((tg->map)[i][j]) == 'P')
				put_image_to_win(tg, 'P', mp);
			j++;
		}
		i++;
	}
}

void	render_game_area(t_game *tg)
{
	render_tiles (tg);
	render_sprites(tg);
	tg->game_state = rendered;
}
