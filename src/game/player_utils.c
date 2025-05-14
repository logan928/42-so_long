/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uwettasi <uwettasi@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:54:20 by uwettasi          #+#    #+#             */
/*   Updated: 2025/05/14 11:54:25 by uwettasi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(t_game *tg, int x, int y)
{
	return ((tg->map)[y][x] == '1');
}

int	is_coin(t_game *tg, int x, int y)
{
	return (ft_toupper((tg->map)[y][x]) == 'C');
}

int	is_exit(t_game *tg, int x, int y)
{
	return (ft_toupper((tg->map)[y][x]) == 'E');
}

int	to_collect(t_game *tg)
{
	return (tg->start_coins - tg->collected_coins);
}

void	update_coin_count(t_game *tg, int x, int y)
{
	if (is_coin (tg, x, y))
	{
		tg->collected_coins += 1;
		tg->map[y][x] = '0';
	}
}
